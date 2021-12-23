#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QStandardItem>

#include "config.hpp"
#include "room.hpp"
#include "user.hpp"
#include "bookedroom.hpp"

class Database
{
public:
    //! Конструктор класса базы данных
    Database();
    //! Функция вызова загрузки всех данных (пользователях, комнатах и забронированных комнат)
    void load();
    //! Сохранение комнат в .tnb-файл (двоичный файл)
    void saveRoomsTable();
    //! Сохранение пользователей в .tnb-файл (двоичный файл)
    void saveUsers();
    //! Сохранение данных о бронировании комнат в .tnb-файл (двоичный файл)
    void saveBookedRoom();
    //! Добавление данных о новом пользователе в .tnb-файл (двоичный файл)
    void addUser(const User&);
    //! Добавление данных о новой комнате в .tnb-файл (двоичный файл)
    void addRoom(const Room&);

    void addBookedRoom(const BookedRoom&);
    //! Функция, возращающая указатель на вектор комнат
    std::vector<Room>* getRoomTable();
    //! Функция, возращающая указатель на вектор пользователей
    std::vector<User>* getUsers();
    //! Функция, возращающая указатель на вектор забронированных комнатах
    std::vector<BookedRoom>* getBookedRooms();

    bool checkAvailablesRooms();

    bool checkBusySeriesOfPassport(QString&);

    bool checkBusyNumOfRoom(int);

    void exportRoomsCSV();

    std::vector<Room>* importRoomsCSV();

    void exportUsersCSV();

    std::vector<User>* importUsersCSV();

    void exportBookedRoomCSV();

    std::vector<BookedRoom>* importBookedRoomCSV();

    QList<QStandardItem *> getDataRooms(size_t&);

    QString comfortToString(size_t);

    size_t comfortToInt(QString);

    void delRoom(size_t);

    void refreshDataRoom(const Room, size_t);

private:
    //! Загрузка данных о пользователях в .tnb-файл (двоичный файл)
    void loadUsers();
    //! Загрузка данных о комнатах в .tnb-файл (двоичный файл)
    void loadRoomsTable();
    //! Загрузка данных о забронированных комнатах в .tnb-файл (двоичный файл)
    void loadBookedRoom();
    //! Вектор с комнатами
    std::vector<Room> vRooms;
    //! Вектор с пользователями
    std::vector<User> vUsers;
    //! Вектор с забронированными пользователями комнаты
    std::vector<BookedRoom> bkdRoom;
};

#endif // DATABASE_HPP
