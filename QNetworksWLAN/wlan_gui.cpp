#include "wlan_gui.h"
#include "ui_wlan_gui.h"

WLAN_GUI::WLAN_GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WLAN_GUI)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/wifi.png"));
    ui->lvView->setModelColumn(2);
    setLayout(ui->glLayout);
    this->m_handler = std::unique_ptr<DataHandler>(new DataHandler(this));
    this->m_model = std::unique_ptr<QStandardItemModel>(new QStandardItemModel(this));
    filling_in_the_view();

    connect(ui->lvView, &QListView::doubleClicked, this, &WLAN_GUI::make_connection);
    connect(ui->lvView, &QListView::doubleClicked, this, &WLAN_GUI::filling_in_the_view);

    m_timer = std::unique_ptr<QTimer>(new QTimer(this));
    connect(m_timer.get(), &QTimer::timeout, this, &WLAN_GUI::filling_in_the_view);    
    m_timer.get()->start(UPDATE_INTERVAL);

    connect(ui->pbUpdate, &QPushButton::clicked, this, &WLAN_GUI::filling_in_the_view);
}

void WLAN_GUI::make_connection(const QModelIndex &network_name)
{
    QString name = network_name.data().toString();
    m_handler.get()->get_connect(name);
}

void WLAN_GUI::filling_in_the_view()
{
    m_model->clear();
    m_handler->init(m_model);
    ui->lvView->setModel(m_model.get());
}

WLAN_GUI::~WLAN_GUI()
{
    delete ui;
}
