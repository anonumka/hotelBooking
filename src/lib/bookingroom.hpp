#ifndef BOOKINGROOM_HPP
#define BOOKINGROOM_HPP

#include <QDialog>
#include "room.hpp"
#include "user.hpp"

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
    void setUsers(std::vector<User> *vU, int index);
    void check_price();

private slots:
    void accept();

    void on_comboBox_currentIndexChanged(int index);

    void on_sellingEdit_dateChanged(const QDate &date);

    void on_releaseEdit_dateChanged(const QDate &date);

private:
    Ui::bookingRoom *ui;
    Room *r;
    std::vector<User> *vUsers;
};

#endif // BOOKINGROOM_HPP
