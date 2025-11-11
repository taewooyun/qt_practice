#ifndef WIDGET_H
#define WIDGET_H

#include <QButtonGroup>
#include <QCheckBox>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QButtonGroup *m_chk_group[2]; // 버튼 그룹 생성
    QCheckBox *m_btn_exclusive[3]; // 그룹 0 체크박스 생성
    QCheckBox *m_btn_non_exclusive[3]; // 그룹 1 체크박스 생성

private slots:
    void slot_clicked_1(); // 버튼 리스너 생성
    void slot_clicked_2();
    void slot_check_changed_1(); // 체크박스 리스너 생성
};
#endif // WIDGET_H
