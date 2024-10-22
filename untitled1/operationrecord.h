#ifndef OPERATIONRECORD_H
#define OPERATIONRECORD_H

#include <QWidget>

namespace Ui {
class OperationRecord;
}

class OperationRecord : public QWidget
{
    Q_OBJECT

public:
    explicit OperationRecord(QWidget *parent = nullptr);
    ~OperationRecord();

private:
    Ui::OperationRecord *ui;
};

#endif // OPERATIONRECORD_H
