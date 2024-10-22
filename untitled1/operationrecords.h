#ifndef OPERATIONRECORDS_H
#define OPERATIONRECORDS_H

#include <QWidget>

namespace Ui {
class OperationRecords;
}

class OperationRecords : public QWidget
{
    Q_OBJECT

public:
    explicit OperationRecords(QWidget *parent = nullptr);
    ~OperationRecords();

private:
    Ui::OperationRecords *ui;
};

#endif // OPERATIONRECORDS_H
