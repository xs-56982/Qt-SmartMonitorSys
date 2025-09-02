#include "mywidget.h"
#include "ui_mywidget.h"
#include "userwidget.h"
#include "devicewidget.h"
#include "datamonitorwidget.h"
#include "alarmwidget.h"
#include "logwidgit.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    insertWidgets();

}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::insertWidgets()
{
    ui->stackedWidget->insertWidget(0,new userWidget);
    ui->stackedWidget->insertWidget(1,new deviceWidget);
    ui->stackedWidget->insertWidget(2,new dataMonitorWidget);
    ui->stackedWidget->insertWidget(3,new alarmWidget);
    ui->stackedWidget->insertWidget(4,new logWidgit);
}


void myWidget::on_pushButton_clicked()
{
    emit openWindows();
    this->close();
}
