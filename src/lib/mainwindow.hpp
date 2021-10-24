#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "roomtable.hpp"
#include "editroom.hpp"
#include "recordingusers.hpp"
#include "bookedroom.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int authorisation();

    void listUsersBookedRoom(const QModelIndex &idx);
    void setEnableActionsUi (int role);
    void saveAllDataInRegistry();

    void saveUsers();
    void loadUsers();
    void saveRoomsTable();
    void loadRoomsTable();
    void saveBookedRoom();
    void loadBookedRoom();

    void addUser(User u);
    void addRoom(const Room &r);
    void setvroom(RoomTable *vRooms);
public slots:
    void updateDisplayedValues();

    void importRoomsCSV();
    void exportRoomsCSV();
    void importUsersCSV();
    void exportUsersCSV();
    void importBookedRoomCSV();
    void exportBookedRoomCSV();

    void create_room();
    void edit_room();
    void del_room();
    void booking_room(const QModelIndex &idx);

    void list_user();
    void authUser();

    void windowAbout();
    void exit();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<RoomTable> vRoom;
    std::vector<User> vUsers;
    std::vector<BookedRoom> bkdRoom;

    int role;
    int index;

};
#endif // MAINWINDOW_HPP
