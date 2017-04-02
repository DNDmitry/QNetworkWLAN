#include "dataextractor.h"


DataExtractor::DataExtractor(QObject *parent) :
    QObject(parent)
{

}
DataExtractor::~DataExtractor()
{

}

QStringList DataExtractor::get_wlan_list()
{
    m_configurations_list = m_netmanager->allConfigurations();
    QStringList result;
    for(auto it : m_configurations_list)
    {
        if (it.bearerType() == QNetworkConfiguration::BearerWLAN)
            result.append(std::move(it.name()));
    }
    return result;
}

void DataExtractor::connect_to_network(const QString &name)
{
    for(auto it : m_configurations_list)
    {
        if(it.name() == name)
        {
            auto session = new QNetworkSession(it, this);
            if(session->state() == QNetworkSession::Connected)
                session->stop();
            else
                session->open();
        }
    }


}
