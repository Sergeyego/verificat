#include "formrep.h"
#include "ui_formrep.h"

FormRep::FormRep(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormRep)
{
    ui->setupUi(this);
    modelRep = new ModelRep(this);
    ui->tableViewRep->setModel(modelRep);
    connect(ui->pushButtonUpd,SIGNAL(clicked(bool)),this,SLOT(upd()));
}

FormRep::~FormRep()
{
    delete ui;
}

void FormRep::upd()
{
    modelRep->refresh();
    ui->tableViewRep->resizeToContents();
}

ModelRep::ModelRep(QObject *parent) : ModelRo(parent)
{

}

QVariant ModelRep::data(const QModelIndex &item, int role) const
{
    if (role==Qt::BackgroundRole){
        QDate dend=this->data(this->index(item.row(),5),Qt::EditRole).toDate();
        int dt=QDate::currentDate().daysTo(dend);
        if (dt<=7){
            return QVariant(QColor(255,170,170));
        } else if (dt<=30){
            return QVariant(QColor(Qt::yellow));
        }
    }
    return ModelRo::data(item,role);
}

ModelRep::~ModelRep()
{

}

void ModelRep::refresh()
{
    QSqlQuery query;
    query.prepare("select vd.nam, vd.locat, vd.numb, vd.ver_per, pv.dat as dat_beg, (pv.dat + interval '1 month'*vd.ver_per)::date as dat_end "
                  "from ver_dev vd "
                  "left join (select va.id_dev as id_dev, max(va.dat) as dat from ver_act va group by va.id_dev) as pv on pv.id_dev=vd.id "
                  "where vd.is_use = true order by (pv.dat is null) desc, dat_end, vd.nam");
    if (execQuery(query)){
        this->setHeaderData(0,Qt::Horizontal,tr("Прибор"));
        this->setHeaderData(1,Qt::Horizontal,tr("Место установки"));
        this->setHeaderData(2,Qt::Horizontal,tr("Заводской номер"));
        this->setHeaderData(3,Qt::Horizontal,tr("Период поверки, мес"));
        this->setHeaderData(4,Qt::Horizontal,tr("Дата последней поверки"));
        this->setHeaderData(5,Qt::Horizontal,tr("Дата следующей поверки"));
    }
}
