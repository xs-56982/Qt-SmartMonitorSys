#ifndef ALARMWIDGET_H
#define ALARMWIDGET_H

#include <QWidget>

namespace Ui {
class alarmWidget;
}

class alarmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit alarmWidget(QWidget *parent = nullptr);
    ~alarmWidget();

private:
    Ui::alarmWidget *ui;
};

#endif // ALARMWIDGET_H
