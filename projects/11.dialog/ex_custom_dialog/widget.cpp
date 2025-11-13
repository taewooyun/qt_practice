#include "widget.h"
#include "./ui_widget.h"
#include "dialog.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *btn = new QPushButton("dialog", this);
    btn->setGeometry(150, 250, 200, 100);
    connect(btn, &QPushButton::clicked, this, &Widget::pushBtn);
}



void Widget::pushBtn()
{
    Dialog dlg;
    int retVal = dlg.exec();
    if(retVal == QDialog::Accepted)
    {
        qDebug() << Q_FUNC_INFO << "QDialog::Accepted";
    }
    else if(retVal == QDialog::Rejected)
    {
        qDebug() << Q_FUNC_INFO << "QDialog::Rejected";
    }
}



Widget::~Widget()
{
    delete ui;
}

