#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include "dataextractor.h"
#include "QStandardItemModel"

class DataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void init(std::unique_ptr<QStandardItemModel> &model);
    void get_connect(const QString &name);

private:
    std::unique_ptr<DataExtractor> m_extractor;
    QList<QStandardItem*> *items;

};

#endif // DATAHANDLER_H
