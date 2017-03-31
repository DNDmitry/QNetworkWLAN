#ifndef DATAEXTRACTOR_H
#define DATAEXTRACTOR_H
#include <memory>
#include <iostream>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkConfiguration>
#include <QTimer>
#include <QObject>

#define UPDATE_INTERVAL 1000
class DataExtractor
{    
public:
    DataExtractor();
    ~DataExtractor();
    QStringList get_wlan_list();


private:

    // to_json
    std::unique_ptr<QNetworkConfiguration> m_configuration;
    std::unique_ptr<QNetworkConfigurationManager> m_netmanager;
    QList<QNetworkConfiguration> m_configurations_list;


};

#endif // DATAEXTRACTOR_H
