#include "roomtable.hpp"

RoomTable::RoomTable()
{
}

const Room &RoomTable::operator[](RoomTable::SizeType idx) const
{
    return vRoom[idx];
}

RoomTable::SizeType RoomTable::size() const
{
    return vRoom.size();
}

int RoomTable::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? vRoom.size() : 0;
}

int RoomTable::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 5 : 0;
}

QVariant RoomTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если речь о заголовках столбцов...
        if (orientation == Qt::Horizontal)
        {
            // Если столбец первый, возвращаем заголовок
            if (section == 0)
            {
                return tr("Number");
            }
            else if (section == 1)
            {
                return tr("Capacity");
            }
            else if (section == 2)
            {
                return tr("Comfort");
            }
            else if (section == 3)
            {
                return tr("Price");
            }
            else if (section == 4)
            {
                return tr("Available");
            }
        }
        // Если речь о заголовках строк...
        else if (orientation == Qt::Vertical)
        {
            // Возвращаем номер строки
            return QString::number(section);
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

QVariant RoomTable::data(const QModelIndex &index, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если столбец первый, возвращаем заголовок заметки, находящейся
        // в соответствующей строке таблицы
        if (index.column() == 0)
            return vRoom[index.row()].getNum();
        else if (index.column() == 1)
            return vRoom[index.row()].getCapacity();
        else if (index.column() == 2)
        {
            int comfort = vRoom[index.row()].getComfort();
            if (comfort == 0)
                return "Default";
            else if (comfort == 1)
                return "Semiluxe";
            else
                return "Luxe";
        }
        else if (index.column() == 3)
            return vRoom[index.row()].getPrice();
        else if (index.column() == 4)
        {
            bool available = vRoom[index.row()].getAvailable();
            if (available)
                return "True";
            else
                return "False";
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

void RoomTable::push_back(const Room &room)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем вставлять строки в модель.
    // Вставку производим в конец, поэтому номер новой строки будет равен size()
    beginInsertRows(QModelIndex(), // Индекс родителя, в список потомков которого добавляются строки
                    size(), // Номер первой добавляемой строки
                    size() // Номер последней добавляемой строки
                    );
    // Вставляем заметку в конец вектора mNotes
    vRoom.push_back(room);
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили вставлять строки в модель.
    endInsertRows();
}

void RoomTable::erase(SizeType idx)
{
    beginRemoveRows(QModelIndex(),
                    idx,
                    idx
                    );
    vRoom.erase(std::next(vRoom.begin(), idx));
    endRemoveRows();
}

void RoomTable::setRoom(RoomTable::SizeType idx, Room room)
{
    // Присваиваем заметку
    vRoom[idx] = room;
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что данные в строке с индексом idx изменились
    emit dataChanged(index(idx, 0), index(idx, columnCount()));
}

void RoomTable::save(QDataStream &ost) const
{
    // Цикл по всем заметкам
    for (const Room &r : vRoom) ost << r;
}

RoomTable::SizeType RoomTable::load(QDataStream &ist)
{
    beginResetModel();
    vRoom.clear();
    while (!ist.atEnd())
    {
        Room r;
        ist >> r;
        vRoom.push_back(r);
    }
    endResetModel();
    return vRoom.size();
}







