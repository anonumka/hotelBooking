#ifndef RECORDINGUSERS_HPP
#define RECORDINGUSERS_HPP

#include <QDialog>
#include "user.hpp"
#include "bookedroom.hpp"

namespace Ui {
class RecordingUsers;
}

class RecordingUsers : public QDialog
{
    Q_OBJECT

public:
    explicit RecordingUsers(QWidget *parent = nullptr);
    ~RecordingUsers();
    void setUser(User *u);
    void setbkdRoom(BookedRoom *bkdr);

private slots:
    void accept();

private:
    Ui::RecordingUsers *ui;
    User *user;
    BookedRoom *bkd;
};

#endif // RECORDINGUSERS_HPP
