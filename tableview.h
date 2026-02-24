#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include <QHeaderView>


class TableView : public QTableView
{
        Q_OBJECT
public:
    TableView(QWidget *parent=0);

public slots:
    void resizeToContents();

};

#endif // TABLEVIEW_H
