#ifndef DATAQUERYBUTTON_H
#define DATAQUERYBUTTON_H

#include <QWidget>

namespace Ui {
class DataQueryButton;
}

class DataQueryButton : public QWidget
{
    Q_OBJECT

public:
    explicit DataQueryButton(QWidget *parent = nullptr);
    ~DataQueryButton();

private:
    Ui::DataQueryButton *ui;
};

#endif // DATAQUERYBUTTON_H
