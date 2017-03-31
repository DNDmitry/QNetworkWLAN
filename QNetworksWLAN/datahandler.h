#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include "dataextractor.h"
#include "QStandardItemModel"

class DataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void init(QStandardItemModel *model);

private:
    DataExtractor *m_extractor;
    QList<QStandardItem*> *test_items;



};

#endif // DATAHANDLER_H
