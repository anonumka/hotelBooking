#include <QFileDialog>
#include <QSaveFile>
#include <QDate>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>
#include <set>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "roomtable.hpp"
#include "bookingroom.hpp"
#include "ui_recordingusers.h"
#include "listusers.hpp"
#include "auth.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->hotelView->horizontalHeader()->setStretchLastSection(true);
    ui->hotelView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->hotelView->setSelectionMode(QAbstractItemView::SingleSelection);

    auto updateTimer = new QTimer;
    updateTimer->setInterval(10000);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedValues()));
    updateTimer->start(100);

    setvroom(new RoomTable);
    load_vrooms();
    load_vusers();

    index = authorisation();

}

void MainWindow::updateDisplayedValues()
{
    if (index == -1) exit();
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());

    for (int i = 0; i < vUsers.size(); i++)
    {
        if (vUsers[i].getDateRelease() < QDate::currentDate())
        {
            vUsers[i].setRoom(0);
            vUsers[i].setDateSettling(1, 1, 2000);
            vUsers[i].setDateRelease(1, 1, 2000);
        }
    }

    for (int i = 0; i < vRoom->size(); ++i)
    {
        Room r = (*vRoom)[i];
        int num_room = r.getNum();
        int count = 0;
        for (int j = 0; j < vUsers.size(); j++)
            if (num_room == vUsers[j].getRoom()) count++;
        r.setAvailable(count < r.getCapacity());
        vRoom->setRoom(i, r);
    }

}

MainWindow::~MainWindow()
{
    save_vrooms();
    save_vusers();
    delete ui;
}

void MainWindow::save_vrooms()
{
    QSettings settings("HotelBookingRooms");
    settings.beginWriteArray("rooms");
    int size = vRoom->size();
    for (int i = 0; i < size; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("num", (*vRoom)[i].getNum());
        settings.setValue("capacity", (*vRoom)[i].getCapacity());
        settings.setValue("comfort", (*vRoom)[i].getComfort());
        settings.setValue("price", (*vRoom)[i].getPrice());
        settings.setValue("available", (*vRoom)[i].getAvailable());
    }
    settings.endArray();
}

void MainWindow::load_vrooms()
{
    QSettings settings("HotelBookingRooms");
    int size = settings.beginReadArray("rooms");
    if (size == 0) return;
    for (int i = 0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Room r;
        r.setNum(settings.value("num").toInt());
        r.setCapacity(settings.value("capacity").toInt());
        r.setComfort(settings.value("comfort").toInt());
        r.setPrice(settings.value("price").toInt());
        r.setAvailable(settings.value("available").toBool());
        vRoom->push_back(r);
    }
    settings.endArray();
    setvroom(vRoom.release());
}

void MainWindow::save_vusers()
{
    QSettings settings("HotelBookingUsers");
    settings.beginWriteArray("users");
    int size = vUsers.size();
    for (int i = 0; i < size; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("surname", vUsers[i].getSurname());
        settings.setValue("name", vUsers[i].getName());
        settings.setValue("patronymic", vUsers[i].getPatronymic());
        settings.setValue("series", vUsers[i].getSeries());
        settings.setValue("adress", vUsers[i].getAdress());
        settings.setValue("settling", vUsers[i].getDateSettling());
        settings.setValue("release", vUsers[i].getDateRelease());
        settings.setValue("room", vUsers[i].getRoom());
        settings.setValue("visit", vUsers[i].getVisit());
        settings.setValue("role", vUsers[i].getRole());
    }
    settings.endArray();
}

void MainWindow::load_vusers()
{
    QSettings settings("HotelBookingUsers");
    int size = settings.beginReadArray("users");
    if (size == 0) return;
    vUsers.clear();
    for (int i = 0; i < size; i++)
    {
        settings.setArrayIndex(i);
        User u;
        u.setSurname(settings.value("surname").toString());
        u.setName(settings.value("name").toString());
        u.setPatronymic(settings.value("patronymic").toString());
        u.setSeries(settings.value("series").toString());
        u.setAdress(settings.value("adress").toString());
        u.setDateSettling(settings.value("settling").toDate().day(), settings.value("settling").toDate().month(), settings.value("settling").toDate().year());
        u.setDateRelease(settings.value("release").toDate().day(), settings.value("release").toDate().month(), settings.value("release").toDate().year());
        u.setRoom(settings.value("room").toInt());
        u.setVisit(settings.value("visit").toInt());
        u.setRole(settings.value("role").toInt());
        vUsers.push_back(u);
    }
}

int MainWindow::authorisation()
{
    auth au;
    au.setUsers(&vUsers);
    au.setWindowTitle("Hotel Booking");
    int i = 0;
    if (au.exec() != auth::Accepted) return -1;
    for (i = 0; i < vUsers.size(); i++)
        if (vUsers[i].getSelect()) break;

    if (i == vUsers.size()) return -1;

    int role = vUsers[i].getRole();

    ui->actionAddRoom->setEnabled(role);
    ui->actionEditRoom->setEnabled(role);
    ui->actionListUsers->setEnabled(role);

    ui->actionExportRooms->setEnabled(role == 2);
    ui->actionExportUsers->setEnabled(role == 2);
    ui->actionImportRooms->setEnabled(role == 2);
    ui->actionImportUsers->setEnabled(role == 2);
    ui->actionSave->setEnabled(role == 2);
    ui->actionSaveUsers->setEnabled(role == 2);
    ui->actionOpen->setEnabled(role == 2);
    ui->actionOpenUsers->setEnabled(role == 2);

    return i;
}

void MainWindow::save_users()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "", "*.bin");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (int i = 0; i < vUsers.size(); i++) ost << vUsers[i];
    outf.commit();
}

void MainWindow::load_users()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open bin", "", "*.bin");
    QFile inf(fileName);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    vUsers.clear();
    while (!ist.atEnd())
    {
        User u;
        ist >> u;
        vUsers.push_back(u);
    }
}

void MainWindow::setvroom(RoomTable *vRooms)
{
    vRoom.reset(vRooms);
    // Связываем новый объект записной книжки с таблицей заметок в главном окне
    ui->hotelView->setModel(vRoom.get());

}

void MainWindow::addRoom(const Room &r)
{
    vRoom->push_back(r);
}

void MainWindow::create_room()
{
    Room r;
    CreateRoom createroom;
    createroom.setRoom(&r);
    createroom.setTitle("Hotel Booking");
    createroom.setWindowTitle("Room editor: ");
    if (createroom.exec() != CreateRoom::Accepted) return;
    addRoom(r);
}

void MainWindow::edit_room()
{
    if (!ui->hotelView->selectionModel()->hasSelection()) return;
    std::set<int> rows;
    {
        QModelIndexList idc = ui->hotelView->selectionModel()->selectedRows();
        (&idc)->last();

        for (const auto &i : idc) rows.insert(i.row());
    }
    for (auto it = rows.rbegin(); it != rows.rend(); ++it)
    {
        Room r = (*vRoom)[*it];
        CreateRoom createroom;
        createroom.setRoom(&r);
        createroom.setTitle("Hotel Booking");
        createroom.setWindowTitle("Room editor: ");
        if (createroom.exec() != CreateRoom::Accepted) return;
        vRoom->setRoom(*it, r);
    }

}

void MainWindow::list_user()
{
    ListUsers lu;
    lu.setUsers(&vUsers);
    lu.setWindowTitle("List Users");
    if (lu.exec() != ListUsers::Accepted) return;
}

void MainWindow::booking_room(const QModelIndex &idx)
{
    Room r = (*vRoom)[idx.row()];
    bookingRoom br;
    br.setRoom(&r);
    br.setUsers(&vUsers, index);
    br.setWindowTitle("Booking room");
    if (br.exec() != bookingRoom::Accepted) return;
    vRoom->setRoom(idx.row(), r);
}

void MainWindow::saveRoomsTable()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Rooms As"), "", "*.bin");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    ost << *vRoom;
    outf.commit();
}

void MainWindow::openRoomsTable()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Rooms", "", "*.bin");
    QFile inf(fileName);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    std::unique_ptr<RoomTable> rt(new RoomTable);
    ist >> *rt;
    setvroom(rt.release());
}

void MainWindow::saveUsers()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Users As"), "", "*.bin");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (int i = 0; i < vUsers.size(); i++) ost << vUsers[i];
    outf.commit();
}

void MainWindow::openUsers()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Users", "", "*.bin");
    QFile inf(fileName);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    vUsers.clear();
    while (!ist.atEnd())
    {
        User u;
        ist >> u;
        vUsers.push_back(u);
    }
}

void MainWindow::ImportRoomsCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Rooms", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    std::unique_ptr<RoomTable> rt(new RoomTable);
    QTextStream in(&file); bool first_str = true;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
            first_str = false;
        else
        {
            Room r;
            QStringList list;
            for (QString item : line.split(";"))
                list.push_back(item);
            r.setNum(list[0].toInt());
            r.setCapacity(list[1].toInt());
            r.setPrice(list[3].toInt());

            if (list[2] == "Luxe")
                r.setComfort(2);
            else if (list[2] == "Semiluxe")
                r.setComfort(1);
            else
                r.setComfort(0);
            rt->push_back(r);
        }
    }
    file.close();
    setvroom(rt.release());
}

void MainWindow::ExportRoomsCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Rooms As"), QString("/backupRooms-%1").arg(ui->dateTimeEdit->text()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);

    ost << QString("Номер;Вместимость;Комфорт;Цена\n").toUtf8();
    for (int i = 0; i < vRoom->size(); i++)
    {
        QString line;
        line = line + QString("%1").arg((*vRoom)[i].getNum()) + ";";
        line = line + QString("%1").arg((*vRoom)[i].getCapacity()) + ";";

        if ((*vRoom)[i].getComfort() == 2)
            line = line + QString("%1").arg("Luxe") + ";";
        else if ((*vRoom)[i].getComfort() == 1)
            line = line + QString("%1").arg("Semiluxe") + ";";
        else
            line = line + QString("%1").arg("Default") + ";";

        line = line + QString("%1").arg((*vRoom)[i].getPrice()) + '\n';
        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

void MainWindow::ExportUsersCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Users As"), QString("/backupUsers-%1").arg(ui->dateTimeEdit->text()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);

    ost << QString("Фамилия;Имя;Отчество;Серия и номер паспорта;Город проживания;Дата заселения;Дата выселения;Посещений;Комната;Админ\n");
    for (int i = 0; i < vUsers.size(); i++)
    {
        QString line;
        line = line + vUsers[i].getSurname() + ";";
        line = line + vUsers[i].getName() + ";";
        line = line + vUsers[i].getPatronymic() + ";";
        line = line + vUsers[i].getSeries() + ";";
        line = line + vUsers[i].getAdress() + ";";

        line = line + vUsers[i].getDateSettling().toString("dd.MM.yyyy") + ";";
        line = line + vUsers[i].getDateRelease().toString("dd.MM.yyyy") + ";";

        line = line + QString("%1").arg(vUsers[i].getVisit()) + ";";
        line = line + QString("%1").arg(vUsers[i].getRoom()) + ";";

        if (vUsers[i].getRole() == 2)
            line = line + "Администратор" + '\n';
        else if (vUsers[i].getRole() == 1)
            line = line + "Управляющий" + '\n';
        else
            line = line + "Клиент" + '\n';
        ost << line;
    }
    outf.commit();
}

void MainWindow::ImportUsersCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Users", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    std::unique_ptr<RoomTable> rt(new RoomTable);
    QTextStream in(&file); bool first_str = true;
    vUsers.clear();
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
            first_str = false;
        else
        {
            User u;
            QStringList list;
            for (QString item : line.split(";"))
                list.push_back(item);
            u.setSurname(list[0]);
            u.setName(list[1]);
            u.setPatronymic(list[2]);
            u.setSeries(list[3]);
            u.setAdress(list[4]);
            QDate sd = QDate::fromString(list[5], "dd.MM.yyyy");
            u.setDateSettling(sd.day(), sd.month(), sd.year());
            QDate rd = QDate::fromString(list[6], "dd.MM.yyyy");
            u.setDateRelease(rd.day(), rd.month(), rd.year());
            u.setVisit(list[7].toInt());
            u.setRoom(list[8].toInt());
            if (list[9] == "Администратор")
                u.setRole(2);
            else if (list[9] == "Управляющий")
                u.setRole(1);
            else
                u.setRole(0);
            vUsers.push_back(u);
        }
    }
    file.close();
}


void MainWindow::registerUser()
{
    User u;
    RecordingUsers reg;
    reg.setUser(&u);
    reg.setWindowTitle("Hotel Booking");
    if (reg.exec() != RecordingUsers::Accepted) return;
    vUsers.push_back(u);
}

void MainWindow::authUser()
{
    role = 0;
    vUsers[index].setSelect(false);
    index = authorisation();
}

void MainWindow::windowAbout()
{
    QMessageBox about(this);
    about.setIcon(QMessageBox::Information);
    about.setWindowTitle("About Hotel Booking");
    about.setText("Hotel Booking<br>"
        "Author: Antsiferov Denis Aleksandrovich KI20-06B 032049103<br>"
        "Version: 1.0");
    about.exec();
}

void MainWindow::exit()
{
    MainWindow::close();
}

