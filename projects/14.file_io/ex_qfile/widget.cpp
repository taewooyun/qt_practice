#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pbtOpen,  SIGNAL(pressed()),
            this,         SLOT(slotPbtOpenPress()));
    connect(ui->pbtWrite, SIGNAL(pressed()),
            this,         SLOT(slotPbtWritePress()));
    connect(ui->pbtClose, SIGNAL(pressed()),
            this,         SLOT(slotPbtClosePress()));

    mFile = new QFile();
    connect(mFile, SIGNAL(aboutToClose()),
            this,  SLOT(slotAboutToClose()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotPbtOpenPress()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(
        this,
        "Open File",
        QDir::currentPath(),
        "Files (*.txt)");

    mFile->setFileName(fileName);

    if(!mFile->open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "File open fail.";
        return;
    }

    QTextStream in(mFile);
    while(in.atEnd()) {
        qDebug() << in.readLine();
    }
}

void Widget::slotPbtWritePress()
{
    QTextStream in(mFile);
    mFile->seek(mFile->size());

    in << "End.\n";
}

void Widget::slotPbtClosePress()
{
    if(mFile->isOpen())
        mFile->close();
}

void Widget::slotAboutToClose()
{
    qDebug() << Q_FUNC_INFO;

}

