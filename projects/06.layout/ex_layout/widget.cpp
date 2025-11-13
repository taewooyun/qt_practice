#include "widget.h"
#include "./ui_widget.h"

#include <QHBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *hboxLayout = new QHBoxLayout();
    QPushButton *btn[6];


    for(int i=0; i<6; ++i){
        btn[i] = new QPushButton(QString::number(i));
        hboxLayout->addWidget(btn[i]);
    }




}

Widget::~Widget()
{
    delete ui;
}
