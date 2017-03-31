#include "datahandler.h"

DataHandler::DataHandler()
{

}

void DataHandler::init(QStandardItemModel *model)
{
   // model->clear();
    /////////////////////
    test_items = new QList<QStandardItem*>();
    QStringList test_data = {"first", "second", "third"};
    for(auto it : test_data)
    {
        test_items->append(new QStandardItem(it));
        model->appendRow(*test_items);
        test_items->clear();
    }
    ///////////////////////


}
