#include <QMessageBox>
#include "bookingroom.hpp"
#include "ui_bookingroom.h"

bookingRoom::bookingRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookingRoom)
{
    ui->setupUi(this);
    setFixedSize(400, 184);
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

void bookingRoom::setUser(User *user)
{
    u = user;
}

void bookingRoom::setBkdroom(std::vector<BookedRoom> *bkdr)
{
    bkdRoom = bkdr;

    ui->sellingEdit->setDate(QDate::currentDate());
    ui->releaseEdit->setDate(QDate::currentDate());
    ui->releaseEdit->setDate(ui->releaseEdit->date().addDays(1));
}

void bookingRoom::check_price()
{
    size_t count_days;
    size_t price = r->getPrice();
    size_t count_visit = 0;

    count_visit = (*u).getVisit();

    QDate first = ui->sellingEdit->date();
    QDate second = ui->releaseEdit->date();

    count_days = second.day() - first.day();
    if (first.month() != second.month())
        count_days += second.daysInMonth();

    if (count_visit >= 5) price *= 0.9;

    ui->priceEdit->setText(QString("%1").arg(count_days * price));
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

    int count_capacity = 0;

    for (size_t i = 0; i < bkdRoom->size(); i++)
        if ((*bkdRoom)[i].getRoom() == num)
        {
            count_capacity++;
            if (count_capacity == capacity)
                if (((*bkdRoom)[i].getDateSettling() <= date_selling) && (date_selling < (*bkdRoom)[i].getDateRelease()))
                {
                    QMessageBox::critical(this, "ERROR!", "This room not avaible in this day.\nChoise other day.");
                    return;
                }

        }

    r->setAvailable(++count_capacity < capacity);

    (*u).addVisit();

    size_t i = 0;
    for (i = 0; i < bkdRoom->size(); ++i)
    {
        if ((*u).getSeries() == (*bkdRoom)[i].getSeries())
            break;
    }

    (*bkdRoom)[i].setRoom(num);
    (*bkdRoom)[i].setDateSettling(date_selling.day(), date_selling.month(), date_selling.year());
    (*bkdRoom)[i].setDateRelease(date_release.day(), date_release.month(), date_release.year());

    return QDialog::accept();
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

