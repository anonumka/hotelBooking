/*!
 * \file
 * \brief Тесты для операций с комнатами
 */
#include <memory>
#include <QtTest>
#include <QCoreApplication>
#include <QMessageBox>

#include "../../lib/editroom.hpp"

/*!
 * \brief Класс с тестами для класса EditRoom
 */

class tst_OperationWithRooms : public QObject
{
    Q_OBJECT

public:
    tst_OperationWithRooms();
    ~tst_OperationWithRooms();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_emptyRoom_data();
    void test_emptyRoom();
    void testEditRoom_data();
    void testEditRoom();

private:
    std::unique_ptr<EditRoom> m_dlg;
};

void tst_OperationWithRooms::initTestCase()
{
    m_dlg.reset(new EditRoom);
}

void tst_OperationWithRooms::cleanupTestCase()
{
    m_dlg.reset();
}

void tst_OperationWithRooms::test_emptyRoom_data()
{
    QTest::addColumn<int>("num");
    QTest::addColumn<int>("capacity");
    QTest::addColumn<QString>("comfort");
    QTest::addColumn<int>("price");

    QTest::newRow("empty num") << NULL << 1 << "Luxe" << 1000;
    QTest::newRow("empty capacity") << 101 << NULL << "Luxe" << 1000;
    QTest::newRow("empty comfort") << 101 << 1 << "" << 1000;
    QTest::newRow("empty price") << 101 << 1 << "Luxe" << NULL;
}

void tst_OperationWithRooms::test_emptyRoom()
{
    //test empty room
    QFETCH(int, num);
    QFETCH(int, capacity);
    QFETCH(QString, comfort);
    QFETCH(int, price);
    Room room;
    m_dlg->setRoom(&room);
    QSignalSpy spy(m_dlg.get(), &EditRoom::accepted);
    m_dlg->setRoomNum(num);
    m_dlg->setRoomCapacity(capacity);
    m_dlg->setRoomComfort(comfort);
    m_dlg->setRoomPrice(price);
    m_dlg->open();
    QTimer::singleShot(0, [=]()
    {
        QMessageBox *box = dynamic_cast<QMessageBox *>(QApplication::activeModalWidget());
        box->accept();
        m_dlg->reject();
    });
    m_dlg->accept();
    QVERIFY2(spy.count() == 0, "Incorrect (NULL value) room accepted");
}

void tst_OperationWithRooms::testEditRoom_data()
{
    QTest::addColumn<int>("num1");
    QTest::addColumn<int>("capacity");
    QTest::addColumn<int>("price");

    QTest::newRow("busy num room") << 102 << 5 << 1000;
    QTest::newRow("error num") << -105 << 5 << 1000;
    QTest::newRow("error capacity") << 101 << 64 << 1000;
    QTest::newRow("error price") << 101 << 5 << -655;
}

void tst_OperationWithRooms::testEditRoom()
{
    QFETCH(int, num1);
    QFETCH(int, capacity);
    QFETCH(int, price);

    Room room1;
    m_dlg->setRoom(&room1);
    QSignalSpy spy(m_dlg.get(), &EditRoom::accepted);
    m_dlg->setRoomNum(num1);
    m_dlg->setRoomCapacity(capacity);
    m_dlg->setRoomComfort(QString("Luxe"));
    m_dlg->setRoomPrice(price);
    m_dlg->setNumOtherRoom(102);
    m_dlg->open();
    QTimer::singleShot(0, [=]()
    {
        QMessageBox *box = dynamic_cast<QMessageBox *>(QApplication::activeModalWidget());
        box->accept();
        m_dlg->reject();
    });
    m_dlg->accept();
    QVERIFY2(spy.count() == 0, "Incorrect (wrong value for lines) room accepted");
}

tst_OperationWithRooms::tst_OperationWithRooms()
{

}

tst_OperationWithRooms::~tst_OperationWithRooms()
{

}

QTEST_MAIN(tst_OperationWithRooms)

#include "tst_tst_operationwithrooms.moc"
