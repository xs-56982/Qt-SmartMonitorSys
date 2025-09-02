#ifndef DATAMONITORWIDGET_H
#define DATAMONITORWIDGET_H

#include <QWidget>

namespace Ui {
class dataMonitorWidget;
}

class dataMonitorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit dataMonitorWidget(QWidget *parent = nullptr);
    ~dataMonitorWidget();

private:
    Ui::dataMonitorWidget *ui;
};

#endif // DATAMONITORWIDGET_H
