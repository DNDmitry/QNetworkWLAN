#include "dataextractor.h"

DataExtractor::DataExtractor()
{

}
DataExtractor::~DataExtractor()
{

}

QStringList DataExtractor::get_wlan_list()
{
    m_configurations_list = m_netmanager.allConfigurations();
    QStringList result;
    for(auto it : m_configurations_list)
    {
        if (it.bearerType() == QNetworkConfiguration::BearerWLAN)
            result.append(it.name());
    }
    return result;
}
