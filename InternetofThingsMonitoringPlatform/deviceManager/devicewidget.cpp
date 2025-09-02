#include "devicewidget.h"
#include "ui_devicewidget.h"

deviceWidget::deviceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deviceWidget)
{
    ui->setupUi(this);
}

deviceWidget::~deviceWidget()
{
    delete ui;
}
