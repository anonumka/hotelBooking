#include "auth.hpp"
#include "ui_auth.h"
#include "recordingusers.hpp"
#include <QMessageBox>

auth::auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

auth::~auth()
{
    delete ui;
}

void auth::setUsers(std::vector<User> *vU)
{
    vUsers = vU;
}
void auth::accept()
{
    QString series = ui->lineEdit->text(); int index = -1;
    for (int i = 0; i < vUsers->size(); i++)
        if ((*vUsers)[i].getSeries() == series) index = i;

    if (series.isEmpty())
    {
        QMessageBox::critical(this, "Hotel Booking!", "Line with series is empty.");
        return;
    }
    else if (index == -1)
    {
        QMessageBox::critical(this, "Hotel Booking!", QString("User with %1 not finded.\nTry again.").arg(series));
        ui->lineEdit->setText("");
        return;
    }


    (*vUsers)[index].setSelect(true);
    return QDialog::accept();
}


void auth::on_pushButton_clicked()
{
    User u;
    RecordingUsers reg;
    reg.setUser(&u);
    reg.setWindowTitle("Hotel Booking");
    if (reg.exec() != RecordingUsers::Accepted) return;
    vUsers->push_back(u);
}

