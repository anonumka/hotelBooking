#include <QMessageBox>
#include "listusers.hpp"
#include "ui_listusers.h"

ListUsers::ListUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListUsers)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
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
    ui->checkBox->setEnabled(role == 2);
}

void ListUsers::on_comboBox_activated(int index)
{
    if (index == 0) return;
    User u = (*vUsers)[index-1];
    ui->seriesEdit->setText(u.getSeries());
    ui->settlingEdit->setDate(u.getDateSettling());
    ui->releaseEdit->setDate(u.getDateRelease());
    ui->countEdit->setText(QString("%1").arg(u.getVisit()));
    ui->roomEdit->setText(QString("%1").arg(u.getRoom()));
    ui->checkBox->setChecked(u.getRole() == 1);
}

void ListUsers::accept()
{
    QDate date_selling = ui->settlingEdit->date();
    QDate date_release = ui->releaseEdit->date();

    if (date_selling >= date_release)
    {
        QMessageBox::critical(this, "Hotel Booking", "Date Selling can't be later than Date Release.");
        return;
    }

    if ((date_selling < QDate::currentDate()) || (date_release < QDate::currentDate()))
    {
        QMessageBox::critical(this, "Hotel Booking", "Date Selling or Date Release can't be < current date.");
        return;
    }

    int visit = QString(ui->countEdit->text()).toInt();
    if (visit <= 0)
    {
        QMessageBox::critical(this, "Hotel Booking", "Count visit can't be <= 0.");
        return;
    }

    int index = ui->comboBox->currentIndex();
    (*vUsers)[index-1].setDateSettling(date_selling.day(), date_selling.month(),date_selling.year());
    (*vUsers)[index-1].setDateRelease(date_release.day(), date_release.month(),date_release.year());
    (*vUsers)[index-1].setVisit(visit);
    (*vUsers)[index-1].setRole(ui->checkBox->isChecked());
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

