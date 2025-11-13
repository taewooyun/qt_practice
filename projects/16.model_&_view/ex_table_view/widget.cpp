#include "widget.h"
#include <QDate>
#include <QFileSystemModel>
#include <QSplitter>
#include <QStringListModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,400);
    QSplitter *splitter = new QSplitter(this);

    QStandardItemModel *itemModel = new QStandardItemModel(0, 3);
    itemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Subject"));
    itemModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    itemModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));

    itemModel->setVerticalHeaderItem(0, new QStandardItem("Col 1"));
    itemModel->setVerticalHeaderItem(1, new QStandardItem("Col 2"));

    itemModel->setData(itemModel->index(0, 0), "Monitor");
    itemModel->setData(itemModel->index(0, 1), "LCD");
    itemModel->setData(itemModel->index(0, 2), QDate(2030, 10, 4));

    itemModel->setData(itemModel->index(1, 0), "CPU");
    itemModel->setData(itemModel->index(1, 1), "Samsung");
    itemModel->setData(itemModel->index(1, 2), QDate(2030, 10, 4));


    QStringList strList;
    strList << "Monday" << "Tuesday" << "Wedneday" << "Thurday" << "Friday";
    QAbstractItemModel *listModel = new QStringListModel(strList);

    QFileSystemModel *fileModel = new QFileSystemModel;
    fileModel->setRootPath(QDir::currentPath());

    QTableView *tableItem = new QTableView(splitter);
    tableItem->setModel(itemModel);

    QTableView *tableList = new QTableView(splitter);
    tableList->setModel(listModel);

    QTableView *tableFile = new QTableView(splitter);
    tableFile->setModel(fileModel);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(tableItem);
    lay->addWidget(tableList);
    lay->addWidget(tableFile);

    setLayout(lay);
}

Widget::~Widget()
{

}

