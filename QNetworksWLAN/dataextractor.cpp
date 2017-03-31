#include "dataextractor.h"


DataExtractor::DataExtractor(QObject *parent) : QObject(parent)
{
    m_timer = std::unique_ptr<QTimer>(new QTimer(this));
    connect(m_timer.get(), &QTimer::timeout, this, &DataExtractor::activateAutoClick);
    m_timer->start(UPDATE_INTERVAL);
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

void DataExtractor::activateAutoClick()
{
    get_wlan_list();
}
