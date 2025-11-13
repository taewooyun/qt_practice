#include "widget.h"
#include "./ui_widget.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    if( initializeDataBase() )
    {
        creationTable();
        insertDataToTable();
        initializeModel();

        ui->tableView->setModel(m_model);

        connect(ui->pbtUpdate, SIGNAL(pressed()),
                this,          SLOT(slot_pbtUpdate()));
        connect(ui->pbtDelete, SIGNAL(pressed()),
                this,          SLOT(slot_pbtDelete()));

    }
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::initializeDataBase()
{
    QFile::remove("./my.db");

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("./my.db");

    if( !m_db.open() ) {
        qDebug() << Q_FUNC_INFO << m_db.lastError().text();
        return false;
    }

    return true;
}

void Widget::creationTable()
{
    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS names "
                "("
                "  id INTEGER UNIQUE PRIMARY KEY, "
                "  firstname VARCHAR(30), "
                "  lastname  VARCHAR(30)"
                ")" );

    if( !qry.exec() ) {
        qDebug() << qry.lastError().text();
    }
}

void Widget::insertDataToTable()
{
    QSqlQuery qry;

    qry.prepare( "INSERT INTO names "
                "(id, firstname, lastname) "
                "VALUES "
                "(1, 'John', 'Doe')" );
    if( !qry.exec() )
        qDebug() << qry.lastError();

    qry.prepare( "INSERT INTO names "
                "(id, firstname, lastname) "
                "VALUES"
                "(2, 'Jane', 'Doe')" );
    if( !qry.exec() )
        qDebug() << qry.lastError();

    qry.prepare( "INSERT INTO names "
                "(id, firstname, lastname) "
                "VALUES "
                "(3, 'James', 'Doe')" );
    if( !qry.exec() )
        qDebug() << qry.lastError();

}

void Widget::initializeModel()
{
    m_model = new QSqlTableModel(this, m_db);

    m_model->setTable("names");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();

    m_model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    m_model->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    m_model->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
}

void Widget::slot_pbtUpdate()
{
    QSqlQuery qry;
    qry.prepare( "UPDATE names "
                "SET firstname = 'Eddy', "
                "lastname = 'Kim' WHERE id = 1" );
    if( !qry.exec() )
        qDebug() << qry.lastError();

    m_model->setTable("names");
    m_model->select();
    ui->tableView->setModel(m_model);
}

void Widget::slot_pbtDelete()
{
    QSqlQuery qry;

    qry.prepare( "DELETE FROM names WHERE id = 1" );
    if( !qry.exec() )
        qDebug() << qry.lastError();

    m_model->setTable("names");
    m_model->select();
    ui->tableView->setModel(m_model);
}
