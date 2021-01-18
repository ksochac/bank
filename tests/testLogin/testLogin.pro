

QT += testlib
QT -= gui
QT +=qml
QT += quick
QT += sql
QT += core
QT += widgets

CONFIG += c++11

RESOURCES += $$TOP_PWD/app/qml.qrc



CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += tst_testlogin.cpp \
        $$TOP_PWD/app/source/login.cpp \
        $$TOP_PWD/app/source/database.cpp \
        $$TOP_PWD/app/source/session.cpp \
        $$TOP_PWD/app/source/transfer.cpp \
        $$TOP_PWD/app/source/formfactory.cpp \
        $$TOP_PWD/app/source/form.cpp \
        $$TOP_PWD/app/source/register.cpp \
        $$TOP_PWD/app/source/transfer_list.cpp \


HEADERS += $$TOP_PWD/app/headers/login.h \
           $$TOP_PWD/app/headers/database.h \
           $$TOP_PWD/app/headers/session.h \
           $$TOP_PWD/app/headers/form.h \
           $$TOP_PWD/app/headers/formfactory.h \
           $$TOP_PWD/app/headers/register.h \
           $$TOP_PWD/app/headers/transfer_list.h \
           $$TOP_PWD/app/headers/transfer.h

INCLUDEPATH += $$TOP_PWD/app/


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
