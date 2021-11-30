/*!
 * \file
 * \brief Заголовочный файл класса User
 */
#ifndef USER_HPP
#define USER_HPP
#include <QString>
#include <QDate>
/*!
 * \brief Класс Пользователь
 *
 * Данным класс является базовым также, как и комнаты, который необходим для основного
 * функционала программы.
 */
class User
{
public:
    //! Конструктор
    User();
    //! Возращение фамилии пользователя
    const QString &getSurname() const;
    //! Установление фамилии пользователя на \a surname_t
    void setSurname(const QString &surname_t);
    //! Возращение имени пользователя
    const QString &getName() const;
    //! Установление имени пользователя на \a name_t
    void setName(const QString &name_t);
    //! Возращение отчества пользователя
    const QString &getPatronymic() const;
    //! Установление отчества пользователя на \a patronymic_t
    void setPatronymic(const QString &patronymic_t);
    //! Возращение серии и номера пользователя
    const QString &getSeries() const;
    //! Установление серии и номера пользователя на \a series_t
    void setSeries(const QString &series_t);
    //! Возращение адреса пользователя
    const QString &getAdress() const;
    //! Установление адреса пользователя на \a adress_t
    void setAdress(const QString &adress_t);
    //! Возращение количества посещений гостиницы пользователем
    const int getVisit() const;
    //! Установление количества посещений гостиницы пользователем на \a +1
    void addVisit();
    //! Установление количества посещений гостиницы пользователем на \a visit_counter
    void setVisit(const int visit_counter);
    //! Возращение роль пользователя
    const int getRole() const;
    //! Установление роли пользователя на \a adm
    void setRole(const int adm);
    //! Возращение выбранного пользователя во время авторизации
    const bool getSelect() const;
    //! Установление выбранного пользователя на \с true, если авторизирован
    void setSelect(const bool selection);
    //! Сохранение значения переменных в поток \a ost
    void save(QDataStream &ost) const;
    //! Загрузка значения переменных из потока \a ist
    void load(QDataStream &ist);

private:
    //! Фамилия пользователя
    QString surname;
    //! Имя пользователя
    QString name;
    //! Отчество пользователя
    QString patronymic;
    //! Серия и номер паспорта пользователя
    QString series;
    //! Адрес пользователя
    QString adress;
    //! Количество посещений гостиницы пользователем
    int count_visit;
    //! Роль пользователя
    int role;
    //! Текущий пользователь программы
    bool selected;
};
/*!
 * \brief Реализация оператора << для вывода пользователя из QDataStream
 * \param ost Поток вывода.
 * \param u Пользователь
 * \return Поток \a ost после вывода.
 */
inline QDataStream &operator<<(QDataStream &ost, const User &u)
{
    u.save(ost);
    return ost;
}
/*!
 * \brief Реализация оператора >> для ввода пользователя из QDataStream
 * \param ist Поток ввода.
 * \param u Пользователь
 * \return Поток \a ist после ввода.
 */
inline QDataStream &operator>>(QDataStream &ist, User &u)
{
    u.load(ist);
    return ist;
}

#endif // USER_HPP
