/*!
 * \file
 * \brief Заголовочный файл класса Database
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QStandardItem>
#include "config.hpp"
#include "room.hpp"
#include "user.hpp"
#include "bookedroom.hpp"

/*!
 * \brief Класс База данных.
 *
 * Данный класс хранить в себе все данные, а также занимается выводом, вводом и поиском нужного элемента.
 */
class Database
{
public:
    //! Конструктор
    Database();
    //! Функция вызова загрузки всех данных (пользователях, комнатах и забронированных комнат)
    void load();
    //! Сохранение комнат в .tnb-файл (двоичный файл)
    void saveRoomsTable();
    //! Сохранение пользователей в .tnb-файл (двоичный файл)
    void saveUsers();
    //! Сохранение данных о бронировании комнат в .tnb-файл (двоичный файл)
    void saveBookedRoom();
    //! Добавление данных о новом пользователе в .tnb-файл (двоичный файл) и в вектор пользователей
    void addUser(const User&);
    //! Добавление данных о новой комнате в .tnb-файл (двоичный файл) и в вектор комнат
    void addRoom(const Room&);
    //! Добавление данных о новой забронированной комнаты в .tnb-файл (двоичный файл и в вектор забронированных комнат
    void addBookedRoom(const BookedRoom&);
    //! Функция, возращающая указатель на вектор комнат
    std::vector<Room>* getRoomTable();
    //! Функция, возращающая указатель на вектор пользователей
    std::vector<User>* getUsers();
    //! Функция, возращающая указатель на вектор забронированных комнатах
    std::vector<BookedRoom>* getBookedRooms();
    //! Функция, проверяющая занятость комнаты и возращающая \a true , если комната поменяла статус занятости
    bool checkAvailablesRooms();
    //! Функция, проверяющая серию и номер паспорта на уникальность и возращает \a true, если номер и серия занята
    bool checkBusySeriesOfPassport(QString&);
    //! Функция, проверяющая номер комнаты на уникальность и возращает \a true, если номер занята
    bool checkBusyNumOfRoom(int);
    //! Функция вывода данных о комнатах в .csv файл
    void exportRoomsCSV();
    //! Функция ввода данных о комнатах из .csv файл
    std::vector<Room>* importRoomsCSV();
    //! Функция вывода данных о пользователях в .csv файл
    void exportUsersCSV();
    //! Функция ввода данных о пользователях из .csv файл
    std::vector<User>* importUsersCSV();
    //! Функция вывода данных о забронированных комнатах в .csv файл
    void exportBookedRoomCSV();
    //! Функция ввода данных о забронированных комнатах из .csv файл
    std::vector<BookedRoom>* importBookedRoomCSV();
    //! Функция вывода данных о комнате в контейнере QList
    QList<QStandardItem *> getDataRooms(size_t&);
    //! Фукнция, конвертирующая комфорта из числа в строку
    QString comfortToString(size_t);
    //! Фукнция, конвертирующая комфорта из строки в число
    size_t comfortToInt(QString);
    //! Функция, удаляющая комнату
    void delRoom(size_t);
    //! Функция, обновляющая данные о комнате по индексу
    void refreshDataRoom(const Room, size_t);
    //! Функция, ищущая пользователя по серию и номера паспорта
    User searchUser(QString);

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
