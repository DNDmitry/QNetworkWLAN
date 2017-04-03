#include "datahandler.h"

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{

}
DataHandler::~DataHandler()
{
    delete items;
}

void DataHandler::init(std::unique_ptr<QStandardItemModel> &model)
{
    items = new QList<QStandardItem*>();
    m_extractor = std::unique_ptr<DataExtractor>(new DataExtractor());
    QJsonArray *data = m_extractor.get()->get_wlan_list();
    std::for_each(data->begin(), data->end(), [&](QJsonValueRef it)
    {
        QJsonObject obj = it.toObject();
        if(obj["connected"].toBool() == true)
            items->append(new QStandardItem(QIcon(":/new/prefix1/wifi.png"), obj["name"].toString()));
        else
            items->append(new QStandardItem(QIcon(":/new/prefix1/locked.png"), obj["name"].toString()));
        model.get()->appendRow(*items);
        items->clear();
    });
}

void DataHandler::get_connect(const QString &name)
{
    m_extractor.get()->connect_to_network(name);
}

