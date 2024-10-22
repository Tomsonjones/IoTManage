#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include <QWidget>
#include "normalsettings.h"
#include "equipmanage.h"

namespace Ui {
class SystemSettings;
}

class SystemSettings : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSettings(QWidget *parent = nullptr);
    ~SystemSettings();

private:
    Ui::SystemSettings *ui;
    NormalSettings *m_pNormalSettings;
    EquipManage *m_pEquipManage;
};

#endif // SYSTEMSETTINGS_H
