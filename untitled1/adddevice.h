#ifndef ADDDEVICE_H
#define ADDDEVICE_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QDateEdit>

namespace Ui {
class AddDevice;
}

class AddDevice : public QDialog
{
    Q_OBJECT

public:
    explicit AddDevice(QWidget *parent = nullptr);
    ~AddDevice();

private slots:
    void onConfirmButtonClicked(); // 确认按钮槽函数
    void onCancelButtonClicked();

private:
    Ui::AddDevice *ui;
    QComboBox *deviceNameComboBox;
    QComboBox *typeComboBox;
    QComboBox *locationComboBox;
    QComboBox *manufacturerComboBox;
    QComboBox *modelComboBox;
    QDateEdit *installDateEdit;

    QPushButton *confirmButton;
    QPushButton *cancelButton;
};

#endif // ADDDEVICE_H
