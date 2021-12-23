/*!
 * \file
 * \brief Файл реализация главного окна
 *
 * Данное окно вляется общим для всех пользователей.
 */
#include <QFileDialog>
#include <QSaveFile>
#include <QDate>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>
#include <set>

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->hotelView->horizontalHeader()->setStretchLastSection(true);
    ui->hotelView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->hotelView->setSelectionMode(QAbstractItemView::SingleSelection);

    db.load();
    vRooms = db.getRoomTable();
    vUsers = db.getUsers();
    bkdRoom = db.getBookedRooms();

    index = authorisation();
    refreshTableRooms();

    auto updateTimer = new QTimer;
    updateTimer->setInterval(15000);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedValues()));
    updateTimer->start(100);

    setFixedSize(568, 460);
}

void MainWindow::updateDisplayedValues()
{
    if (index == -1)
        exit();

    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());

    for (size_t i = 0; i < bkdRoom->size(); i++)
    {
        if (bkdRoom->at(i).getDateRelease() < QDate::currentDate())
        {
            bkdRoom->at(i).setRoom(0);
            bkdRoom->at(i).setDateSettling(1, 1, 2000);
            bkdRoom->at(i).setDateRelease(1, 1, 2000);
        }
    }

    if (!ui->hotelView->selectionModel()->hasSelection())
    {
        ui->bookingButton->setEnabled(false);
    }
    else
    {
        ui->bookingButton->setEnabled(true);
    }

    if (db.checkAvailablesRooms()) {
        refreshTableRooms();
    }
}

void MainWindow::addColumns()
{
    roomsModel = new QStandardItemModel(ui->hotelView);
    roomsModel->setHorizontalHeaderLabels(QStringList() << "Номер" << "Вместимость" << "Комфорт" << "Цена" << "Доступность" );
    ui->hotelView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->hotelView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->hotelView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->hotelView->horizontalHeader()->setStretchLastSection(true);
    ui->hotelView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->hotelView->setModel(roomsModel);
}

void MainWindow::refreshTableRooms()
{
    addColumns();
    for (size_t i = 0; i < vRooms->size(); i++) {
        QList<QStandardItem *> standardItemsList = db.getDataRooms(i);
        roomsModel->insertRow(roomsModel->rowCount(), standardItemsList);
    }
}

MainWindow::~MainWindow()
{
    db.saveRoomsTable();
    db.saveUsers();
    db.saveBookedRoom();
    delete ui;
}

void MainWindow::setEnableActionsUi (int role)
{
    ui->actionAddRoom->setEnabled(role);
    ui->actionEditRoom->setEnabled(role);
    ui->actionDelete_Room->setEnabled(role);
    ui->actionListUsers->setEnabled(role);

    if (role) {
        ui->bookingButton->setText("Список забронировавших комнату");
    }

    ui->actionExportRooms->setEnabled(role == 2);
    ui->actionExportUsers->setEnabled(role == 2);
    ui->actionImportRooms->setEnabled(role == 2);
    ui->actionImportUsers->setEnabled(role == 2);
    ui->actionBooked_Rooms->setEnabled(role == 2);
    ui->actionBooked_Rooms_2->setEnabled(role == 2);
}

int MainWindow::authorisation()
{
    Auth au;
    au.setUsers(vUsers);
    au.setWindowTitle(config::applicationName);
    size_t i = 0;
    if (au.exec() != Auth::Accepted) { return -1; }

    for (i = 0; i < vUsers->size(); i++)
        if (vUsers->at(i).getSelect())
        {
            break;
        }

    if (i == vUsers->size())
    {
        return -1;
    }

    if (vUsers->size() == 1 && vUsers->at(0).getRole() == 0)
    {
        QMessageBox::information(this, config::applicationName, QString("Добро пожаловать в информационную систему %1."
                                                                "\n\nВы являетесь первым зарегистрированным пользователем"
                                                                ", поэтому вы наделены правами администратора!"
                                                                "\n\nПри возникновении проблем, обращайтесь к создателю. "
                                                                "Ссылку на почту можно найти в Help->About.")
                                                                .arg(config::applicationName));
        vUsers->at(0).setRole(2);
    }

    role = vUsers->at(i).getRole();
    setEnableActionsUi(role);

    return i;
}

void MainWindow::addRoom(const Room &r)
{
    db.addRoom(r);
}

void MainWindow::addUser(User u)
{
    db.addUser(u);
}

void MainWindow::create_room()
{
    Room r;
    EditRoom cr;
    cr.setRoom(&r);
    cr.setWindowTitle(config::applicationName);
    cr.setTitle("Room creator: ");
    if (cr.exec() != EditRoom::Accepted)
    {
        return;
    }

    if (db.checkBusyNumOfRoom(r.getNum()))
    {
        QMessageBox::warning(0, config::applicationName, "Комната с таким номером занята.");
        return;
    }
    addRoom(r);
    refreshTableRooms();
}

void MainWindow::edit_room()
{
    if (!ui->hotelView->selectionModel()->hasSelection())
    {
        QMessageBox::warning(this, config::applicationName, "Выберите комнату в таблице.");
        return;
    }

    QModelIndexList selection = ui->hotelView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    size_t ind = index.row();

    Room r = vRooms->at(ind);
    EditRoom er;
    er.setRoom(&r);
    er.setWindowTitle(config::applicationName);
    er.setTitle("Room editor: ");
    if (er.exec() != EditRoom::Accepted) return;

    if (db.checkBusyNumOfRoom(r.getNum()))
    {
        QMessageBox::warning(0, config::applicationName, "Комната с таким номером занята.");
        return;
    }
    db.refreshDataRoom(r, ind);
    refreshTableRooms();
}

void MainWindow::del_room()
{
    if (!ui->hotelView->selectionModel()->hasSelection())
    {
        QMessageBox::warning(this, config::applicationName, "Выберите комнату в таблице.");
        return;
    }

    QModelIndexList selection = ui->hotelView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    size_t ind = index.row();

    Room r = vRooms->at(ind);
    int num = r.getNum();
    int count = 0;
    for (size_t i = 0; i < bkdRoom->size(); i++)
    {
        if (num == bkdRoom->at(i).getRoom()) { count++; }
    }
    if (count != 0)
        if (QMessageBox::question(this, config::applicationName,
                                        tr("%1 пользователей забронировали комнату.\n"
                                        "Вы серьезно хотите удалить эту комнату?").arg(count))
                                        == QMessageBox::No)
        { return; }

    db.delRoom(ind);
    refreshTableRooms();
}

void MainWindow::list_user()
{
    ListUsers lu;
    lu.setUsers(vUsers);
    lu.setBkdRooms(bkdRoom);
    lu.setWindowTitle("List Users");
    lu.exec();
}

void MainWindow::listUsersBookedRoom(size_t& ind)
{
    QDialog *listbkdroom = new QDialog;
    Ui::Dialog ui_listbkdroom;
    listbkdroom->setFixedSize(452, 327);

    ui_listbkdroom.setupUi(listbkdroom);
    listbkdroom->setWindowTitle(config::applicationName);
    Room r = vRooms->at(ind);
    int num = r.getNum();
    ui_listbkdroom.label->setText(QString("Комната %1").arg(num));

    QStandardItemModel *bkrModel = new QStandardItemModel(this);
    bkrModel->setColumnCount(3);
    bkrModel->setHorizontalHeaderLabels(QStringList() << "Фамилия" << "Паспорт"
                                        << "Дата заселения" << "Дата выселения");
    ui_listbkdroom.tableView->setModel(bkrModel);
    ui_listbkdroom.tableView->horizontalHeader()->setStretchLastSection(true);
    ui_listbkdroom.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui_listbkdroom.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui_listbkdroom.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (size_t i = 0; i < bkdRoom->size(); ++i)
    {
        if (bkdRoom->at(i).getRoom() == num)
        {
            QList<QStandardItem *> standardItemsList;
            BookedRoom bkdr = bkdRoom->at(i);
            User u;
            for (size_t j = 0; j < vUsers->size(); i++)
            {
                if (bkdr.getSeries() == vUsers->at(i).getSeries())
                {
                    u = vUsers->at(i);
                    break;
                }
            }
            standardItemsList.append(new QStandardItem(u.getSurname()));
            standardItemsList.append(new QStandardItem(bkdr.getSeries()));
            standardItemsList.append(new QStandardItem(bkdr.getDateSettling().toString()));
            standardItemsList.append(new QStandardItem(bkdr.getDateRelease().toString()));
            bkrModel->insertRow(bkrModel->rowCount(), standardItemsList);
        }
    }
    if (!(bkrModel->rowCount()))
    {
        QMessageBox::information(this, config::applicationName, "Комната пустая!");
        return;
    }
    ui_listbkdroom.label_2->setText(QString("Свободных мест: %1").arg(r.getCapacity()
                                    - bkrModel->rowCount()));
    listbkdroom->exec();
}

void MainWindow::booking_room()
{
    if (!ui->hotelView->selectionModel()->hasSelection()) {
        QMessageBox::warning(this, config::applicationName, "Выберите комнату в таблице.");
        return;
    }

    QModelIndexList selection = ui->hotelView->selectionModel()->selectedRows();
    QModelIndex idx = selection.at(0);
    size_t ind = idx.row();

    if (role) {
        listUsersBookedRoom(ind);
        return;
    }

    Room r = vRooms->at(ind);
    BookedRoom bkr;
    bookingRoom br;
    br.setRoom(&r);
    br.setUser(&vUsers->at(index));
    br.setBkdroom(bkdRoom);
    br.setWindowTitle(config::applicationName);
    if (br.exec() != bookingRoom::Accepted) {
        return;
    }
    db.addBookedRoom(bkr);
    refreshTableRooms();
}

void MainWindow::exportRoomsCSV()
{
    db.exportRoomsCSV();
}

void MainWindow::importRoomsCSV()
{
    vRooms = db.importRoomsCSV();
    refreshTableRooms();
}

void MainWindow::exportUsersCSV()
{
    db.exportUsersCSV();
}

void MainWindow::importUsersCSV()
{
    vUsers = db.importUsersCSV();
}

void MainWindow::exportBookedRoomCSV()
{
    db.exportBookedRoomCSV();
}

void MainWindow::importBookedRoomCSV()
{
    bkdRoom = db.importBookedRoomCSV();
}

void MainWindow::authUser()
{
    vUsers->at(index).setSelect(false);
    int tmp = authorisation();
    if (tmp != -1)
    {
        index = tmp;
    }
    else
    {
        role = vUsers->at(index).getRole();
    }
}

void MainWindow::windowAbout()
{
    QMessageBox about(this);
    about.setIcon(QMessageBox::Information);
    about.setWindowTitle(QString("About %1").arg(config::applicationName));
    about.setText(QString("%1<br>"
        "Author: <a href=\"mailto:cergeu912@gmail.com\">Antsiferov Denis Aleksandrovich</a><br>"
        "Github: <a href=\"https://github.com/anonumka/hotelBooking\">*click*</a><br>"
        "Icons by <a href=\"http://tango.freedesktop.org/"
        "Tango_Desktop_Project\">The Tango! Desktop Project</a><br>"
        "Version %1: %2<br> Version QT: %3")
                  .arg(config::applicationName).arg(config::applicationVersion).arg(qVersion()));
    about.exec();
}

void MainWindow::exit()
{
    MainWindow::close();
}

