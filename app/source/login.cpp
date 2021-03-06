#include "headers/login.h"

// sets the first data visible to the user
Login::Login(Session *msession,QObject *parent):
    QObject(parent),
    clientid(""),
    startsession(msession),
    client_db(&Data_base::get_instance() ),
    pin("pin"),
    username("martinszafarczyk@gmail.com")
{
}

Login::~Login()
{
   // delete client_db; changed database to Singelton, deleted "delte" method

}

//  sets the pin given by the user
bool Login::setpin(const QString &mpin)
{    

    if(mpin.length()==4)
    {
        pin=mpin;
        emit pinChanged();
        return true;
    }
    else{
        pin=mpin;
        emit pinChanged();
        loginerror="Pin must have 4 digits";
        emit loginerrorChanged();
        return false;
    }
}

// sets the username inputed by the user of the app
bool Login::setusername(const QString &musername){

    loginerror.clear();
     username=musername;
        emit loginerrorChanged();
    bool contains_at,contains_dot=false;
    for(int i =0;i<musername.length();i++)
    {
        if(musername[i]=='.' && contains_at)contains_dot=true;
        if(musername[i]=='@')contains_at=true;
    }
    if(!contains_at || !contains_dot){
        loginerror+="Email is incorret";
                emit loginerrorChanged();
        return false;
    }
    else {
        return true;
    }
}

// logs the user into the session
bool Login::loguserin(const QString &mpin,const QString &musername)
{
    qDebug()<<"username:"<<musername<<" pin :"<<mpin;
    if(setusername(musername) && setpin(mpin) && client_db->validet_user(musername,mpin,clientid)){
        startsession->client_id=clientid;
        startsession->settransfers();

        return true;
    }

    else{
        loginerror="Wrong pin or username";
        emit loginerrorChanged();
        return false ;
    }
}













