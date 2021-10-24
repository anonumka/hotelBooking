#ifndef LISTUSERS_HPP
#define LISTUSERS_HPP

#include <QDialog>
#include "user.hpp"

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

private slots:
    void on_comboBox_activated(int index);

    void accept();

    void on_resetBtn_clicked();

private:
    Ui::ListUsers *ui;
    std::vector<User> *vUsers;
    int role;
};

#endif // LISTUSERS_HPP
