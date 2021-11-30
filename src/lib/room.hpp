/*!
 * \file
 * \brief Заголовочный файл класса Room
 */
#ifndef ROOM_HPP
#define ROOM_HPP

#include <QDataStream>
#include <QDate>
/*!
 * \brief Класс Комната.
 *
 * Данный класс является базовым функционалом для программы.
 */
class Room
{
public:
    //! Конструктор
    Room();
    //! Возвращает номер комнаты
    const int getNum() const;
    //! Устанавливает номер комнаты значения \a num_t
    void setNum(const int num_t);
    //! Возвращает вместимость комнаты
    const int getCapacity() const;
    //! Устанавливает вместимость комнаты значения \a capacity_t
    void setCapacity(const int capacity_t);
    //! Возвращает комфорт комнаты
    const int getComfort() const;
    //! Устанавливает комфорт комнаты значения \a comfort_t
    void setComfort(const int comfort_t);
    //! Возвращает цену комнаты
    const int getPrice() const;
    //! Устанавливает цену комнаты значения \a price_t
    void setPrice(const int price_t);
    //! Возвращает \с true, если комната свобода
    const bool getAvailable() const;
    //! Устанавливает доступность комнаты
    void setAvailable(const bool available);
    //! Сохранение значения переменных в поток \a ost
    void save(QDataStream &ost) const;
    //! Загрузка значения переменных из потока \a ist
    void load(QDataStream &ist);


private:
    //! Номер комнаты
    int num;
    //! Вместимость комнаты
    int capacity;
    //! Комфорт комнаты
    int comfort;
    //! Цена комнаты
    int price;
    //! Доступность комнаты в данный момент
    bool available;
};

/*!
 * \brief Реализация оператора << для вывода Room в QDataStream
 * \param ost Поток вывода.
 * \param r Комната
 * \return Поток \a ost после вывода.
 */

inline QDataStream &operator<<(QDataStream &ost, const Room &r)
{
    r.save(ost);
    return ost;
}
/*!
 * \brief Реализация оператора >> для ввода Room в QDataStream
 * \param ist Поток ввода.
 * \param r Комната
 * \return Поток \a ist после ввода.
 */
inline QDataStream &operator>>(QDataStream &ist, Room &r)
{
    r.load(ist);
    return ist;
}

#endif // ROOM_HPP
