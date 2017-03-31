#include "wlan_gui.h"
#include "ui_wlan_gui.h"

WLAN_GUI::WLAN_GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WLAN_GUI)
{
    ui->setupUi(this);
    setLayout(ui->verticalLayout);
    this->m_handler = new DataHandler();
    this->m_model = new QStandardItemModel(this);
    filling_in_the_view();
}

void WLAN_GUI::filling_in_the_view()
{
    this->m_handler->init(this->m_model);
    ui->lvView->setModel(m_model);
}

WLAN_GUI::~WLAN_GUI()
{
    delete ui;
}
