#ifndef WIDGET_H
#define WIDGET_H

#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QVBoxLayout>
#include <QDateTime>
#include <QTableView>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:

};

#endif // WIDGET_H
