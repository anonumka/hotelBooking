#ifndef EDITROOM_H
#define EDITROOM_H

#include <QDialog>
#include "room.hpp"
#include "user.hpp"

namespace Ui {
class EditRoom;
}

class EditRoom : public QDialog
{
    Q_OBJECT

public:
    explicit EditRoom(QWidget *parent = nullptr);
    ~EditRoom();
    void setRoom(Room *room);
    void setTitle(QString title);
    QString comfortConvert(int comfort);

private slots:
    void accept();

private:
    Ui::EditRoom *ui;
    Room *r;
};

#endif // EDITROOM_H
