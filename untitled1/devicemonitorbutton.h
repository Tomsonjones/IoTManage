#ifndef DEVICEMONITORBUTTON_H
#define DEVICEMONITORBUTTON_H

#include <QWidget>

namespace Ui {
class DeviceMonitorButton;
}

class DeviceMonitorButton : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceMonitorButton(QWidget *parent = nullptr);
    ~DeviceMonitorButton();

private:
    Ui::DeviceMonitorButton *ui;
};

#endif // DEVICEMONITORBUTTON_H
