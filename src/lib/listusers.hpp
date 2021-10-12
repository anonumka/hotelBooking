#ifndef LISTUSERS_HPP
#define LISTUSERS_HPP

#include <QDialog>
#include "user.hpp"
#include "bookedroom.hpp"

namespace Ui {
class ListUsers;
}

class ListUsers : public QDialog
{
    Q_OBJECT

public:
    explicit ListUsers(QWidget *parent = nullptr);
    ~ListUsers();
    void setUsers(std::vector<User> *vU);
    void setBkdRooms(std::vector<BookedRoom> *bkdr);

private slots:
    void on_comboBox_activated(int index);

    void accept();

    void on_resetBtn_clicked();

private:
    Ui::ListUsers *ui;
    std::vector<User> *vUsers;
    std::vector<BookedRoom> *bkdRoom;
    int role;
};

#endif // LISTUSERS_HPP
