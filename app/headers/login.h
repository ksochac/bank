#ifndef LOGIN_H
#define LOGIN_H
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "database.h"
#include "session.h"

class Login:public QObject{

    Q_OBJECT

    Q_PROPERTY(QString pin READ getpin WRITE setpin NOTIFY pinChanged);
    Q_PROPERTY(QString username READ getusername WRITE setusername NOTIFY usernameChanged);
    Q_PROPERTY(QString loginerror READ getloginerror NOTIFY loginerrorChanged);


public:
    explicit Login(Session *session=nullptr,QObject *parent = nullptr);
    ~Login();
public:
    Q_INVOKABLE bool loguserin(const QString &pin,const QString &username);

public slots:
    QString getpin()const{return pin;};
    QString getusername()const{return username;};
    QString getloginerror()const{return loginerror;}
    bool setusername(const QString &name);
    bool setpin(const QString &newpin);
signals:
    void loginerrorChanged();
    void usernameChanged();
    void pinChanged();
private:
    Session *startsession;
    Data_base *client_db;
    QString clientid;
    QString pin;
    QString loginerror;
    QString username;



};


#endif // LOGIN_H
