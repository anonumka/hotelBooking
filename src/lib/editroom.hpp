#ifndef EDITROOM_H
#define EDITROOM_H

#include <QDialog>
#include "room.hpp"
#include "user.hpp"
#include "roomtable.hpp"

namespace Ui {
class EditRoom;
}

class EditRoom : public QDialog
{
    Q_OBJECT

public:
    explicit EditRoom(QWidget *parent = 0);
    ~EditRoom();
    void setRoomNum(int num);
    void setRoomCapacity(int capacity);
    void setRoomComfort(QString comfort);
    void setRoomPrice(int price);
    void setNumOtherRoom(int num);
    void setNumsVector(std::vector<int> vNums_);
    void setRoom(Room *room);
    void setTitle(QString title);
    QString comfortConvert(int comfort);

public slots:
    void accept() Q_DECL_OVERRIDE;

private:
    Ui::EditRoom *ui;
    Room *r;
    std::vector<int> vNums;
};

#endif // EDITROOM_H
