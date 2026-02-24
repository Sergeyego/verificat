#ifndef FORMVER_H
#define FORMVER_H

#include <QWidget>
#include "db/dbtablemodel.h"
#include "rels.h"

namespace Ui {
class FormVer;
}

class FormVer : public QWidget
{
    Q_OBJECT

public:
    explicit FormVer(QWidget *parent = nullptr);
    ~FormVer();

private:
    Ui::FormVer *ui;
    DbTableModel *modelVer;

private slots:
    void upd();
};

#endif // FORMVER_H
