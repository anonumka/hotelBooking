/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAddRoom;
    QAction *actionAbout;
    QAction *actionEditRoom;
    QAction *actionListUsers;
    QAction *actionAuth;
    QAction *actionImportRooms;
    QAction *actionImportUsers;
    QAction *actionExportRooms;
    QAction *actionExportUsers;
    QAction *actionBooked_Rooms;
    QAction *actionBooked_Rooms_2;
    QAction *actionDelete_Room;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *AddRoomBtn;
    QPushButton *EditRoomBtn;
    QLabel *label;
    QLabel *label_2;
    QTableView *hotelView;
    QPushButton *DelRoomBtn;
    QMenuBar *menubar;
    QMenu *menuFIle;
    QMenu *menuImport_CSV;
    QMenu *menuExport_CSV;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuEdit_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(568, 453);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAddRoom = new QAction(MainWindow);
        actionAddRoom->setObjectName(QString::fromUtf8("actionAddRoom"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionEditRoom = new QAction(MainWindow);
        actionEditRoom->setObjectName(QString::fromUtf8("actionEditRoom"));
        actionListUsers = new QAction(MainWindow);
        actionListUsers->setObjectName(QString::fromUtf8("actionListUsers"));
        actionAuth = new QAction(MainWindow);
        actionAuth->setObjectName(QString::fromUtf8("actionAuth"));
        actionImportRooms = new QAction(MainWindow);
        actionImportRooms->setObjectName(QString::fromUtf8("actionImportRooms"));
        actionImportUsers = new QAction(MainWindow);
        actionImportUsers->setObjectName(QString::fromUtf8("actionImportUsers"));
        actionExportRooms = new QAction(MainWindow);
        actionExportRooms->setObjectName(QString::fromUtf8("actionExportRooms"));
        actionExportUsers = new QAction(MainWindow);
        actionExportUsers->setObjectName(QString::fromUtf8("actionExportUsers"));
        actionBooked_Rooms = new QAction(MainWindow);
        actionBooked_Rooms->setObjectName(QString::fromUtf8("actionBooked_Rooms"));
        actionBooked_Rooms_2 = new QAction(MainWindow);
        actionBooked_Rooms_2->setObjectName(QString::fromUtf8("actionBooked_Rooms_2"));
        actionDelete_Room = new QAction(MainWindow);
        actionDelete_Room->setObjectName(QString::fromUtf8("actionDelete_Room"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 549, 411));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        dateTimeEdit = new QDateTimeEdit(gridLayoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setWrapping(false);
        dateTimeEdit->setFrame(true);
        dateTimeEdit->setReadOnly(true);

        gridLayout->addWidget(dateTimeEdit, 0, 3, 1, 1);

        AddRoomBtn = new QPushButton(gridLayoutWidget);
        AddRoomBtn->setObjectName(QString::fromUtf8("AddRoomBtn"));
        AddRoomBtn->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddRoomBtn->sizePolicy().hasHeightForWidth());
        AddRoomBtn->setSizePolicy(sizePolicy1);
        AddRoomBtn->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/List-add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AddRoomBtn->setIcon(icon);

        gridLayout->addWidget(AddRoomBtn, 2, 1, 1, 1);

        EditRoomBtn = new QPushButton(gridLayoutWidget);
        EditRoomBtn->setObjectName(QString::fromUtf8("EditRoomBtn"));
        EditRoomBtn->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Edit-find-replace.svg"), QSize(), QIcon::Normal, QIcon::Off);
        EditRoomBtn->setIcon(icon1);

        gridLayout->addWidget(EditRoomBtn, 2, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        hotelView = new QTableView(gridLayoutWidget);
        hotelView->setObjectName(QString::fromUtf8("hotelView"));
        hotelView->setGridStyle(Qt::NoPen);

        gridLayout->addWidget(hotelView, 1, 0, 1, 4);

        DelRoomBtn = new QPushButton(gridLayoutWidget);
        DelRoomBtn->setObjectName(QString::fromUtf8("DelRoomBtn"));
        DelRoomBtn->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/List-remove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        DelRoomBtn->setIcon(icon2);

        gridLayout->addWidget(DelRoomBtn, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 568, 20));
        menuFIle = new QMenu(menubar);
        menuFIle->setObjectName(QString::fromUtf8("menuFIle"));
        menuImport_CSV = new QMenu(menuFIle);
        menuImport_CSV->setObjectName(QString::fromUtf8("menuImport_CSV"));
        menuExport_CSV = new QMenu(menuFIle);
        menuExport_CSV->setObjectName(QString::fromUtf8("menuExport_CSV"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit_2 = new QMenu(menubar);
        menuEdit_2->setObjectName(QString::fromUtf8("menuEdit_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFIle->menuAction());
        menubar->addAction(menuEdit_2->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFIle->addSeparator();
        menuFIle->addAction(menuImport_CSV->menuAction());
        menuFIle->addAction(menuExport_CSV->menuAction());
        menuFIle->addSeparator();
        menuFIle->addAction(actionExit);
        menuImport_CSV->addAction(actionImportRooms);
        menuImport_CSV->addAction(actionImportUsers);
        menuImport_CSV->addAction(actionBooked_Rooms);
        menuExport_CSV->addAction(actionExportRooms);
        menuExport_CSV->addAction(actionExportUsers);
        menuExport_CSV->addAction(actionBooked_Rooms_2);
        menuEdit->addSeparator();
        menuEdit->addAction(actionListUsers);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAuth);
        menuHelp->addAction(actionAbout);
        menuEdit_2->addAction(actionAddRoom);
        menuEdit_2->addAction(actionEditRoom);
        menuEdit_2->addAction(actionDelete_Room);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(exit()));
        QObject::connect(actionAddRoom, SIGNAL(triggered()), MainWindow, SLOT(create_room()));
        QObject::connect(hotelView, SIGNAL(activated(QModelIndex)), MainWindow, SLOT(booking_room(QModelIndex)));
        QObject::connect(actionEditRoom, SIGNAL(triggered()), MainWindow, SLOT(edit_room()));
        QObject::connect(actionListUsers, SIGNAL(triggered()), MainWindow, SLOT(list_user()));
        QObject::connect(actionAuth, SIGNAL(triggered()), MainWindow, SLOT(authUser()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(windowAbout()));
        QObject::connect(actionImportRooms, SIGNAL(triggered()), MainWindow, SLOT(importRoomsCSV()));
        QObject::connect(actionExportRooms, SIGNAL(triggered()), MainWindow, SLOT(exportRoomsCSV()));
        QObject::connect(actionImportUsers, SIGNAL(triggered()), MainWindow, SLOT(importUsersCSV()));
        QObject::connect(actionExportUsers, SIGNAL(triggered()), MainWindow, SLOT(exportUsersCSV()));
        QObject::connect(actionBooked_Rooms, SIGNAL(triggered()), MainWindow, SLOT(importBookedRoomCSV()));
        QObject::connect(actionBooked_Rooms_2, SIGNAL(triggered()), MainWindow, SLOT(exportBookedRoomCSV()));
        QObject::connect(AddRoomBtn, &QPushButton::clicked, actionAddRoom, qOverload<>(&QAction::trigger));
        QObject::connect(EditRoomBtn, &QPushButton::clicked, actionEditRoom, qOverload<>(&QAction::trigger));
        QObject::connect(actionDelete_Room, SIGNAL(triggered()), MainWindow, SLOT(del_room()));
        QObject::connect(DelRoomBtn, &QPushButton::clicked, actionDelete_Room, qOverload<>(&QAction::trigger));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hotel Booking", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAddRoom->setText(QCoreApplication::translate("MainWindow", "Add Room", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionEditRoom->setText(QCoreApplication::translate("MainWindow", "Edit Room", nullptr));
        actionListUsers->setText(QCoreApplication::translate("MainWindow", "List Users", nullptr));
        actionAuth->setText(QCoreApplication::translate("MainWindow", "Auth", nullptr));
        actionImportRooms->setText(QCoreApplication::translate("MainWindow", "Rooms", nullptr));
        actionImportUsers->setText(QCoreApplication::translate("MainWindow", "Users", nullptr));
        actionExportRooms->setText(QCoreApplication::translate("MainWindow", "Rooms", nullptr));
        actionExportUsers->setText(QCoreApplication::translate("MainWindow", "Users", nullptr));
        actionBooked_Rooms->setText(QCoreApplication::translate("MainWindow", "Booked Rooms", nullptr));
        actionBooked_Rooms_2->setText(QCoreApplication::translate("MainWindow", "Booked Rooms", nullptr));
        actionDelete_Room->setText(QCoreApplication::translate("MainWindow", "Delete Room", nullptr));
#if QT_CONFIG(whatsthis)
        AddRoomBtn->setWhatsThis(QCoreApplication::translate("MainWindow", "Add Room", nullptr));
#endif // QT_CONFIG(whatsthis)
        AddRoomBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\274\320\275\320\260\321\202\321\203", nullptr));
#if QT_CONFIG(whatsthis)
        EditRoomBtn->setWhatsThis(QCoreApplication::translate("MainWindow", "Edit Room", nullptr));
#endif // QT_CONFIG(whatsthis)
        EditRoomBtn->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\276\320\274\320\275\320\260\321\202\321\203", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\275\320\260\321\202\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\262\321\200\320\265\320\274\321\217:", nullptr));
#if QT_CONFIG(whatsthis)
        DelRoomBtn->setWhatsThis(QCoreApplication::translate("MainWindow", "Delete Room", nullptr));
#endif // QT_CONFIG(whatsthis)
        DelRoomBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\276\320\274\320\275\320\260\321\202\321\203", nullptr));
        menuFIle->setTitle(QCoreApplication::translate("MainWindow", "FIle", nullptr));
        menuImport_CSV->setTitle(QCoreApplication::translate("MainWindow", "Import CSV", nullptr));
        menuExport_CSV->setTitle(QCoreApplication::translate("MainWindow", "Export CSV", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuEdit_2->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
