#ifndef NORMALSETTINGS_H
#define NORMALSETTINGS_H

#include <QWidget>

namespace Ui {
class NormalSettings;
}

class NormalSettings : public QWidget
{
    Q_OBJECT

public:
    explicit NormalSettings(QWidget *parent = nullptr);
    ~NormalSettings();

private:
    Ui::NormalSettings *ui;
};

#endif // NORMALSETTINGS_H
