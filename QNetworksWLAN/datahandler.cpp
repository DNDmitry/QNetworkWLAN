#include "datahandler.h"

DataHandler::DataHandler()
{

}
DataHandler::~DataHandler()
{
    delete items;
}

void DataHandler::init(std::unique_ptr<QStandardItemModel> &model)
{
   // model->clear();
    /////////////////////
    items = new QList<QStandardItem*>();
    m_extractor = std::unique_ptr<DataExtractor>(new DataExtractor());
    QJsonArray data = m_extractor.get()->get_wlan_list();
    for(auto it : data)
    {
        QJsonObject obj = it.toObject();
        items->append(new QStandardItem(obj["name"].toString()));
        model->appendRow(*items);
        items->clear();
    }
    ///////////////////////
}

void DataHandler::get_connect(const QString &name)
{
    m_extractor.get()->connect_to_network(name);
}

