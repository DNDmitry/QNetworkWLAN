#ifndef WLAN_GUI_H
#define WLAN_GUI_H

#include <QWidget>
#include "datahandler.h"
#include <QTimer>

#define UPDATE_INTERVAL 3000

namespace Ui {
class WLAN_GUI;
}

class WLAN_GUI : public QWidget
{
    Q_OBJECT

public:
    explicit WLAN_GUI(QWidget *parent = 0);
    ~WLAN_GUI();

private:
    Ui::WLAN_GUI *ui;
    std::unique_ptr<QStandardItemModel> m_model;
    std::unique_ptr<DataHandler> m_handler;
    std::unique_ptr<QTimer> m_timer;

    void filling_in_the_view();
    void check_the_selection();
    void make_connection(const QModelIndex &network_name);

};

#endif // WLAN_GUI_H
