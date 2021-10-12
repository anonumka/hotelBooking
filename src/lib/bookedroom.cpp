#include "bookedroom.hpp"

BookedRoom::BookedRoom()
{
    room = 0;
    date_settling.setDate(1, 1, 2000);
    date_release.setDate(1, 1, 2000);
}

const QString &BookedRoom::getSeries() const
{
    return series;
}

void BookedRoom::setSeries(const QString &series_t)
{
    series = series_t;
}

const QDate BookedRoom::getDateSettling() const
{
    return date_settling;
}

void BookedRoom::setDateSettling(const int day, const int month, const int year)
{
    date_settling.setDate(year, month, day);
}

const QDate BookedRoom::getDateRelease() const
{
    return date_release;
}

void BookedRoom::setDateRelease(const int day, const int month, const int year)
{
    date_release.setDate(year, month, day);
}

int BookedRoom::getRoom() const
{
    return room;
}

void BookedRoom::setRoom(const int number)
{
    room = number;
}

void BookedRoom::save(QDataStream &ost) const
{
    ost << series << room << date_settling << date_release;
}

void BookedRoom::load(QDataStream &ist)
{
    ist >> room >> date_settling >> date_release;
}
