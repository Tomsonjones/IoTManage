#ifndef EQUIPMANAGE_H
#define EQUIPMANAGE_H

#include <QWidget>

namespace Ui {
class EquipManage;
}

class EquipManage : public QWidget
{
    Q_OBJECT

public:
    explicit EquipManage(QWidget *parent = nullptr);
    ~EquipManage();

private:
    Ui::EquipManage *ui;
};

#endif // EQUIPMANAGE_H
