#include "loginwidgit.h"
#include "ui_loginwidgit.h"
#include <windows.h>
#include <QMessageBox>
#include "sqltools.h"
#include <QDebug>

loginWidgit::loginWidgit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWidgit),
    regist(new registWidget),
    forget(new forgetWidget),
    widget(new myWidget)
{

    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    if(!SqlTools::connectDataBase()){
        qDebug() << "数据库连接失败";
        return;
    }

    connect(regist,&registWidget::openWindows,this,[=](){ this->show(); });
    connect(forget,&forgetWidget::openWindows,this,[=](){ this->show(); });
    connect(widget,&myWidget::openWindows,this,[=](){ widget = nullptr; this->show(); });
}

loginWidgit::~loginWidgit()
{
    delete ui;
}

void loginWidgit::on_pushButton_regist_clicked()
{
    regist->show();
    this->hide();
}

void loginWidgit::mouseMoveEvent(QMouseEvent *event)
{
    ReleaseCapture();  // 释放当前鼠标捕获
    // 发送系统命令：SC_MOVE + HTCAPTION 组合模拟标题栏拖动
    SendMessage(HWND(winId()), WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
}

void loginWidgit::on_pushButton_close_clicked()
{
    int state = QMessageBox::question(this,"提示","是否关闭窗口!",QMessageBox::Ok|QMessageBox::No);
    if(state == QMessageBox::Ok){
        this->close();
    }
}

void loginWidgit::on_pushButton_forgetpass_clicked()
{
    this->hide();
    forget->show();
}

void loginWidgit::on_pushButton_login_clicked()
{
    if(ui->lineEdit_account->text().trimmed().isEmpty() || ui->lineEdit_password->text().trimmed().isEmpty() ){
        QMessageBox::critical(this,"ERROR","输入信息不能为空",QMessageBox::Close);
        return;
    }

    bool state = SqlTools::queryData(ui->lineEdit_account->text(),ui->lineEdit_password->text());
    if(!state){
        ui->label_message->setText("账号或密码错误!");
        return;
    }

    if(widget == nullptr){
        widget = new myWidget;
        connect(widget,&myWidget::openWindows,this,[=](){ widget = nullptr; this->show(); });
    }
    this->close();
    widget->show();
}
