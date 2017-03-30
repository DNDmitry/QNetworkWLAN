#include "wlan_gui.h"
#include "ui_wlan_gui.h"

WLAN_GUI::WLAN_GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WLAN_GUI)
{
    ui->setupUi(this);
    setLayout(ui->verticalLayout);
}

WLAN_GUI::~WLAN_GUI()
{
    delete ui;
}
