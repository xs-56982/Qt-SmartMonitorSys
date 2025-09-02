#include "alarmwidget.h"
#include "ui_alarmwidget.h"

alarmWidget::alarmWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::alarmWidget)
{
    ui->setupUi(this);
}

alarmWidget::~alarmWidget()
{
    delete ui;
}
