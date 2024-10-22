#ifndef SYSTEMSETTINGSBUTTON_H
#define SYSTEMSETTINGSBUTTON_H

#include <QWidget>

namespace Ui {
class SystemSettingsButton;
}

class SystemSettingsButton : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSettingsButton(QWidget *parent = nullptr);
    ~SystemSettingsButton();

private:
    Ui::SystemSettingsButton *ui;
};

#endif // SYSTEMSETTINGSBUTTON_H
