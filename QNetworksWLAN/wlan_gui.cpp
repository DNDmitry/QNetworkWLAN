#include "wlan_gui.h"
#include "ui_wlan_gui.h"

WLAN_GUI::WLAN_GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WLAN_GUI)
{
    ui->setupUi(this);
    setLayout(ui->verticalLayout);
    this->m_handler = std::unique_ptr<DataHandler>(new DataHandler());//new DataHandler(this);
    this->m_model = std::unique_ptr<QStandardItemModel>(new QStandardItemModel(this));//new QStandardItemModel(this);
    filling_in_the_view();
}

void WLAN_GUI::filling_in_the_view()
{
    m_handler->init(m_model);
    ui->lvView->setModel(m_model.get());
}

WLAN_GUI::~WLAN_GUI()
{
    delete ui;
}
