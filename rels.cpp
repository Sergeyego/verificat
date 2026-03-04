#include "rels.h"

Rels* Rels::rels_instance=nullptr;

Rels *Rels::instance()
{
    if (rels_instance==nullptr)
        rels_instance = new Rels();
    return rels_instance;
}


Rels::Rels(QObject *parent) : QObject(parent)
{

    relDev = new DbSqlRelation("ver_dev","id","str",this);
    relDev->setFilter("is_use=true");
    relDev->setSort("str");
}

