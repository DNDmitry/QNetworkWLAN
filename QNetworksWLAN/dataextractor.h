#ifndef DATAEXTRACTOR_H
#define DATAEXTRACTOR_H
#include <memory>
#include <iostream>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkConfiguration>

class DataExtractor
{
public:
    DataExtractor();
    ~DataExtractor();
    QStringList get_wlan_list();

private:

    // to_json
    QNetworkConfiguration m_configuration;
    QNetworkConfigurationManager m_netmanager;
    QList<QNetworkConfiguration> m_configurations_list;
};

#endif // DATAEXTRACTOR_H
