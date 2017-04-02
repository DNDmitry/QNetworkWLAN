#include "datahandler.h"

DataHandler::DataHandler()
{

}
DataHandler::~DataHandler()
{
    delete test_items;
}

void DataHandler::init(std::unique_ptr<QStandardItemModel> &model)
{
   // model->clear();
    /////////////////////
    test_items = new QList<QStandardItem*>();
    m_extractor = std::unique_ptr<DataExtractor>(new DataExtractor());
    QStringList test_data = m_extractor.get()->get_wlan_list();
    for(auto it : test_data)
    {
        test_items->append(new QStandardItem(it));
        model->appendRow(*test_items);
        test_items->clear();
    }
    ///////////////////////
}

void DataHandler::get_connect(const QString &name)
{
    m_extractor.get()->connect_to_network(name);
}

