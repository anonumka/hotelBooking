#ifndef ROOM_HPP
#define ROOM_HPP

#include <QDataStream>
#include <QDate>

class Room
{
public:
    Room();
    const int getNum() const;
    void setNum(const int num_t);
    const int getCapacity() const;
    void setCapacity(const int capacity_t);
    const int getComfort() const;
    void setComfort(const int comfort_t);
    const int getPrice() const;
    void setPrice(const int price_t);
    const bool getAvailable() const;
    void setAvailable(const bool available);

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);


private:
    int num;
    int capacity;
    int comfort;
    int price;

    bool available;
};

inline QDataStream &operator<<(QDataStream &ost, const Room &r)
{
    r.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Room &r)
{
    r.load(ist);
    return ist;
}

#endif // ROOM_HPP
