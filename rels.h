#ifndef RELS_H
#define RELS_H

#include <QObject>
#include "db/dbtablemodel.h"

class Rels : public QObject
{
    Q_OBJECT
public:
    static Rels *instance();
    DbSqlRelation *relDev;

protected:
    explicit Rels(QObject *parent = nullptr);

private:
    static Rels *rels_instance;

};

#endif // RELS_H
