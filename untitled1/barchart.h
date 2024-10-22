#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>

namespace Ui {
class BarChart;
}

class BarChart : public QWidget
{
    Q_OBJECT

public:
    explicit BarChart(QWidget *parent = nullptr);
    ~BarChart();

private:
    Ui::BarChart *ui;
};

#endif // BARCHART_H
