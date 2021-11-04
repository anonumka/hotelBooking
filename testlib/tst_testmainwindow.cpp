#include <QtTest>

// add necessary includes here

class testMainWindow : public QObject
{
    Q_OBJECT

public:
    testMainWindow();
    ~testMainWindow();

private slots:
    void test_case1();
    //void test_case2();
    //void test_case3();
    //void test_case4();
    //void test_case5();
    //void test_case6();

};

testMainWindow::testMainWindow()
{
}

testMainWindow::~testMainWindow()
{
}

void testMainWindow::test_case1()
{

}

QTEST_APPLESS_MAIN(testMainWindow)

#include "tst_testmainwindow.moc"
