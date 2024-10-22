#ifndef OTHERSETTINGS_H
#define OTHERSETTINGS_H

#include <QWidget>
#include "usermanagement.h"

namespace Ui {
class OtherSettings;
}

class OtherSettings : public QWidget
{
    Q_OBJECT

public:
    explicit OtherSettings(QWidget *parent = nullptr);
    ~OtherSettings();

private:
    Ui::OtherSettings *ui;
    UserManagement *m_pUserManagement;
};

#endif // OTHERSETTINGS_H
