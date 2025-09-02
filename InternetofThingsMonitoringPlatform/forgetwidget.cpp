#include "forgetwidget.h"
#include "ui_forgetwidget.h"
#include "sqltools.h"
#include <QMessageBox>

forgetWidget::forgetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forgetWidget)
{
    ui->setupUi(this);
}

forgetWidget::~forgetWidget()
{
    delete ui;
}

void forgetWidget::clearText()
{
    ui->lineEdit_forget_name->clear();
    ui->lineEdit_forget_pass->clear();
    ui->lineEdit_forget_email_phone->clear();
}

void forgetWidget::closeEvent(QCloseEvent *event)
{
    emit openWindows();
    clearText();
    event->accept();
}

void forgetWidget::on_pushButton_clicked()
{
    if(ui->lineEdit_forget_name->text().trimmed().isEmpty() || ui->lineEdit_forget_pass->text().trimmed().isEmpty() ||
            ui->lineEdit_forget_email_phone->text().trimmed().isEmpty()){
        QMessageBox::critical(this,"ERROR","输入信息不能为空",QMessageBox::Close);
        return;
    }

    if(!SqlTools::queryData(ui->lineEdit_forget_name->text())){
        QMessageBox::critical(this,"ERROR","用户不存在",QMessageBox::Close);
        return;
    }

    if(!SqlTools::updateData(ui->lineEdit_forget_name->text(),ui->lineEdit_forget_email_phone->text(),
                             ui->lineEdit_forget_pass->text())){
        QMessageBox::critical(this,"ERROR","手机号或邮箱错误",QMessageBox::Close);
        return;
    }

    QMessageBox::information(this,"SUCCESS","修改成功",QMessageBox::Close);
    emit openWindows();
    clearText();
    this->close();
}
