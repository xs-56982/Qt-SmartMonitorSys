#include "logwidgit.h"
#include "ui_logwidgit.h"

logWidgit::logWidgit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logWidgit)
{
    ui->setupUi(this);
}

logWidgit::~logWidgit()
{
    delete ui;
}
