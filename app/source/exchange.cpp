#include "headers/exchange.h"

// sets the modeldata of the currencyform
Exchange::Exchange(QObject *parent) : QObject(parent),
    form(FormFactory::getInstance().CreateForm("Form")),
    db(&Data_base::get_instance())
{
    form->mform.insert("Result", "00.00");
    form->mform_edited.insert("Result", false );
}

// returns the result of the exchange
QString Exchange::getresult(QString amount, double converter)
{
    QVariant res=amount.toDouble()*converter;
    return res.toString();
}
