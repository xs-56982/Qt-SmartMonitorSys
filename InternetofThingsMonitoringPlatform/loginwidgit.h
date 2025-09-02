#ifndef LOGINWIDGIT_H
#define LOGINWIDGIT_H

#include <QWidget>
#include "registwidget.h"
#include "forgetwidget.h"
#include "mywidget.h"

namespace Ui {
class loginWidgit;
}

class loginWidgit : public QWidget
{
    Q_OBJECT

public:
    explicit loginWidgit(QWidget *parent = nullptr);
    ~loginWidgit();

private slots:
    void on_pushButton_regist_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_forgetpass_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::loginWidgit *ui;
    registWidget *regist;
    forgetWidget *forget;
    myWidget *widget;

    // QWidget interface
protected:
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // LOGINWIDGIT_H
