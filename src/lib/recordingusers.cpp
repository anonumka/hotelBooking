/*!
 * \file
 * \brief Файл реализация класса RecordingUsers
 */
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
    setFixedSize(368, 237);

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

void RecordingUsers::setSurname(QString surname)
{
    ui->surnameEdit->setText(surname);
}

void RecordingUsers::setName(QString name)
{
    ui->nameEdit->setText(name);
}

void RecordingUsers::setPatronymic(QString patronymic)
{
    ui->patronymicEdit->setText(patronymic);
}

void RecordingUsers::setSeriesNumPassport(QString series)
{
    ui->seriesEdit->setText(series);
}

void RecordingUsers::setCity(QString city)
{
    ui->adressEdit->setText(city);
}

void RecordingUsers::setBusySeriesUsers(std::vector<QString> &BusySeries)
{
    vNums = BusySeries;
}

void RecordingUsers::setSeriesOtherUser(QString series)
{
    vNums.push_back(series);
}

void RecordingUsers::accept()
{
    QString surname = ui->surnameEdit->text();
    if (surname.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Поле с фамилией пустое.");
        return;
    }

    QString name = ui->nameEdit->text();
    if (name.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Поле с именем пустое.");
        return;
    }

    QString patronymic = ui->patronymicEdit->text();
    if (patronymic.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Поле отчество пустое.");
        return;
    }

    QString series = ui->seriesEdit->text(); bool ok;
    series.toInt(&ok);
    for (size_t i = 0; i < vNums.size(); i++) {
        if (vNums[i] == series)
        {
            QMessageBox::critical(this, config::applicationName, "Данная серия и номер паспорта уже есть в базе данных.");
            return;
        }
    }

    if (series.isEmpty())
    {
        QMessageBox::critical(this, config::applicationName, "Поле с серией и номером паспорта пустое.");
        return;
    }
    else if (!ok)
    {
        QMessageBox::critical(this, config::applicationName, "Поле с серией содержит буквы.");
        return;
    }
    else if(series.size() != 10)
    {
        QMessageBox::critical(this, config::applicationName, "Длина паспорта должна быть равной 10.");
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

