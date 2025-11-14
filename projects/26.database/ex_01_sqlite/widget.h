#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QSqlDatabase m_db;
    QSqlTableModel *m_model;

    bool initializeDataBase();
    void creationTable();
    void insertDataToTable();
    void initializeModel();

private slots:
    void slot_pbtUpdate();
    void slot_pbtDelete();


};
#endif // WIDGET_H
