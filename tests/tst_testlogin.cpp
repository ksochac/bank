#include <QtTest>

#include <headers/login.h>

class testLogin : public QObject
{
    Q_OBJECT

public:
    testLogin();
    ~testLogin();

private slots:
    void test_setpin1();
    void test_setpin2();
    void test_setusername1();
    void test_setusername2();
    void test_setusername3();
    void test_loguserin1();
    void test_loguserin2();
    void test_loguserin3();

};

testLogin::testLogin()
{

}

testLogin::~testLogin()
{

}

void testLogin::test_setpin1()
{
    Login login;
    QCOMPARE(login.setpin("1234"), true);
}

void testLogin::test_setpin2()
{
    Login login;
    QCOMPARE(login.setpin("12345"), false);
}

void testLogin::test_setusername1()
{
    Login login;
    QCOMPARE(login.setusername("mail@host.com"), true);
}

void testLogin::test_setusername2()
{
    Login login;
    QCOMPARE(login.setusername("mailhost.com"), false);
}

void testLogin::test_setusername3()
{
    Login login;
    QCOMPARE(login.setusername("mail@hostcom"), false);
}

void testLogin::test_loguserin1()
{
    Login login;
    QCOMPARE(login.loguserin("1234","martinszafarczyk@gmail.com"), true);
}

void testLogin::test_loguserin2()
{
    Login login;
    QCOMPARE(login.loguserin("1235","martinszafarczyk@gmail.com"), false);
}

void testLogin::test_loguserin3()
{
    Login login;
    QCOMPARE(login.loguserin("1234","martinszafarczyk1@gmail.com"), false);
}


QTEST_APPLESS_MAIN(testLogin)

#include "tst_testlogin.moc"
