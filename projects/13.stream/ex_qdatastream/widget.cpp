#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDataStream>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtSave, SIGNAL(pressed()),
            this, SLOT(slotPbtFileSave()));
    connect(ui->pbtFileRead, SIGNAL(pressed()),
            this, SLOT(slotPbtFileRead()));

    mFile = new QFile();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotPbtFileSave()
{
    QString fileName;
    fileName = QString("C:/Users/2-21/Desktop/price.data");

    mFile->setFileName(fileName);
    if(!mFile->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "File open fail.";
        return;
    }
    else
    {
        qint32 keyboardPrice = ui->leKeyboard->text().toInt();
        qint32 monitoryPrice = ui->leMonitor->text().toInt();

        QDataStream out(mFile);
        out << keyboardPrice;
        out << monitoryPrice;

        mFile->close();
    }
}

void Widget::slotPbtFileRead()
{
    if(!mFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "File open fail.";
        return;
    }
    else
    {
        qint32 keyboardPrice;
        qint32 monitoryPrice;

        QDataStream in(mFile);
        in >> keyboardPrice;
        in >> monitoryPrice;

        mFile->close();

        qDebug() << "Keyboard price : " << keyboardPrice;
        qDebug() << "Monitor  price : " << monitoryPrice;
    }
}



