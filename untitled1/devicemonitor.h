#ifndef DEVICEMONITOR_H
#define DEVICEMONITOR_H

#include <QWidget>
#include "datamonitor.h"
#include "equipmentpanel.h"
#include "barchart.h"
#include "linegraph.h"

namespace Ui {
class DeviceMonitor;
}

class DeviceMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceMonitor(QWidget *parent = nullptr);
    ~DeviceMonitor();

private:
    Ui::DeviceMonitor *ui;
    DataMonitor *m_pDataMonitor;
    EquipmentPanel *m_pEquipmentPanel;
    BarChart *m_pBarChart;
    LineGraph *m_pLineGraph;
};

#endif // DEVICEMONITOR_H
