#ifndef EQUIPMENTPANEL_H
#define EQUIPMENTPANEL_H

#include <QWidget>

namespace Ui {
class EquipmentPanel;
}

class EquipmentPanel : public QWidget
{
    Q_OBJECT

public:
    explicit EquipmentPanel(QWidget *parent = nullptr);
    ~EquipmentPanel();

private:
    Ui::EquipmentPanel *ui;
};

#endif // EQUIPMENTPANEL_H
