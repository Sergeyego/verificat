#include "formdev.h"
#include "ui_formdev.h"

FormDev::FormDev(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormDev)
{
    ui->setupUi(this);

    modelDev = new DbTableModel("ver_dev",this);
    modelDev->addColumn("id",tr("id"));
    modelDev->addColumn("nam",tr("Название"));
    modelDev->addColumn("numb",tr("Серийный номер"));
    modelDev->addColumn("ver_per",tr("Период поверки, мес."));
    modelDev->addColumn("is_use",tr("Используется"));
    modelDev->setSort("ver_dev.nam");
    modelDev->setDefaultValue(3,12);
    modelDev->setDefaultValue(4,true);
    modelDev->select();

    ui->tableViewDev->setModel(modelDev);
    ui->tableViewDev->setColumnHidden(0,true);
    ui->tableViewDev->setColumnWidth(1,300);
    ui->tableViewDev->setColumnWidth(2,200);
    ui->tableViewDev->setColumnWidth(3,150);
    ui->tableViewDev->setColumnWidth(4,90);

    connect(modelDev,SIGNAL(sigUpd()),Rels::instance()->relDev,SLOT(refreshModel()));
}

FormDev::~FormDev()
{
    delete ui;
}
