#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QDialog>

namespace Ui {
class Statusbar;
}

class Statusbar : public QDialog
{
    Q_OBJECT

public:
    explicit Statusbar(QWidget *parent = nullptr);
    ~Statusbar();

public slots:
    void showStatus(int a);

private:
    Ui::Statusbar *ui;
};

#endif // STATUSBAR_H
