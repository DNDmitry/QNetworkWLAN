#ifndef DATAEXTRACTOR_H
#define DATAEXTRACTOR_H
#include <memory>
#include <iostream>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkConfiguration>
#include <QtNetwork/QNetworkSession>
#include <QTimer>
#include <QObject>


class DataExtractor : public QObject
{    
    Q_OBJECT
public:
    DataExtractor(QObject *parent = 0);
    ~DataExtractor();
    QStringList get_wlan_list();

public slots:
    void connect_to_network(const QString &name);

private:

    // to_json
    std::unique_ptr<QNetworkConfiguration> m_configuration;
    std::unique_ptr<QNetworkConfigurationManager> m_netmanager;
    QList<QNetworkConfiguration> m_configurations_list;


};

#endif // DATAEXTRACTOR_H
