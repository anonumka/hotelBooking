#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "roomtable.hpp"
#include "editroom.hpp"
#include "recordingusers.hpp"

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
    void save_vrooms();
    void load_vrooms();
    void save_vusers();
    void load_vusers();
    void save_users();
    void load_users();
    void displayTable(RoomTable *rt);
    void addRoom(const Room &r);
    void setvroom(RoomTable *vRooms);
public slots:
    void updateDisplayedValues();
    void create_room();
    void edit_room();
    void list_user();
    void booking_room(const QModelIndex &idx);

    void saveRoomsTable();
    void openRoomsTable();
    void saveUsers();
    void openUsers();

    void ImportRoomsCSV();
    void ExportRoomsCSV();
    void ImportUsersCSV();
    void ExportUsersCSV();

    void registerUser();
    void authUser();
    void windowAbout();
    void exit();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<RoomTable> vRoom;
    std::vector<User> vUsers;

    int role;
    int index;

};
#endif // MAINWINDOW_HPP
