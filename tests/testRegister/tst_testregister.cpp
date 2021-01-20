#include <QtTest>

#include <headers/register.h>

class testRegister : public QObject
{
    Q_OBJECT

public:
    testRegister();
    ~testRegister();


private slots:
    void test_testValidate_email1();
    void test_testValidate_email2();
    void test_testValidate_email3();

    void test_testValidate_pin1();
    void test_testValidate_pin2();
    void test_testValidate_pin3();

    void test_testValidate_password1();
    void test_testValidate_password2();
    void test_testValidate_password3();
    void test_testValidate_password4();
    void test_testValidate_password5();




};

testRegister::testRegister()
{

}

testRegister::~testRegister()
{

}

Register reg("test");
void testRegister::test_testValidate_email1()
{
    QCOMPARE(reg.validate_email("martinszafarczyk@gmail.com"), true);
}

void testRegister::test_testValidate_email2()
{
    QCOMPARE(reg.validate_email("martinszafarczykgmail.com"), false);
}

void testRegister::test_testValidate_email3()
{
    QCOMPARE(reg.validate_email("martin@szafarczykgmailcom"), false);
}

void testRegister::test_testValidate_pin1()
{
    QCOMPARE(reg.validate_email("1234"), true);
}

void testRegister::test_testValidate_pin2()
{
    QCOMPARE(reg.validate_email("12345"), false);
}

void testRegister::test_testValidate_pin3()
{
    QCOMPARE(reg.validate_email("abcd"), false);
}

void testRegister::test_testValidate_password1()
{
    QCOMPARE(reg.validate_password("a1b2c3d4!"), true);
}

void testRegister::test_testValidate_password2()
{
    QCOMPARE(reg.validate_password("a1b2c3d4"), false);
}

void testRegister::test_testValidate_password3()
{
    QCOMPARE(reg.validate_password("a1b2c3!"), false);
}

void testRegister::test_testValidate_password4()
{
    QCOMPARE(reg.validate_password("abcdefghijklmn"), false);
}

void testRegister::test_testValidate_password5()
{
    QCOMPARE(reg.validate_password("123456789!"), false);
}



QTEST_APPLESS_MAIN(testRegister)

#include "tst_testregister.moc"
