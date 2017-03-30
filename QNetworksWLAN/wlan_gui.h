#ifndef WLAN_GUI_H
#define WLAN_GUI_H

#include <QWidget>

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
};

#endif // WLAN_GUI_H
