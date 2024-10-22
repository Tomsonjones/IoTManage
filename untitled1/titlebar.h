#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QDialog>

namespace Ui {
class Titlebar;
}

class Titlebar : public QDialog
{
    Q_OBJECT

public:
    explicit Titlebar(QWidget *parent = nullptr);
    ~Titlebar();

signals:
    void miniSizedSignal();
    void maxSizedSignal();
    void closeSignal();

private:
    Ui::Titlebar *ui;
};

#endif // TITLEBAR_H
