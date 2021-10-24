#ifndef AUTH_HPP
#define AUTH_HPP

#include <QDialog>
#include <user.hpp>

namespace Ui {
class auth;
}

class auth : public QDialog
{
    Q_OBJECT

public:
    explicit auth(QWidget *parent = nullptr);
    ~auth();
    void setUsers(std::vector<User> *vU);

private slots:
    void accept();

    void on_pushButton_clicked();

private:
    Ui::auth *ui;
    std::vector<User> *vUsers;
};

#endif // AUTH_HPP
