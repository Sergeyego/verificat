#ifndef FORMREP_H
#define FORMREP_H

#include <QWidget>
#include "modelro.h"

namespace Ui {
class FormRep;
}

class ModelRep : public ModelRo
{
    Q_OBJECT

public:
    explicit ModelRep(QObject *parent = nullptr);
    QVariant data(const QModelIndex &item, int role) const;
    ~ModelRep();

public slots:
    void refresh();

};

class FormRep : public QWidget
{
    Q_OBJECT

public:
    explicit FormRep(QWidget *parent = nullptr);
    ~FormRep();

private:
    Ui::FormRep *ui;
    ModelRep *modelRep;

private slots:
    void upd();
};

#endif // FORMREP_H
