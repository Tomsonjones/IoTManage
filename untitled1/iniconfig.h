#ifndef INICONFIG_H
#define INICONFIG_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class IniConfig;
}

class IniConfig : public QWidget
{
    Q_OBJECT

public:
    explicit IniConfig(QWidget *parent = nullptr);
    ~IniConfig();
    void readSettings();
    void writeSettings();
    QString m_username;
    QString m_password;

private:
    Ui::IniConfig *ui;
    QSettings * m_pSettings;
};

#endif // INICONFIG_H
