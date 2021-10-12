#include <QMessageBox>
#include "editroom.hpp"
#include "ui_editroom.h"


CreateRoom::CreateRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateRoom)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

CreateRoom::~CreateRoom()
{
    delete ui;
}

QString CreateRoom::comfortConvert(int comfort)
{
    if (comfort == 0)
        return "Default";
    else if (comfort == 1)
        return "Semiluxe";
    else
        return "Luxe";
}

void CreateRoom::setRoom(Room *room)
{
    r = room;

    ui->numEdit->setText(QString("%1").arg(r->getNum()));
    ui->capacityEdit->setText(QString("%1").arg(r->getCapacity()));
    ui->priceEdit->setText(QString("%1").arg(r->getPrice()));

    int comfort = r->getComfort();
    ui->comfortEdit->setText(comfortConvert(comfort));
}

void CreateRoom::setTitle(QString title)
{
    ui->label_8->setText(title);
}

void CreateRoom::accept()
{
    int num = QString(ui->numEdit->text()).toInt();
    int capacity = QString(ui->capacityEdit->text()).toInt();
    QString comfort = ui->comfortEdit->text();
    int price = QString(ui->priceEdit->text()).toInt();

    if (num <= 0)
    {
        QMessageBox::warning(this, "Hotel Booking", "Inccorect entered num\nNum can't be <= 0");
        return;
    }

    if (capacity <= 0 || capacity >= 10)
    {
        QMessageBox::warning(this, "Hotel Booking", "Inccorect entered capacity\nCapacity should be 1-9");
        return;
    }

    if (price <= 0)
    {
        QMessageBox::warning(this, "Hotel Booking", "Inccorect entered price\nPrice can't be be < 0");
        return;
    }


    if (comfort == "Default") r->setComfort(0);
    else if (comfort == "Semiluxe") r->setComfort(1);
    else if (comfort == "Luxe") r->setComfort(2);
    else
    {
        QMessageBox::warning(this, "Hotel Booking", "Inccorect entered textLine \"Comfort\"");
        return;
    }

    r->setNum(num);
    r->setCapacity(capacity);
    r->setPrice(price);

    return QDialog::accept();
}
