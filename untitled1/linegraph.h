#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <QWidget>

namespace Ui {
class LineGraph;
}

class LineGraph : public QWidget
{
    Q_OBJECT

public:
    explicit LineGraph(QWidget *parent = nullptr);
    ~LineGraph();

private:
    Ui::LineGraph *ui;
};

#endif // LINEGRAPH_H
