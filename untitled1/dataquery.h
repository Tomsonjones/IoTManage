#ifndef DATAQUERY_H
#define DATAQUERY_H

#include <QWidget>
#include "alarmrecord.h"
#include "operationrecords.h"
#include "operationrecord.h"

namespace Ui {
class DataQuery;
}

class DataQuery : public QWidget
{
    Q_OBJECT

public:
    explicit DataQuery(QWidget *parent = nullptr);
    ~DataQuery();

private:
    Ui::DataQuery *ui;
    AlarmRecord *m_pAlarmRecord;
    OperationRecords *m_pOperationRecords;
    OperationRecord *m_pOperationRecord;

};

#endif // DATAQUERY_H
