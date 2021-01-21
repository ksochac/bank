#include "headers/formfactory.h"

// creeates form objects, and exposes them to the qmlengine and appengine
Form * FormFactory::CreateForm(QString qmlObjectName)
{
        if(!QmlEngine)
            return NULL;
        else{
            Form *form =new Form(nullptr,QmlEngine);
            appEngine->rootContext()->setContextProperty(qmlObjectName,form);
            return form;
        }
}
// sets the appengine
void FormFactory::setAppEngine(QQmlEngine *engine)
{
    if(engine)
    appEngine=engine;
}

//sets the qmlengiine
void FormFactory::setQmlEngine(QObject *engine)
{
        QmlEngine=engine;
};
