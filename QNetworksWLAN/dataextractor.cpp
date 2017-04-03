#include "dataextractor.h"


DataExtractor::DataExtractor(QObject *parent) :
    QObject(parent)
{

}
DataExtractor::~DataExtractor()
{

}

QJsonArray* DataExtractor::get_wlan_list()
{
    m_configurations_list = m_netmanager->allConfigurations();
    json = std::unique_ptr<QJsonArray>(new QJsonArray());
    for(auto it : m_configurations_list)
    {
        if (it.bearerType() == QNetworkConfiguration::BearerWLAN)
        {
            QJsonObject single_wlan
            {
                {"name", it.name()},
                {"connected", it.state() == QNetworkConfiguration::Active ? true : false},
                {"secured", true} // unable to check
            };
            json.get()->push_front(std::move(single_wlan));
        }
    }
    return json.get();
}

void DataExtractor::connect_to_network(const QString &name)
{
    for(auto it : m_configurations_list)
    {
        if(it.name() == name)
        {
            auto session = new QNetworkSession(it, this);
            if(session->state() == QNetworkSession::Connected)
            {
                session->stop();
                session->deleteLater();
            }
            else
            {
                session->open();
                session->waitForOpened(1000);
                session->deleteLater();
            }

        }
    }
}
