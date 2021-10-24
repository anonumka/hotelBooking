#ifndef BOOKINGROOM_HPP
#define BOOKINGROOM_HPP

#include <QDialog>
#include "room.hpp"
#include "user.hpp"
#include "bookedroom.hpp"

namespace Ui {
class bookingRoom;
}

class bookingRoom : public QDialog
{
    Q_OBJECT

public:
    explicit bookingRoom(QWidget *parent = nullptr);
    ~bookingRoom();
    QString addItemFunction(int index);
    void setRoom(Room *room);
    void setUser(User *user);
    void setBkdroom(std::vector<BookedRoom> *bkdr);
    void check_price();

private slots:
    void accept();

    void on_sellingEdit_dateChanged(const QDate &date);

    void on_releaseEdit_dateChanged(const QDate &date);

private:
    Ui::bookingRoom *ui;
    Room *r;
    User *u;
    std::vector<BookedRoom> *bkdRoom;
};

#endif // BOOKINGROOM_HPP
