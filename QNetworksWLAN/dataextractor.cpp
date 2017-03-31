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
        result.append(it.name());
    }
    return result;
}
