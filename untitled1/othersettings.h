#ifndef OTHERSETTINGS_H
#define OTHERSETTINGS_H

#include <QWidget>
#include "usermanagement.h"

namespace Ui {
class OtherSettings;
}
class UserManagementLow;
class OtherSettings : public QWidget
{
    Q_OBJECT

public:
    explicit OtherSettings(QWidget *parent = nullptr);
    ~OtherSettings();
public slots:
    void UserManagementDisplay();
private:
    Ui::OtherSettings *ui;
    UserManagement *m_pUserManagement;

};
extern UserManagementLow *m_pUserManagementLow;

#endif // OTHERSETTINGS_H
