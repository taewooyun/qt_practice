#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString str1[3] = {"Game", "Office", "Develop"}; // 버튼 그룹 0 목록
    QString str2[3] = {"P&rogramming", "Q&t", "O&S"}; // 버튼 그룹 1 목록
    int xpos = 30;
    int ypos = 30;
    m_chk_group[0] = new QButtonGroup(this);
    m_chk_group[1] = new QButtonGroup(this);


    for(int i = 0 ; i < 3 ; i++)
    {
        m_btn_exclusive[i] = new QCheckBox(str1[i], this);
        m_btn_exclusive[i]->setGeometry(xpos, ypos, 120, 30);
        m_chk_group[0]->addButton(m_btn_exclusive[i]); // 버튼 생성
        connect(m_btn_exclusive[i], SIGNAL(clicked()), this, SLOT(slot_check_changed_1())); // 리스너 등록

        m_btn_non_exclusive[i] = new QCheckBox(str2[i], this);
        m_btn_non_exclusive[i]->setGeometry(xpos + 120, ypos, 120, 30);
        m_chk_group[1]->addButton(m_btn_non_exclusive[i]); //버튼 생성

        ypos += 40;
    }
    m_chk_group[0]->setExclusive(true); // 단일 선택 설정 (radio button)
    m_chk_group[1]->setExclusive(false); // 다중 선택 설정

    m_btn_exclusive[0]->setIcon(QIcon(":resources/browser.png"));
    m_btn_exclusive[1]->setIcon(QIcon(":resources/calendar.png"));
    m_btn_exclusive[2]->setIcon(QIcon(":resources/chat.png"));
    m_btn_non_exclusive[0]->setIcon(QIcon(":resources/editor.png"));
    m_btn_non_exclusive[1]->setIcon(QIcon(":resources/mail.png"));
    m_btn_non_exclusive[2]->setIcon(QIcon(":resources/users.png"));

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(slot_clicked_1())); // pushButton이 clicked가 발생되면 slot_clicked를 실행
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_clicked_2()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_check_changed_1()
{
    for(int i = 0 ; i < 3 ; i++) {
        if(m_btn_exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ", i+1); // 선택 버튼 출력
        }
    }
}

void Widget::slot_clicked_1()
{
    QString str = "";
    for (auto btn : m_chk_group[1]->buttons()) { // 체크 된 버튼 목록 확인
        if(btn->isChecked()) {
            str += btn->text() + ", ";
        }
    }
    str.replace("&&", "&");
    str.remove('&'); // 특수 기호 제거
    if(str != "") ui->label_1->setText(str);
}

void Widget::slot_clicked_2()
{
    m_chk_group[0]->setExclusive(false); // 선택 초기화를 하기 위해 단일 선택 옵션을 해제 해야한다
    for(auto group: m_chk_group){       // 선택 된 버튼 초기화
        for(auto btn: group->buttons())
            btn->setChecked(false);
    }
    m_chk_group[0]->setExclusive(true); //

    ui->label_1->setText("SELECTED SKILLS"); // label 초기화
}
