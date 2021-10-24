#include "recordingusers.hpp"
#include "ui_recordingusers.h"
#include <QMessageBox>

RecordingUsers::RecordingUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordingUsers)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

RecordingUsers::~RecordingUsers()
{
    delete ui;
}

void RecordingUsers::setUser(User *u)
{
    user = u;
}

void RecordingUsers::accept()
{
    QString surname = ui->surnameEdit->text();
    if (surname.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking", "Line surname is empty");
        return;
    }

    QString name = ui->nameEdit->text();
    if (name.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking", "Line name is empty");
        return;
    }

    QString patronymic = ui->patronymicEdit->text();
    if (patronymic.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking", "Line patronymic is empty");
        return;
    }

    QString series = ui->seriesEdit->text(); bool ok;
    series.toInt(&ok);
    if (series.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking", "Line series is empty");
        return;
    }
    else if (!ok)
    {
        QMessageBox::critical(this, "Hotel Booking", "Line doesn't have a digit");
        return;
    }

    QString adress = ui->adressEdit->text();
    if (adress.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking", "Line adress is empty");
        return;
    }

    user->setSurname(surname);
    user->setName(name);
    user->setPatronymic(patronymic);
    user->setSeries(series);
    user->setAdress(adress);

    return QDialog::accept();
}

