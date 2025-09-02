#include "registwidget.h"
#include "ui_registwidget.h"
#include "sqltools.h"
#include <QMessageBox>

registWidget::registWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registWidget)
{
    ui->setupUi(this);

}

registWidget::~registWidget()
{
    delete ui;
}

void registWidget::clear_text()
{
    ui->lineEdit_email->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_account->clear();
    ui->lineEdit_nickname->clear();
    ui->lineEdit_password->clear();
}

void registWidget::closeEvent(QCloseEvent *event)
{
    emit openWindows();
    clear_text();
    event->accept();
}

void registWidget::on_pushButton_sub_clicked()
{

    if(ui->lineEdit_account->text().trimmed().isEmpty() || ui->lineEdit_password->text().trimmed().isEmpty() ||
            ui->lineEdit_email->text().trimmed().isEmpty() || ui->lineEdit_phone->text().trimmed().isEmpty()){
        QMessageBox::critical(this,"ERROR","必填信息不能为空",QMessageBox::Close);
        return;
    }

    int state = SqlTools::insertData(ui->lineEdit_account->text(),ui->lineEdit_password->text(),
                         ui->lineEdit_email->text(),ui->lineEdit_phone->text(),ui->lineEdit_nickname->text());

    if(state == 0){
        QMessageBox::critical(this,"ERROR","注册失败,账号已存在!",QMessageBox::Close);
        return;
    }else if(state == -1){
        QMessageBox::critical(this,"ERROR","注册失败,手机号已存在!",QMessageBox::Close);
        return;
    }else if(state == -2){
        QMessageBox::critical(this,"ERROR","注册失败,邮箱已存在!",QMessageBox::Close);
        return;
    }

    QMessageBox::information(this,"SUCCESS","注册成功!",QMessageBox::Ok);

    emit openWindows();
    clear_text();
    this->close();
}
