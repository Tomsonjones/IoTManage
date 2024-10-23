#ifndef DATAMONITOR_H
#define DATAMONITOR_H

#include <QWidget>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QtWidgets>
#include <QtSql>
#include <QTimer>

namespace Ui {
class DataMonitor;
}

class DataMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit DataMonitor(QWidget *parent = nullptr);
    ~DataMonitor();
private slots:
    //更新数据
    void updateData();
    void insertDataToDatabase();
    //检测是否有异常信息
    void checkForAlerts();
private:
    Ui::DataMonitor *ui;
    QSqlTableModel *model;
    QDialogButtonBox *buttonBox;
    //QPushButton *filterButton;
    QTimer *dataUpdateTimer;    // 定时器，用于每10秒更新一次实时数据
    QLabel *alertLabel;         // 显示异常的提示框
};

#endif // DATAMONITOR_H
