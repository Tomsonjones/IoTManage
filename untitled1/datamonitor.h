#ifndef DATAMONITOR_H
#define DATAMONITOR_H

#include <QWidget>

namespace Ui {
class DataMonitor;
}

class DataMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit DataMonitor(QWidget *parent = nullptr);
    ~DataMonitor();

private:
    Ui::DataMonitor *ui;
};

#endif // DATAMONITOR_H
