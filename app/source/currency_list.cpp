#include "headers/currency_list.h"




Currency_list::Currency_list(QObject *parent):
         QAbstractListModel(parent)
{
setList();

}

//return the active currency in the currencylist
int Currency_list::getactivecurrencyindex() const
{
    return choosenCurrency;
}

//returns the exchange rate of the choosen currency
double Currency_list::getcurrencyconverter()
{
    return list.first().converter;
}

// return the active currency structure
Currency Currency_list::getacivecurrency()
{
    return list.first();
}
//returns the currencyname
QString Currency_list::getcurrencyName() const
{
    return list.first().type;
}


// makes visible only one element
bool Currency_list::hidelist()
{
    return displayonelement=!displayonelement;
}


// sets a new active currency
void Currency_list::setactivecurrency(const int& newcurrency)
{
    if(newcurrency!=0)
        {
        choosenCurrency=newcurrency;
        swapRows(choosenCurrency,0);
        }
        currecychoosen=true;

        emit choosencurrencyChanged();

}

// returns the size of the list
int Currency_list::rowCount(const QModelIndex &parent)const
{
    if(parent.isValid())return 0;

    else if(displayonelement)
        return 1;
    else
        return list.size();

}

// sets data in the list
QVariant Currency_list::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() && list.empty())
        return "";

    switch (role) {

    case AMOUNT:{
        return list.at(index.row()).amount;
    }break;

    case FILEPATH:{
        return list.at(index.row()).filePath;
    }break;

    case TYPE:{
    return list.at(index.row()).type;
    }break;

    case CONVERTER:
    {
        return list.at(index.row()).converter;
    }break;
    default:return "";
    }

}

// allows to call the data from qml
QHash<int, QByteArray> Currency_list::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[AMOUNT]="amount";
    roles[FILEPATH]="filepath";
    roles[TYPE]="type";
    roles[CONVERTER]="converter";
    return roles;

}

// swap the 2 given rows
void Currency_list::swapRows(const int &sourceindex, const int &destindex)
{
    list.swapItemsAt(sourceindex,destindex);

}


// sets a new list
void Currency_list::setList()
{
    QString clientid = Session::getclientId();

    Currency currency;
    Data_base *db=&Data_base::get_instance();
    currency.amount = db->getclient_data("AccountBalance",Data_base::clients,clientid);
    list.push_back(currency);

        QStringList amount = db->getcolumn("AccountBalance",Data_base::currency_accounts,clientid);
        QStringList type = db->getcolumn("Currency",Data_base::currency_accounts,clientid);
       for(int i=0; i<type.size();i++ )
         {
            currency.amount=amount.at(i);
            currency.type=type.at(i);
            currency.filePath="../images/"+currency.type+".jpg";
            list.push_back(currency);
         }

}

// sets another list
void Currency_list::setallcurrency()
{
        list.clear();
        Currency currency;
        Data_base *db=&Data_base::get_instance();
        QStringList converter = db->getcolumn("ExchangeRate",Data_base::currencys);
        QStringList type = db->getcolumn("Currency",Data_base::currencys);

        for(int i=0; i<type.size();i++ )
             {
                currency.converter=converter.at(i).toDouble();
                currency.type=type.at(i);
                currency.filePath="../images/"+currency.type+".jpg";
                list.push_back(currency);
             }


}



