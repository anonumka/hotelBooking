/*!
 * \file
 * \brief Файл реализация класса Auth
 */
#include "auth.hpp"
#include "ui_auth.h"
#include "recordingusers.hpp"
#include <QMessageBox>

Auth::Auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Auth)
{
    ui->setupUi(this);
    setFixedSize(400, 234);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::setUsers(std::vector<User> *vU)
{
    vUsers = vU;
}
void Auth::accept()
{
    QString surname = ui->lineEdit->text();
    QString series = ui->lineEdit_2->text(); int index = -1;

    for (size_t i = 0; i < vUsers->size(); i++)
        if ( (vUsers->at(i).getSeries() == series) && (vUsers->at(i).getSurname() == surname)) index = i;

    if (surname.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking!", "Line with surname is empty.");
        return;
    }
    else if (series.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking!", "Line with series is empty.");
        return;
    }
    else if (index == -1)
    {
        QMessageBox::critical(this, "Hotel Booking!", QString("User not finded.\nTry again."));
        ui->lineEdit_2->setText("");
        return;
    }

    for (size_t i = 0; i < vUsers->size(); i++)
        if ((*vUsers)[i].getSeries() == series) index = i;

    (*vUsers)[index].setSelect(true);
    return QDialog::accept();
}


void Auth::recordingUsersButton()
{
    User u;
    BookedRoom bkr;
    RecordingUsers reg;
    reg.setUser(&u);
    reg.setbkdRoom(&bkr);

    std::vector<QString> BusySeries;
    for (size_t i = 0; i < vUsers->size(); i++) {
        BusySeries.push_back(vUsers->at(i).getSeries());
    }

    reg.setBusySeriesUsers(BusySeries);
    reg.setWindowTitle("Hotel Booking");
    if (reg.exec() != RecordingUsers::Accepted)
    {
        return;
    }
    vUsers->push_back(u);
}

