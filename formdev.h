#ifndef FORMDEV_H
#define FORMDEV_H

#include <QWidget>
#include "db/dbtablemodel.h"
#include "rels.h"

namespace Ui {
class FormDev;
}

class FormDev : public QWidget
{
    Q_OBJECT

public:
    explicit FormDev(QWidget *parent = nullptr);
    ~FormDev();

private:
    Ui::FormDev *ui;
    DbTableModel *modelDev;
};

#endif // FORMDEV_H
