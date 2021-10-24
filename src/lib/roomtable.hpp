#ifndef ROOMTABLE_H
#define ROOMTABLE_H

#include <QObject>
#include <QAbstractTableModel>

#include "room.hpp"

class RoomTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    RoomTable();
    using SizeType = int;
    const Room &operator[](SizeType idx) const;
    SizeType size() const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void push_back(const Room &room);
    void erase(SizeType idx);
    void setRoom(RoomTable::SizeType idx, Room room);
    void save(QDataStream &ost) const;
    SizeType load(QDataStream &ist);

signals:

private:
    std::vector<Room> vRoom;;

};

inline QDataStream &operator<<(QDataStream &ost, const RoomTable &vr)
{
    vr.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, RoomTable &vr)
{
    vr.load(ist);
    return ist;
}

#endif // ROOMTABLE_H
