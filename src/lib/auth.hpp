#ifndef AUTH_HPP
#define AUTH_HPP
/*!
 * \file
 * \brief Заголовочный файл класса Auth
 */

#include <QDialog>
#include "user.hpp"

namespace Ui {
class Auth;
}
/*!
 * \brief Класс Авторизация.
 *
 * Вызывается во время запуска программы или во время нажатия кнопки Help->Auth.
 */
class Auth : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit Auth(QWidget *parent = nullptr);
    //! Деконструктор
    ~Auth();
    void setUsers(std::vector<User> *vU);

private slots:
    //! Функция, совершающая проверки перед тем, как подтвердить изменения
    void accept();
    //! Функция, открывающая окно регистрации при нажатии кнопки "Регистрация"
    void recordingUsersButton();

private:
    //! Указатель на интерфейс
    Ui::Auth *ui;
    //! Указатель на вектор пользователей
    std::vector<User> *vUsers;
};

#endif // AUTH_HPP
