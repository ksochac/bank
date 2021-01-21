#include "headers/session.h"

Session::Session(QObject *parent) : QObject(parent),
    db(&Data_base::get_instance())
{}
QString Session::client_id=0;

// returns the given data the clients asks for from the clients table
QString Session::get_data_from_clients_table(QString record) const
{
    return db->getclient_data(record,Data_base::clients,client_id);
}
 // sets the transfers
void Session::settransfers()
{
    transfers = db->set_clients_transfers(client_id);
}



