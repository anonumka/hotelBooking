#include <QSaveFile>
#include <QFile>
#include <QFileDialog>
#include "database.hpp"

Database::Database()
{

}

void Database::saveRoomsTable()
{
    QSaveFile outf(config::fileRooms);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < vRooms.size(); i++) {
        ost << vRooms[i];
    }
    outf.commit();
}

QString Database::comfortToString(size_t comfort_)
{
    if (comfort_ == 0)
        return "Default";
    else if (comfort_ == 1)
        return "Semiluxe";
    return "Luxe";
}

size_t Database::comfortToInt(QString comfort_)
{
    if (comfort_ == "Default")
        return 0;
    else if (comfort_ == "Semiluxe")
        return 1;
    return 2;
}

QList<QStandardItem *> Database::getDataRooms(size_t& i)
{
    QList<QStandardItem *> standardItemsList;
    standardItemsList.append(new QStandardItem(QString("%1").arg(vRooms[i].getNum())));
    standardItemsList.append(new QStandardItem(QString("%1").arg(vRooms[i].getCapacity())));
    standardItemsList.append(new QStandardItem(comfortToString(vRooms[i].getComfort())));
    standardItemsList.append(new QStandardItem(QString("%1").arg(vRooms[i].getPrice())));
    if (vRooms[i].getAvailable())
        standardItemsList.append(new QStandardItem("Свободна"));
    else
        standardItemsList.append(new QStandardItem("Занята"));
    return standardItemsList;
}

void Database::delRoom(size_t index)
{
    int num = vRooms[index].getNum();

    for (size_t i = 0; i < bkdRoom.size(); i++)
    {
        if (bkdRoom[i].getRoom() == num)
        {
            bkdRoom.erase(bkdRoom.begin() + i);
        }
    }

    vRooms.erase(vRooms.begin() + index);


}

void Database::saveUsers()
{
    QSaveFile outf(config::fileUsers);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < vUsers.size(); i++) {
        ost << vUsers[i];
    }
    outf.commit();
}

void Database::addUser(const User& user_)
{
    vUsers.push_back(user_);
    QFile outf(config::fileUsers);
    outf.open(QIODevice::Append);
    QDataStream out(&outf);
    out << user_;
}

void Database::addRoom(const Room &room_)
{
    vRooms.push_back(room_);
    QFile outf(config::fileRooms);
    outf.open(QIODevice::Append);
    QDataStream out(&outf);
    out << room_;
}

void Database::addBookedRoom(const BookedRoom& bkdr_)
{
    bkdRoom.push_back(bkdr_);
    QFile outf(config::fileBookedRooms);
    outf.open(QIODevice::Append);
    QDataStream out(&outf);
    out << bkdr_;
}

void Database::saveBookedRoom()
{
    QSaveFile outf(config::fileBookedRooms);
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < bkdRoom.size(); i++) {
        ost << bkdRoom[i];
    }
    outf.commit();
}

void Database::load()
{
    loadRoomsTable();
    loadUsers();
    loadBookedRoom();
}

void Database::loadRoomsTable()
{
    QFile inf(config::fileRooms);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    vRooms.clear();
    while (!ist.atEnd())
    {
        Room r;
        ist >> r;
        vRooms.push_back(r);
    }
}

void Database::loadUsers()
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

void Database::loadBookedRoom()
{
    QFile inf(config::fileBookedRooms);
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    while (!ist.atEnd())
    {
        QString series;
        ist >> series;
        for (size_t i = 0; i < bkdRoom.size(); i++) {
            if (series == bkdRoom[i].getSeries()) {
                ist >> bkdRoom[i];
            }
        }
    }
}

void Database::exportRoomsCSV()
{
    QString fileName = QFileDialog::getSaveFileName(0, "Save Rooms As", QString("/backupRooms-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);

    ost << QString("Номер;Вместимость;Комфорт;Цена\n").toUtf8();
    for (size_t i = 0; i < vRooms.size(); i++)
    {
        QString line;
        line = line + QString("%1").arg(vRooms[i].getNum()) + ";";
        line = line + QString("%1").arg(vRooms[i].getCapacity()) + ";";

        if (vRooms[i].getComfort() == 2)
            line = line + QString("%1").arg("Luxe") + ";";
        else if (vRooms[i].getComfort() == 1)
            line = line + QString("%1").arg("Semiluxe") + ";";
        else
            line = line + QString("%1").arg("Default") + ";";

        line = line + QString("%1").arg(vRooms[i].getPrice()) + '\n';
        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

std::vector<Room>* Database::importRoomsCSV()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open Rooms", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    vRooms.clear();
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
            vRooms.push_back(r);
        }
    }
    file.close();
    return &vRooms;
}

void Database::exportUsersCSV()
{
    QString fileName = QFileDialog::getSaveFileName(0, "Save Users As", QString("/backupUsers-%1").arg(QDate::currentDate().toString()), "*.csv");
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

std::vector<User>* Database::importUsersCSV()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open Users", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
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
    return &vUsers;
}

void Database::exportBookedRoomCSV()
{
    QString fileName = QFileDialog::getSaveFileName(0, "Save Booked Rooms As", QString("/backupBkdRooms-%1").arg(QDate::currentDate().toString()), "*.csv");
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

std::vector<BookedRoom>* Database::importBookedRoomCSV()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open Booked Rooms", "", "*.csv");
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
    return &bkdRoom;
}

bool Database::checkAvailablesRooms()
{
    for (size_t i = 0; i < vRooms.size(); ++i) {
        Room *r = &vRooms[i];
        int num_room = r->getNum();
        int count = 0;
        for (size_t j = 0; j < bkdRoom.size(); j++)
            if (num_room == bkdRoom[j].getRoom()) {
                count++;
            }
        bool refresh = r->getAvailable();
        r->setAvailable(count < r->getCapacity());
        if (refresh != r->getAvailable())
            return true;
    }
    return false;
}

bool Database::checkBusySeriesOfPassport(QString& series_)
{
    for (size_t i = 0; i < vUsers.size(); i++)
    {
        if (vUsers[i].getSeries() == series_)
            return true;
    }
    return false;
}

bool Database::checkBusyNumOfRoom(int num_)
{
    for (size_t i = 0; i < vRooms.size(); i++)
    {
        if (vRooms[i].getNum() == num_)
            return true;
    }
    return false;
}

User Database::searchUser(QString series_)
{
    for (size_t i = 0; i < vUsers.size(); i++) {
        if (vUsers[i].getSeries() == series_)
            return vUsers[i];
    }
    return vUsers[0];
}

void Database::refreshDataRoom(const Room room_, size_t index_)
{
    int num = vRooms[index_].getNum();

    vRooms[index_].setNum(room_.getNum());
    vRooms[index_].setCapacity(room_.getCapacity());
    vRooms[index_].setComfort(room_.getComfort());
    vRooms[index_].setPrice(room_.getPrice());
    vRooms[index_].setAvailable(room_.getAvailable());

    for (size_t i = 0; i < bkdRoom.size(); ++i)
    {
        if (bkdRoom[i].getRoom() == num)
        {
            bkdRoom[i].setRoom(vRooms[index_].getNum());
        }
    }
}

std::vector<Room> *Database::getRoomTable()
{
    return &vRooms;
}

std::vector<User>* Database::getUsers()
{
    return &vUsers;
}

std::vector<BookedRoom>* Database::getBookedRooms()
{
    return &bkdRoom;
}
