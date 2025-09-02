#include "datamonitorwidget.h"
#include "ui_datamonitorwidget.h"

dataMonitorWidget::dataMonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataMonitorWidget)
{
    ui->setupUi(this);



}

dataMonitorWidget::~dataMonitorWidget()
{
    delete ui;
}
