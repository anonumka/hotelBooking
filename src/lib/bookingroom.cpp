#include <QMessageBox>
#include "bookingroom.hpp"
#include "ui_bookingroom.h"

bookingRoom::bookingRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookingRoom)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->sellingEdit->setDate(QDate::currentDate());
    ui->releaseEdit->setDate(QDate::currentDate());
    ui->releaseEdit->setDate(ui->releaseEdit->date().addDays(1));
}

bookingRoom::~bookingRoom()
{
    delete ui;
}

void bookingRoom::setRoom(Room *room)
{
    r = room;
    ui->priceEdit->setText(QString("%1").arg(r->getPrice()));
}

void bookingRoom::check_price()
{
    int count_days;
    int price = r->getPrice();
    int count_visit = 0;
    if (ui->comboBox->currentIndex() != 0)
        count_visit = (*vUsers)[ui->comboBox->currentIndex()-1].getVisit();

    QDate first = ui->sellingEdit->date();
    QDate second = ui->releaseEdit->date();

    count_days = second.day() - first.day();
    if (first.month() != second.month())
        count_days += second.daysInMonth();

    if (count_visit >= 5) price *= 0.9;

    ui->priceEdit->setText(QString("%1").arg(count_days * price));
}

QString bookingRoom::addItemFunction(int index)
{
    QString text;
    text = (*vUsers)[index].getSurname();
    text = text + " " + (*vUsers)[index].getName()[0] + ".";
    text = text + " " + (*vUsers)[index].getPatronymic()[0] + ".";
    ui->comboBox->addItem(text);
    return text;
}

void bookingRoom::setUsers(std::vector<User> *vU, int index)
{
    vUsers = vU;
    if ((*vUsers)[index].getRole())
        for (int i = 0; i < vUsers->size(); i++) addItemFunction(i);
    else
        addItemFunction(index);
}
void bookingRoom::accept()
{
    QDate date_selling = ui->sellingEdit->date();
    QDate date_release = ui->releaseEdit->date();

    if (date_selling >= date_release)
    {
        QMessageBox::critical(this, "ERROR!", "Date Selling can't be later than Date Release.");
        return;
    }

    if ((date_selling < QDate::currentDate()) || (date_release < QDate::currentDate()))
    {
        QMessageBox::critical(this, "ERROR!", "Date Selling or Date Release can't be < current date.");
        return;
    }

    int num = r->getNum();
    int capacity = r->getCapacity();


    int ind = ui->comboBox->currentIndex();
    if (ind == 0) return bookingRoom::reject();
    int count_capacity = 0;

    for (int i = 0; i < vUsers->size(); i++)
        if ((*vUsers)[i].getRoom() == num)
        {
            count_capacity++;
            if (count_capacity == capacity)
                if (((*vUsers)[i].getDateSettling() <= date_selling) && (date_selling < (*vUsers)[i].getDateRelease()))
                {
                    QMessageBox::critical(this, "ERROR!", "This room not avaible in this day.\nChoise other day.");
                    return;
                }

        }

    r->setAvailable(++count_capacity < capacity);

    (*vUsers)[ind-1].setRoom(num);
    (*vUsers)[ind-1].addVisit();
    (*vUsers)[ind-1].setDateSettling(date_selling.day(), date_selling.month(), date_selling.year());
    (*vUsers)[ind-1].setDateRelease(date_release.day(), date_release.month(), date_release.year());

    return QDialog::accept();
}

void bookingRoom::on_comboBox_currentIndexChanged(int index)
{
    ui->sellingEdit->setEnabled(index != 0);
    ui->releaseEdit->setEnabled(index != 0);
}

void bookingRoom::on_sellingEdit_dateChanged(const QDate &date)
{
    ui->releaseEdit->setDate(ui->sellingEdit->date().addDays(1));

    check_price();
}


void bookingRoom::on_releaseEdit_dateChanged(const QDate &date)
{

    check_price();
}

