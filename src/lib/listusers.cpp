#include <QMessageBox>
#include "listusers.hpp"
#include "ui_listusers.h"

ListUsers::ListUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListUsers)
{
    ui->setupUi(this);
    setFixedSize(404, 283);
    ui->countEdit->setValidator(new QIntValidator);
}

ListUsers::~ListUsers()
{
    delete ui;
}

void ListUsers::setUsers(std::vector<User> *vU)
{
    vUsers = vU;

    int size = vUsers->size();
    for (int i = 0; i < size; i++)
    {
        if ((*vUsers)[i].getSelect())
                role = (*vUsers)[i].getRole();
        QString text;
        text = (*vUsers)[i].getSurname();
        text = text + " " + (*vUsers)[i].getName()[0] + ".";
        text = text + " " + (*vUsers)[i].getPatronymic()[0] + ".";
        ui->comboBox->addItem(text);
    }
    ui->roleBox->setEnabled(role == 2);
}

void ListUsers::setBkdRooms(std::vector<BookedRoom> *bkdr)
{
    bkdRoom = bkdr;
}

void ListUsers::on_comboBox_activated(int index)
{
    if (index == 0)
    {
        ui->seriesEdit->setText(0);
        ui->countEdit->setText(0);
        ui->roleBox->setCurrentIndex(0);

        ui->settlingEdit->setDate(QDate::fromString("01.01.2000", "ddMMyyyy"));
        ui->releaseEdit->setDate(QDate::fromString("01.01.2000", "ddMMyyyy"));
        ui->roomEdit->setText(QString("%1").arg(0));
    }
    else
    {
        User u = (*vUsers)[index-1];
        int j = -1;
        for (size_t i = 0; i < bkdRoom->size(); i++)
        {
            if ((*bkdRoom)[i].getSeries() == u.getSeries())
                j = i;
        }

        ui->seriesEdit->setText(u.getSeries());
        ui->countEdit->setText(QString("%1").arg(u.getVisit()));
        ui->roleBox->setCurrentIndex(u.getRole());

        if (j != -1)
        {
            ui->settlingEdit->setDate((*bkdRoom)[j].getDateSettling());
            ui->releaseEdit->setDate((*bkdRoom)[j].getDateRelease());
            ui->roomEdit->setText(QString("%1").arg((*bkdRoom)[j].getRoom()));
        }
        else
        {
            ui->settlingEdit->setDate(QDate::fromString("01.01.2000", "ddMMyyyy"));
            ui->releaseEdit->setDate(QDate::fromString("01.01.2000", "ddMMyyyy"));
            ui->roomEdit->setText(QString("%1").arg(0));
        }
    }
}

void ListUsers::accept()
{
    QDate date_selling = ui->settlingEdit->date();
    QDate date_release = ui->releaseEdit->date();

    int visit = QString(ui->countEdit->text()).toInt();
    if (visit < 0)
    {
        QMessageBox::critical(this, "Hotel Booking", "Count visit can't be < 0.");
        return;
    }

    int index = ui->comboBox->currentIndex();
    (*bkdRoom)[index-1].setDateSettling(date_selling.day(), date_selling.month(),date_selling.year());
    (*bkdRoom)[index-1].setDateRelease(date_release.day(), date_release.month(),date_release.year());
    (*vUsers)[index-1].setVisit(visit);
    (*vUsers)[index-1].setRole(ui->roleBox->currentIndex());
    return QDialog::accept();
}

void ListUsers::on_resetBtn_clicked()
{
    if (QMessageBox::question(this, "Warning", "You sure to reset a data of user?"))
    {
        QDate date;
        date.setDate(2000, 1, 1);
        ui->settlingEdit->setDate(date);
        ui->releaseEdit->setDate(date);
        ui->countEdit->setText(QString("%1").arg(0));
        ui->roomEdit->setText(QString("%1").arg(0));
    }
}

