#include <QMessageBox>
#include <QIntValidator>

#include "config.hpp"
#include "editroom.hpp"
#include "ui_editroom.h"


EditRoom::EditRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRoom)
{
    ui->setupUi(this);
    setFixedSize(401, 243);

    ui->numEdit->setValidator(new QIntValidator);
    ui->capacityEdit->setValidator(new QIntValidator);
    ui->priceEdit->setValidator(new QIntValidator);
}

EditRoom::~EditRoom()
{
    delete ui;
}

QString EditRoom::comfortConvert(int comfort)
{
    if (comfort == 0)
        return "Default";
    else if (comfort == 1)
        return "Semiluxe";
    else
        return "Luxe";
}

void EditRoom::setRoom(Room *room)
{
    r = room;

    ui->numEdit->setText(QString("%1").arg(r->getNum()));
    ui->capacityEdit->setText(QString("%1").arg(r->getCapacity()));
    ui->priceEdit->setText(QString("%1").arg(r->getPrice()));

    int comfort = r->getComfort();
    ui->comfortEdit->setText(comfortConvert(comfort));
}

void EditRoom::setTitle(QString title)
{
    ui->label_8->setText(title);
}

void EditRoom::accept()
{
    int num = QString(ui->numEdit->text()).toInt();
    int capacity = QString(ui->capacityEdit->text()).toInt();
    QString comfort = ui->comfortEdit->text();
    int price = QString(ui->priceEdit->text()).toInt();

    if (num <= 0)
    {
        QMessageBox::warning(this, config::applicationName, "Inccorect entered num\nNum can't be <= 0");
        return;
    }

    if (capacity <= 0 || capacity >= 10)
    {
        QMessageBox::warning(this, config::applicationName, "Inccorect entered capacity\nCapacity should be 1-9");
        return;
    }

    if (price <= 0)
    {
        QMessageBox::warning(this, config::applicationName, "Inccorect entered price\nPrice can't be be < 0");
        return;
    }


    if (comfort == "Default") r->setComfort(0);
    else if (comfort == "Semiluxe") r->setComfort(1);
    else if (comfort == "Luxe") r->setComfort(2);
    else
    {
        QMessageBox::warning(this, config::applicationName, "Inccorect entered textLine \"Comfort\""
                                                            "\nUse 'Luxe', 'Semiuxe', 'Default'");
        return;
    }

    r->setNum(num);
    r->setCapacity(capacity);
    r->setPrice(price);

    return QDialog::accept();
}
