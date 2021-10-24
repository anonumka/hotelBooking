#include <QMessageBox>
#include <QIntValidator>

#include "recordingusers.hpp"
#include "ui_recordingusers.h"
#include "config.hpp"

RecordingUsers::RecordingUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordingUsers)
{
    ui->setupUi(this);
    setFixedSize(400, 282);

    ui->seriesEdit->setValidator(new QIntValidator);
}

RecordingUsers::~RecordingUsers()
{
    delete ui;
}

void RecordingUsers::setUser(User *u)
{
    user = u;
}

void RecordingUsers::setbkdRoom(BookedRoom *bkdr)
{
    bkd = bkdr;
}

void RecordingUsers::accept()
{
    QString surname = ui->surnameEdit->text();
    if (surname.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Line surname is empty");
        return;
    }

    QString name = ui->nameEdit->text();
    if (name.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Line name is empty");
        return;
    }

    QString patronymic = ui->patronymicEdit->text();
    if (patronymic.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Line patronymic is empty");
        return;
    }

    QString series = ui->seriesEdit->text(); bool ok;
    series.toInt(&ok);
    if (series.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Line series is empty");
        return;
    }
    else if (!ok)
    {
        QMessageBox::critical(this, config::applicationName, "Line doesn't have a digit");
        return;
    }

    QString adress = ui->adressEdit->text();
    if (adress.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Line adress is empty");
        return;
    }

    user->setSurname(surname);
    user->setName(name);
    user->setPatronymic(patronymic);
    user->setSeries(series);
    user->setAdress(adress);

    bkd->setSeries(series);

    return QDialog::accept();
}

