#ifndef EQUIPMENTPANEL_H
#define EQUIPMENTPANEL_H

#include <QWidget>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QtWidgets>
#include <QtSql>

namespace Ui {
class EquipmentPanel;
}

class EquipmentPanel : public QWidget
{
    Q_OBJECT

public:
    explicit EquipmentPanel(QWidget *parent = nullptr);
    ~EquipmentPanel();
public slots:
    void DeleteAction();
    void AddAction();
    void FilterAction();
private:
    Ui::EquipmentPanel *ui;
    QSqlTableModel *model;
    QPushButton *DeleteButton;
    QPushButton *AddButton;
    QDialogButtonBox *buttonBox;
    QPushButton *filterButton;
};

#endif // EQUIPMENTPANEL_H
