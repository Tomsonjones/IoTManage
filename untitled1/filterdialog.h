#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();
    QString getDeviceName() const;
    QString getLocation() const;

private:
    Ui::FilterDialog *ui;
    QComboBox *deviceNameComboBox;
    QComboBox *locationComboBox;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
};

#endif // FILTERDIALOG_H
