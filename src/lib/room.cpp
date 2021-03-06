/*!
 * \file
 * \brief Файл реализация класса Room
 */
#include "room.hpp"

Room::Room()
{
    num = 0;
    capacity = 0;
    comfort = 0;
    price = 0;
}

int Room::getNum() const
{
    return num;
}

void Room::setNum(const int num_t)
{
    num = num_t;
}

int Room::getCapacity() const
{
    return capacity;
}

void Room::setCapacity(const int capacity_t)
{
    capacity = capacity_t;
}

int Room::getComfort() const
{
    return comfort;
}

void Room::setComfort(const int comfort_t)
{
    comfort = comfort_t;
}

int Room::getPrice() const
{
    return price;
}

void Room::setPrice(const int price_t)
{
    price = price_t;
}

bool Room::getAvailable() const
{
    return available;
}

void Room::setAvailable(const bool available_t)
{
    available = available_t;
}

void Room::save(QDataStream &ost) const
{
    ost << num << capacity << comfort << price;
}

void Room::load(QDataStream &ist)
{
    ist >> num >> capacity >> comfort >> price;
}
