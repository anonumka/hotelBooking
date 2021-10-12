#include <QFileDialog>
#include <QSaveFile>
#include <QDate>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>
#include <set>
#include <QStandardItemModel>

#include "config.hpp"
#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "ui_dialogbkdroom.h"
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

    setvroom(new RoomTable);

    loadRoomsTable();
    loadUsers();
    loadBookedRoom();

    index = authorisation();

    auto updateTimer = new QTimer;
    updateTimer->setInterval(30000);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedValues()));
    updateTimer->start(100);

    setFixedSize(568, 453);
}

void MainWindow::updateDisplayedValues()
{
    if (index == -1) exit();

    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());

    for (size_t i = 0; i < bkdRoom.size(); i++)
    {
        if (bkdRoom[i].getDateRelease() < QDate::currentDate())
        {
            bkdRoom[i].setRoom(0);
            bkdRoom[i].setDateSettling(1, 1, 2000);
            bkdRoom[i].setDateRelease(1, 1, 2000);
        }
    }

    for (int i = 0; i < vRoom->size(); ++i)
    {
        Room r = (*vRoom)[i];
        int num_room = r.getNum();
        int count = 0;
        for (size_t j = 0; j < bkdRoom.size(); j++)
            if (num_room == bkdRoom[j].getRoom()) count++;
        r.setAvailable(count < r.getCapacity());
        vRoom->setRoom(i, r);
    }
}


MainWindow::~MainWindow()
{
    saveRoomsTable();
    saveUsers();
    saveBookedRoom();
    delete ui;
}

void MainWindow::setEnableActionsUi (int role)
{
    ui->AddRoomBtn->setEnabled(role);
    ui->EditRoomBtn->setEnabled(role);
    ui->DelRoomBtn->setEnabled(role);

    ui->actionAddRoom->setEnabled(role);
    ui->actionEditRoom->setEnabled(role);
    ui->actionDelete_Room->setEnabled(role);
    ui->actionListUsers->setEnabled(role);

    ui->actionExportRooms->setEnabled(role == 2);
    ui->actionExportUsers->setEnabled(role == 2);
    ui->actionImportRooms->setEnabled(role == 2);
    ui->actionImportUsers->setEnabled(role == 2);
    ui->actionBooked_Rooms->setEnabled(role == 2);
    ui->actionBooked_Rooms_2->setEnabled(role == 2);
}

void MainWindow::saveRoomsTable()
{
    QSaveFile outf(config::fileRooms);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    ost << *vRoom;
    outf.commit();
}

void MainWindow::loadRoomsTable()
{
    QFile inf(config::fileRooms);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    std::unique_ptr<RoomTable> rt(new RoomTable);
    ist >> *rt;
    setvroom(rt.release());
}

void MainWindow::saveUsers()
{
    QSaveFile outf(config::fileUsers);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < vUsers.size(); i++) { ost << vUsers[i]; }
    outf.commit();
}

void MainWindow::loadUsers()
{
    QFile inf(config::fileUsers);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    vUsers.clear();
    while (!ist.atEnd())
    {
        User u;
        ist >> u;
        vUsers.push_back(u);

        BookedRoom bkdr;
        bkdr.setSeries(u.getSeries());
        bkdRoom.push_back(bkdr);
    }
}

void MainWindow::saveBookedRoom()
{
    QSaveFile outf(config::fileBookedRooms);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < bkdRoom.size(); i++) { ost << bkdRoom[i]; }
    outf.commit();
}

void MainWindow::loadBookedRoom()
{
    QFile inf(config::fileBookedRooms);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    while (!ist.atEnd())
    {
        QString series;
        ist >> series;
        for (size_t i = 0; i < bkdRoom.size(); i++)
        {
            if (series == bkdRoom[i].getSeries()) { ist >> bkdRoom[i]; }
        }
    }
}

int MainWindow::authorisation()
{
    auth au;
    au.setUsers(&vUsers);
    au.setWindowTitle(config::applicationName);
    size_t i = 0;
    if (au.exec() != auth::Accepted) { return -1; }

    for (i = 0; i < vUsers.size(); i++)
        if (vUsers[i].getSelect()) { break; }

    if (i == vUsers.size()) { return -1; }

    if (vUsers.size() == 1) { vUsers[0].setRole(2); }

    role = vUsers[i].getRole();
    setEnableActionsUi(role);

    return i;
}

void MainWindow::setvroom(RoomTable *vRooms)
{
    vRoom.reset(vRooms);
    ui->hotelView->setModel(vRoom.get());
}

void MainWindow::addRoom(const Room &r)
{
    vRoom->push_back(r);
}

void MainWindow::addUser(User u)
{
    vUsers.push_back(u);
}

void MainWindow::create_room()
{
    Room r;
    EditRoom cr;
    cr.setRoom(&r);
    cr.setWindowTitle(config::applicationName);
    cr.setTitle("Room creator: ");
    if (cr.exec() != EditRoom::Accepted) return;
    addRoom(r);
}

void MainWindow::edit_room()
{
    if (!ui->hotelView->selectionModel()->hasSelection())
    {
        QMessageBox::warning(this, config::applicationName, "Choice a room in table.");
        return;
    }
    std::set<int> rows;
    {
        QModelIndexList idc = ui->hotelView->selectionModel()->selectedRows();
        (&idc)->last();

        for (const auto &i : idc) rows.insert(i.row());
    }
    for (auto it = rows.rbegin(); it != rows.rend(); ++it)
    {
        Room r = (*vRoom)[*it];
        EditRoom er;
        er.setRoom(&r);
        er.setWindowTitle(config::applicationName);
        er.setTitle("Room editor: ");
        if (er.exec() != EditRoom::Accepted) return;
        vRoom->setRoom(*it, r);
    }
}

void MainWindow::del_room()
{
    if (!ui->hotelView->selectionModel()->hasSelection())
    {
        QMessageBox::warning(this, config::applicationName, "Choice a room in table.");
        return;
    }
    std::set<int> rows;
    {
        QModelIndexList idc = ui->hotelView->selectionModel()->selectedRows();
        (&idc)->last();

        for (const auto &i : idc) rows.insert(i.row());
    }
    for (auto it = rows.rbegin(); it != rows.rend(); ++it)
    {
        int num = (*vRoom)[*it].getNum();
        int count = 0;
        for (size_t i = 0; i < bkdRoom.size(); i++)
        {
            if ((*vRoom)[*it].getNum() == bkdRoom[i].getRoom()) { count++; }
        }
        if (count != 0)
            if (QMessageBox::question(this, config::applicationName,
                                          tr("%1 users booked this room. Are you sure you want to delete this room?").arg(count)) == QMessageBox::No)
            { return; }
        vRoom->erase(*it);
    }
}

void MainWindow::list_user()
{
    ListUsers lu;
    lu.setUsers(&vUsers);
    lu.setBkdRooms(&bkdRoom);
    lu.setWindowTitle("List Users");
    if (lu.exec() != ListUsers::Accepted) return;
}

void MainWindow::listUsersBookedRoom(const QModelIndex &idx)
{
    QDialog *listbkdroom = new QDialog;
    Ui::Dialog ui_listbkdroom;
    listbkdroom->setFixedSize(452, 327);

    ui_listbkdroom.setupUi(listbkdroom);
    listbkdroom->setWindowTitle(config::applicationName);
    int num = (*vRoom)[idx.row()].getNum();
    ui_listbkdroom.label->setText(QString("Комната %1").arg(num));

    QStandardItemModel *bkrModel = new QStandardItemModel(this);
    bkrModel->setColumnCount(3);
    bkrModel->setHorizontalHeaderLabels(QStringList() << "Фамилия" << "Паспорт" << "Дата заселения" << "Дата выселения");
    ui_listbkdroom.tableView->setModel(bkrModel);
    ui_listbkdroom.tableView->horizontalHeader()->setStretchLastSection(true);
    ui_listbkdroom.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui_listbkdroom.tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    for (size_t i = 0; i < bkdRoom.size(); ++i)
    {
        if (bkdRoom[i].getRoom() == num)
        {
            QList<QStandardItem *> standardItemsList;
            BookedRoom bkdr = bkdRoom[i];
            User u;
            for (size_t j = 0; j < vUsers.size(); i++)
            {
                if (bkdr.getSeries() == vUsers[i].getSeries())
                {
                    u = vUsers[i];
                    break;
                }
            }
            standardItemsList.append(new QStandardItem(u.getSurname()));
            standardItemsList.append(new QStandardItem(bkdr.getSeries()));
            standardItemsList.append(new QStandardItem(bkdr.getDateSettling().toString()));
            standardItemsList.append(new QStandardItem(bkdr.getDateRelease().toString()));
            bkrModel->insertRow(bkrModel->rowCount(), standardItemsList);
        }
    }
    if (!bkrModel->rowCount())
    {
        QMessageBox::information(this, "Booking Room", "Room is empty!");
        return;
    }

    listbkdroom->show();
}

void MainWindow::booking_room(const QModelIndex &idx)
{
    if (role)
    {
        listUsersBookedRoom(idx);
        return;
    }
    Room r = (*vRoom)[idx.row()];
    BookedRoom bkr;
    bookingRoom br;
    br.setRoom(&r);
    br.setUser(&vUsers[index]);
    br.setBkdroom(&bkdRoom);
    br.setWindowTitle("Booking room");
    if (br.exec() != bookingRoom::Accepted) return;
    vRoom->setRoom(idx.row(), r);
}

void MainWindow::exportRoomsCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Rooms As"), QString("/backupRooms-%1").arg(QDate::currentDate().toString()), "*.csv");
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

void MainWindow::importRoomsCSV()
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

void MainWindow::exportUsersCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Users As"), QString("/backupUsers-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);

    ost << QString("Фамилия;Имя;Отчество;Серия и номер паспорта;Город проживания;Админ\n");
    for (size_t i = 0; i < vUsers.size(); i++)
    {
        QString line;
        line = line + vUsers[i].getSurname() + ";";
        line = line + vUsers[i].getName() + ";";
        line = line + vUsers[i].getPatronymic() + ";";
        line = line + vUsers[i].getSeries() + ";";
        line = line + vUsers[i].getAdress() + ";";

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

void MainWindow::importUsersCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Users", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    std::unique_ptr<RoomTable> rt(new RoomTable);
    QTextStream in(&file); bool first_str = true;
    vUsers.clear();
    bkdRoom.clear();
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
            if (list[5] == "Администратор")
                u.setRole(2);
            else if (list[5] == "Управляющий")
                u.setRole(1);
            else
                u.setRole(0);
            addUser(u);

            BookedRoom bkdr;
            bkdr.setSeries(list[3]);
            bkdRoom.push_back(bkdr);
        }
    }
    file.close();
}

void MainWindow::exportBookedRoomCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Booked Rooms As"), QString("/backupBkdRooms-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);

    ost << QString("Номер;Серия;Заселение;Выселение\n").toUtf8();
    for (size_t i = 0; i < bkdRoom.size(); i++)
    {
        QString line;

        line = line + QString("%1").arg(bkdRoom[i].getRoom()) + ";";
        line = line + bkdRoom[i].getSeries() + ";";
        line = line + bkdRoom[i].getDateSettling().toString("dd.MM.yyyy") + ";";
        line = line + bkdRoom[i].getDateRelease().toString("dd.MM.yyyy") + ";\n";

        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

void MainWindow::importBookedRoomCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Booked Rooms", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file); bool first_str = true;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
            first_str = false;
        else
        {
            QStringList list;
            for (QString item : line.split(";"))
                list.push_back(item);

            for (size_t i = 0; i < bkdRoom.size(); i++)
            {
                if (list[1] == bkdRoom[i].getSeries())
                {
                    bkdRoom[i].setRoom(list[0].toInt());
                    QDate sd = QDate::fromString(list[2], "dd.MM.yyyy");
                    bkdRoom[i].setDateSettling(sd.day(), sd.month(), sd.year());
                    QDate rd = QDate::fromString(list[3], "dd.MM.yyyy");
                    bkdRoom[i].setDateRelease(rd.day(), rd.month(), rd.year());
                }
            }
        }
    }
    file.close();
}

void MainWindow::authUser()
{
    vUsers[index].setSelect(false);
    int tmp = authorisation();
    if (tmp != -1)
    {
        index = tmp;
    }
    else
    {
        role = vUsers[index].getRole();
    }
}

void MainWindow::windowAbout()
{
    QMessageBox about(this);
    about.setIcon(QMessageBox::Information);
    about.setWindowTitle(QString("About %1").arg(config::applicationName));
    about.setText(QString("%1<br>"
        "Author: <a href=\"mailto:cergeu912@gmail.com\">Antsiferov Denis Aleksandrovich</a><br>"
        "Github: <a href=\"https://github.com/anonumka?tab=repositories\">*click*</a><br>"
        "Icons by <a href=\"http://tango.freedesktop.org/"
        "Tango_Desktop_Project\">The Tango! Desktop Project</a><br>"
        "Version %1: %2<br> Version QT: %3")
                  .arg(config::applicationName).arg(config::applicationVersion).arg(qVersion()));
    about.exec();
}

void MainWindow::exit()
{
    MainWindow::close();
}

