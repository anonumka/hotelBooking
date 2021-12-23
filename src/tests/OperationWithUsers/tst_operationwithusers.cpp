/*!
 * \file
 * \brief Тесты для операций с пользователями
 */
#include <memory>
#include <QtTest>
#include <QCoreApplication>
#include <QMessageBox>

#include "../../lib/recordingusers.hpp"
#include "../../lib/bookedroom.hpp"

/*!
 * \brief Класс с тестами для класса RecordingUsers
 */

class operationwithusers : public QObject
{
    Q_OBJECT

public:
    operationwithusers();
    ~operationwithusers();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_correctInputUser_data();
    void test_correctInputUser();
private:
    std::unique_ptr<RecordingUsers> m_dlg;
};

void operationwithusers::initTestCase()
{
    m_dlg.reset(new RecordingUsers);
}

void operationwithusers::cleanupTestCase()
{
    m_dlg.reset();
}

void operationwithusers::test_correctInputUser_data()
{
    QTest::addColumn<QString>("surname");
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("patronymic");
    QTest::addColumn<QString>("series");
    QTest::addColumn<QString>("city");

    //Проверка на пустую комнату
    QTest::newRow("empty surname") << "" << "Denis" << "Aleksandrovich" << "0415123456" << "Achinsk";
    QTest::newRow("empty name") << "Antsiferov" << "" << "Aleksandrovich" << "0415123456" << "Achinsk";
    QTest::newRow("empty patronymic") << "Antsiferov" << "Denis" << "" << "0415123456" << "Achinsk";
    QTest::newRow("empty series") << "Antsiferov" << "Denis" << "Aleksandrovich" << "" << "Achinsk";
    QTest::newRow("empty city") << "Antsiferov" << "Denis" << "Aleksandrovich" << "0415123456" << "";

    //Проверка на правильность введеных данных
    QTest::newRow("busy series") << "Antsiferov" << "Denis" << "Aleksandrovich" << "0415123457" << "Achinsk";
    QTest::newRow("few series") <<  "Antsiferov" << "Denis" << "Aleksandrovich" << "041512345" << "Achinsk";
    QTest::newRow("long series") << "Antsiferov" << "Denis" << "Aleksandrovich" << "04151234567" << "Achinsk";
    QTest::newRow("without digits series") << "Antsiferov" << "Denis" << "Aleksandrovich" << "abcdabcdab" << "Achinsk";
}

void operationwithusers::test_correctInputUser()
{
    QFETCH(QString, surname);
    QFETCH(QString, name);
    QFETCH(QString, patronymic);
    QFETCH(QString, series);
    QFETCH(QString, city);
    User user;
    m_dlg->setUser(&user);
    QSignalSpy spy(m_dlg.get(), &RecordingUsers::accepted);
    m_dlg->setSurname(surname);
    m_dlg->setName(name);
    m_dlg->setPatronymic(patronymic);
    m_dlg->setSeriesNumPassport(series);
    m_dlg->setCity(city);
    m_dlg->setSeriesOtherUser("0415123457");
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

operationwithusers::operationwithusers()
{

}

operationwithusers::~operationwithusers()
{

}

QTEST_MAIN(operationwithusers)

#include "tst_operationwithusers.moc"
