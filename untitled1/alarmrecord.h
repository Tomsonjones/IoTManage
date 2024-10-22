#ifndef ALARMRECORD_H
#define ALARMRECORD_H

#include <QWidget>

namespace Ui {
class AlarmRecord;
}

class AlarmRecord : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmRecord(QWidget *parent = nullptr);
    ~AlarmRecord();

private:
    Ui::AlarmRecord *ui;
};

#endif // ALARMRECORD_H
