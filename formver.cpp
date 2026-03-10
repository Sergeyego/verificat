#include "formver.h"
#include "ui_formver.h"

FormVer::FormVer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormVer)
{
    ui->setupUi(this);

    ui->dateEditBeg->setDate(QDate(QDate::currentDate().year(),1,1));
    ui->dateEditEnd->setDate(QDate(QDate::currentDate().year(),12,31));

    modelVer = new DbTableModel("ver_act",this);
    modelVer->addColumn("dat",tr("Дата поверки"));
    modelVer->addColumn("id_dev",tr("Прибор"),Rels::instance()->relDev);
    modelVer->setSort("ver_act.dat, ver_dev.str");

    ui->tableViewVer->setModel(modelVer);
    ui->tableViewVer->setColumnWidth(0,100);
    ui->tableViewVer->setColumnWidth(1,500);

    connect(ui->pushButtonUpd,SIGNAL(clicked(bool)),this,SLOT(upd()));
    upd();
}

FormVer::~FormVer()
{
    delete ui;
}

void FormVer::upd()
{
    modelVer->refreshRelsModel();
    modelVer->setFilter("ver_act.dat between '"+ui->dateEditBeg->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEditEnd->date().toString("yyyy-MM-dd")+"'");
    modelVer->select();
}
