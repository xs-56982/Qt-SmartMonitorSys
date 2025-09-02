#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QWidget>

namespace Ui {
class deviceWidget;
}

class deviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit deviceWidget(QWidget *parent = nullptr);
    ~deviceWidget();

private:
    Ui::deviceWidget *ui;
};

#endif // DEVICEWIDGET_H
