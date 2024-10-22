#ifndef OTHERSETTINGSBUTTON_H
#define OTHERSETTINGSBUTTON_H

#include <QWidget>

namespace Ui {
class OtherSettingsButton;
}

class OtherSettingsButton : public QWidget
{
    Q_OBJECT

public:
    explicit OtherSettingsButton(QWidget *parent = nullptr);
    ~OtherSettingsButton();

private:
    Ui::OtherSettingsButton *ui;
};

#endif // OTHERSETTINGSBUTTON_H
