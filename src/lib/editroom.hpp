#ifndef EDITROOM_H
#define EDITROOM_H

#include <QDialog>
#include "room.hpp"
#include "user.hpp"

namespace Ui {
class CreateRoom;
}

class CreateRoom : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRoom(QWidget *parent = nullptr);
    ~CreateRoom();
    void setRoom(Room *room);
    void setTitle(QString title);
    QString comfortConvert(int comfort);

private slots:
    void accept();

private:
    Ui::CreateRoom *ui;
    Room *r;
};

#endif // EDITROOM_H
