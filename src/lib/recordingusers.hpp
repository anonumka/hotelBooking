/*!
 * \file
 * \brief Заголовочный файл класса RecordingUsers
 */
#ifndef RECORDINGUSERS_HPP
#define RECORDINGUSERS_HPP

#include <QDialog>
#include "user.hpp"
#include "bookedroom.hpp"

namespace Ui {
class RecordingUsers;
}
/*!
 * \brief Класс Запись пользователей
 *
 * Данный класс вызывается во время регистрации пользователей из окна Auth.
 */
class RecordingUsers : public QDialog
{
    Q_OBJECT

public:
    //! Конструтор
    explicit RecordingUsers(QWidget *parent = nullptr);
    //! Деконструтор
    ~RecordingUsers();
    //! Установка указателя на регистрируемого пользователя
    void setUser(User *u);
    //! Установка указателя на запись о бронировании пользователем
    void setbkdRoom(BookedRoom *bkdr);
    //! Установка \a surname в поле фамилии пользователя
    void setSurname(QString surname);
    //! Установка \a name в поле имени пользователя
    void setName(QString name);
    //! Установка \a patronymic в поле отчества пользователя
    void setPatronymic(QString patronymic);
    //! Установка \a series в поле серии и номера паспорта пользователя
    void setSeriesNumPassport(QString series);
    //! Установка \a city в поле города пользователя
    void setCity(QString city);
    //! Установка \a series в вектор занятых серии и номеров паспортов
    void setSeriesOtherUser(QString series);
    //! Установка вектора \a BusySeries в вектор занятых занятых серии и номеров паспортов
    void setBusySeriesUsers(std::vector<QString> &BusySeries);

private slots:

public slots:
    //! Проверки перед регистрацией пользователя
    void accept();

private:
    //! Указатель на интерфейс программы
    Ui::RecordingUsers *ui;
    //! Указатель на регистрируемого пользователя
    User *user;
    //! Указатель на запись бронирования комнаты пользователем
    BookedRoom *bkd;
    //! Вектор занятых серий и номеров паспортов
    std::vector<QString> vNums;
};

#endif // RECORDINGUSERS_HPP
