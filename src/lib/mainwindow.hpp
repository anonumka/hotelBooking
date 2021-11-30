/*!
 * \file
 * \brief Заголовочный файл главного экрана
 */
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "roomtable.hpp"
#include "editroom.hpp"
#include "recordingusers.hpp"
#include "bookedroom.hpp"

#include "config.hpp"
#include "ui_mainwindow.h"
#include "ui_dialogbkdroom.h"
#include "roomtable.hpp"
#include "bookingroom.hpp"
#include "ui_recordingusers.h"
#include "listusers.hpp"
#include "auth.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*!
 * \brief Класс Главное окно.
 *
 * В этом классе происходят вызов всех основных функций программы.
 * Изначально запускает запуск авторизации, и если нажата Отмена, окно закрывается.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Конструктор
    MainWindow(QWidget *parent = nullptr);
    //! Деструктор
    ~MainWindow();
    //! Авторизация
    int authorisation();
    //! Отображение пользователей, забронировавших выбранную комнату
    void listUsersBookedRoom(const QModelIndex &idx);
    //! Включение/отключение кнопок взависимости от пользователя
    void setEnableActionsUi (int role);
    //! Сохранение пользователей в .tnb-файл
    void saveUsers();
    //! Загрузка пользователей в .tnb-файл
    void loadUsers();
    //! Сохранение списка комнат в .tnb-файл
    void saveRoomsTable();
    //! Загрузка списка комнат в .tnb-файл
    void loadRoomsTable();
    //! Сохранение списка забронированных комнат в .tnb-файл
    void saveBookedRoom();
    //! Загрузка списка комнат в .tnb-файл
    void loadBookedRoom();
    //! Добавление пользователя в vUsers
    void addUser(User u);
    //! Добавление комнаты в vRooms
    void addRoom(const Room &r);
    //! Обновление таблицы с комнатами
    void setvroom(RoomTable *vRooms);
public slots:
    //! Обновление доступных комнат и времени, расположенного в главном меню
    void updateDisplayedValues();
    //! Сохранение комнат в формате .csv
    void importRoomsCSV();
    //! Загрузка комнат в формате .csv
    void exportRoomsCSV();
    //! Сохранение пользователей в формате .csv
    void importUsersCSV();
    //! Загрузка пользоватедей в формате .csv
    void exportUsersCSV();
    //! Сохранение забронированных комнат в формате .csv
    void importBookedRoomCSV();
    //! Загрузка забронированных комнат в формате .csv
    void exportBookedRoomCSV();
    //! Функция создания комнаты
    void create_room();
    //! Функция редактирования комнаты
    void edit_room();
    //! Функция удаления комнаты
    void del_room();
    //! Функция бронирования комнаты для клиентов
    void booking_room(const QModelIndex &idx);
    //! Список пользователей, доступный менеджерам и администраторам
    void list_user();
    //! Функция выхода из учетной записи
    void authUser();
    //! Функция вывода информации о программе
    void windowAbout();
    //! Завершение программы
    void exit();

private:
    //! Указатель на интерфейс
    Ui::MainWindow *ui;
    //! Вектор с комнатами
    std::unique_ptr<RoomTable> vRoom;
    //! Вектор с пользователями
    std::vector<User> vUsers;
    //! Вектор с забронированными пользователями комнаты
    std::vector<BookedRoom> bkdRoom;
    //! Роль пользователя
    int role;
    //! Индекс пользователя в векторе с пользователями
    int index;
};
#endif // MAINWINDOW_HPP
