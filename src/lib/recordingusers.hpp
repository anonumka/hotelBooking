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

    void setSurname(QString surname);
    void setName(QString name);
    void setPatronymic(QString patronymic);
    void setSeriesNumPassport(QString series);
    void setCity(QString city);
    void setSeriesOtherUser(QString series);
    void setBusySeriesUsers(std::vector<QString> BusySeries);

private slots:

public slots:
    void accept();

private:
    Ui::RecordingUsers *ui;
    User *user;
    BookedRoom *bkd;
    std::vector<QString> vNums;
};

#endif // RECORDINGUSERS_HPP
