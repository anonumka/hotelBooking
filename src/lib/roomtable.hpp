/*!
 * \file
 * \brief Заголовочный файл класса RoomTable
 */
#ifndef ROOMTABLE_H
#define ROOMTABLE_H

#include <QObject>
#include <QAbstractTableModel>

#include "room.hpp"

/*!
 * \brief Класс Таблица комнат
 *
 * Данный класс является базовым для построения таблицы комнат из главного окна.
 */
class RoomTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    //! Конструктор
    RoomTable();
    //! Изменение типа индектов и размера контейнера на целочисленный тип
    using SizeType = int;
    //! Оператор [] с параметром idx
    const Room &operator[](SizeType idx) const;
    //! Возращает размер массива
    SizeType size() const;
    //! Установка строк данным типом для таблицы
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    //! Установка столбиков данным типом для таблицы
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    //! Установка названия столбиков таблицы
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    //! Установка данных в таблицу
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    //! Вставка \a room в вектор комнат
    void push_back(const Room &room);
    //! Удаление комнаты индексом \a idx из вектора комнат
    void erase(SizeType idx);
    //! Замена информации в комнате
    void setRoom(RoomTable::SizeType idx, Room room);
    //! Вывод информации о комнате в поток \a ost
    void save(QDataStream &ost) const;
    //! Ввод информации о комнате из потока \a ist
    SizeType load(QDataStream &ist);

private:
    //! Вектор комнат
    std::vector<Room> vRoom;;

};

/*!
 * \brief Реализация оператора << для вывода класса Roomtable в QDataStream
 * \param ost Поток вывода.
 * \param vr RoomTable
 * \return Поток \a ost после вывода.
 */
inline QDataStream &operator<<(QDataStream &ost, const RoomTable &vr)
{
    vr.save(ost);
    return ost;
}
/*!
 * \brief Реализация оператора >> для ввода класса Roomtable из QDataStream
 * \param ist Поток ввода.
 * \param vr RoomTable
 * \return Поток \a ist после ввода.
 */
inline QDataStream &operator>>(QDataStream &ist, RoomTable &vr)
{
    vr.load(ist);
    return ist;
}

#endif // ROOMTABLE_H
