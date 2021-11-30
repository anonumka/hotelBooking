/*!
 * \file
 * \brief Заголовочный файл класса BookedRoom
 */
#ifndef BOOKEDROOM_HPP
#define BOOKEDROOM_HPP
#include <QString>
#include <QDate>
/*!
 * \brief Класс Забронированная комната
 *
 * Класс, который  хранит в себе комнату, серию и номер паспорта, дату заселения и
 * дату выселения. Другими словами, каждый пользователь имеет забронированную комнату
 * только в нужный момент добавляется номер, дата заселения и дата выселения.
 */
class BookedRoom
{
public:
    //! Конструктор
    BookedRoom();
    //! Возращение значения номера комнаты
    int getRoom() const;
    //! Устанавливает значение \a number для номера комнаты
    void setRoom(const int number);
    //! Возращает серию и номер паспорта
    const QString &getSeries() const;
    //! Устанавливает значение \a series_t для серии и номера паспорта
    void setSeries(const QString &series_t);
    //! Возращает дату заселения
    const QDate getDateSettling() const;
    //! Устанавливает значение \a day дня, \a month месяца и \a year года заселения
    void setDateSettling(const int day, const int month, const int year);
    //! Возращает дату выселения
    const QDate getDateRelease() const;
    //! Устанавливает значение \a day дня, \a month месяца и \a year года выселения
    void setDateRelease(const int day, const int month, const int year);
    //! Сохранение значений переменных в поток \a ost
    void save(QDataStream &ost) const;
    //! Загрузка значений переменных из потока \a ist
    void load(QDataStream &ist);

private:
    QString series;
    int room;
    QDate date_settling;
    QDate date_release;
};

inline QDataStream &operator<<(QDataStream &ost, const BookedRoom &b)
{
    b.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, BookedRoom &b)
{
    b.load(ist);
    return ist;
}

#endif // BOOKEDROOM_HPP
