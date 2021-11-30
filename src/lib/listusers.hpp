/*!
 * \file
 * \brief Заголовочный файл класса ListUsers
 */
#ifndef LISTUSERS_HPP
#define LISTUSERS_HPP

#include <QDialog>
#include "user.hpp"
#include "bookedroom.hpp"

namespace Ui {
class ListUsers;
}
/*!
 * \brief Класс Лист пользователей
 *
 * Данный класс предназначен для того, чтобы управляющие и администраторы могли
 * смотреть информацию о пользователях. Администратор в этом окне может настраивать
 * права для пользователей. Можно сбросить информацию о пользователе до исходных.
 */
class ListUsers : public QDialog
{
    Q_OBJECT

public:
    //! Конструтор
    explicit ListUsers(QWidget *parent = nullptr);
    //! Деконструтор
    ~ListUsers();
    //! Установка указателя на вектор пользователей
    void setUsers(std::vector<User> *vU);
    //! Установка указателя на вектор бронированных комнат
    void setBkdRooms(std::vector<BookedRoom> *bkdr);

private slots:
    //! Функция, отслеживающая изменения пользователей
    void on_comboBox_activated(int index);
    //! Проверки перед изменением пользователей
    void accept();
    //! Сброс данных о пользователе
    void on_resetBtn_clicked();

private:
    //! Указатель на интерфейс
    Ui::ListUsers *ui;
    //! Указатель на вектор пользователей
    std::vector<User> *vUsers;
    //! Указатель на вектор бронированных комнат
    std::vector<BookedRoom> *bkdRoom;
    //! Роль пользователя
    int role;
};

#endif // LISTUSERS_HPP
