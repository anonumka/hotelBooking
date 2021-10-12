#ifndef BOOKEDROOM_HPP
#define BOOKEDROOM_HPP
#include <QString>
#include <QDate>

class BookedRoom
{
public:
    BookedRoom();

    int getRoom() const;
    void setRoom(const int number);
    const QDate getDateSettling() const;
    const QString &getSeries() const;
    void setSeries(const QString &series_t);
    void setDateSettling(const int day, const int month, const int year);
    const QDate getDateRelease() const;
    void setDateRelease(const int day, const int month, const int year);

    void save(QDataStream &ost) const;
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
