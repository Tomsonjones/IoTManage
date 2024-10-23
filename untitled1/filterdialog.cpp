#include "filterdialog.h"
#include "ui_filterdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
    // 创建下拉菜单和按钮

    setWindowTitle("筛选");
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    deviceNameComboBox = new QComboBox(this);
    deviceNameComboBox->addItems({"", "测温仪", "湿度计", "光照检测仪"});

    locationComboBox = new QComboBox(this);
    locationComboBox->addItems({"", "位置1", "位置2", "位置3"});

    confirmButton = new QPushButton("确定", this);
    cancelButton = new QPushButton("取消", this);

    // 布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *deviceLayout = new QHBoxLayout();
    QHBoxLayout *locationLayout = new QHBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    deviceLayout->addWidget(new QLabel("设备名称:"));
    deviceLayout->addWidget(deviceNameComboBox);

    locationLayout->addWidget(new QLabel("位置:"));
    locationLayout->addWidget(locationComboBox);

    buttonLayout->addWidget(confirmButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(deviceLayout);
    mainLayout->addLayout(locationLayout);
    mainLayout->addLayout(buttonLayout);

    // 连接按钮的信号槽
    connect(confirmButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString FilterDialog::getDeviceName() const
{
    return deviceNameComboBox->currentText();
}

QString FilterDialog::getLocation() const
{
    return locationComboBox->currentText();
}

FilterDialog::~FilterDialog()
{
    delete ui;
}
