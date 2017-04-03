#ifndef DATAEXTRACTOR_H
#define DATAEXTRACTOR_H
#include <memory>
#include <iostream>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkConfiguration>
#include <QtNetwork/QNetworkSession>
#include <QtNetwork/QNetworkAccessManager>
#include <QTimer>
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>

class DataExtractor : public QObject
{    
    Q_OBJECT
public:
    explicit DataExtractor(QObject *parent = 0);
    ~DataExtractor();
    QJsonArray* get_wlan_list();
    void connect_to_network(const QString &name);

private:
    std::unique_ptr<QNetworkConfigurationManager> m_netmanager;    
    QList<QNetworkConfiguration> m_configurations_list;
    std::unique_ptr<QJsonArray> json;
};

#endif // DATAEXTRACTOR_H
