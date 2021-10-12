#ifndef RECORDINGUSERS_HPP
#define RECORDINGUSERS_HPP

#include <QDialog>
#include "user.hpp"

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

private slots:
    void accept();

private:
    Ui::RecordingUsers *ui;
    User *user;
};

#endif // RECORDINGUSERS_HPP
