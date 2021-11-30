/*!
 * \file
 * \brief Заголовочный файл класса BookingRoom
 */
#ifndef BOOKINGROOM_HPP
#define BOOKINGROOM_HPP

#include <QDialog>
#include "room.hpp"
#include "user.hpp"
#include "bookedroom.hpp"

namespace Ui {
class bookingRoom;
}
/*!
 * \brief Класс Бронирование комнаты
 *
 * Данный класс используется для бронирования комнаты. Вызывается во время
 * двойного нажатия комнаты в таблице комнат клиентом.
 */
class bookingRoom : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit bookingRoom(QWidget *parent = nullptr);
    //! Деконструктор
    ~bookingRoom();
    //! Устанавливает указатель на бронируемую комнату
    void setRoom(Room *room);
    //! Устанавливает указатель на пользователя, который бронирует комнату
    void setUser(User *user);
    //! Устанавливает указатель на запись брони
    void setBkdroom(std::vector<BookedRoom> *bkdr);


private slots:
    //! Функция с проверками для брони комнаты
    void accept();
    //! Функция, запускающая обновление значения цены при изменение даты въезда
    void on_sellingEdit_dateChanged(const QDate &date);
    //! Функция, запускающая обновление значения цены при изменение даты выезда
    void on_releaseEdit_dateChanged(const QDate &date);

private:
    //! Функция, считающая цену бронирования на промежуток от въезда до выезда
    void check_price();
    //! Указатель на интерфейс
    Ui::bookingRoom *ui;
    //! Указательнь на бронируемую комнату
    Room *r;
    //! Указатель на пользователя, который бронирует комнату
    User *u;
    //! Указатель на запись брони
    std::vector<BookedRoom> *bkdRoom;
};

#endif // BOOKINGROOM_HPP
