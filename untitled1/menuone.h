#ifndef MENUONE_H
#define MENUONE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QItemSelectionModel>
#include <QModelIndexList>

#include "devicemonitor.h"
#include "dataquery.h"
#include "systemsettings.h"
#include "othersettings.h"

namespace Ui {
class MenuOne;
}

class MenuOne : public QDialog
{
    Q_OBJECT

public:
    explicit MenuOne(QWidget *parent = nullptr);
    ~MenuOne();

signals:
    void display(int a);
    void ChangeInterfaceSize();
public slots:
    void QuitBtn();

private:
    Ui::MenuOne *ui;
    DeviceMonitor *m_pDeviceMonitor;
    DataQuery *m_pDataQuery;
    SystemSettings *m_pSystemSettings;
    OtherSettings *m_pOtherSettings;
};

#endif // MENUONE_H
