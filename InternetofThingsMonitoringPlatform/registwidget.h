#ifndef REGISTWIDGET_H
#define REGISTWIDGET_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class registWidget;
}

class registWidget : public QWidget
{
    Q_OBJECT

public:
    explicit registWidget(QWidget *parent = nullptr);
    ~registWidget();
    void clear_text();

signals:
    void openWindows();

private:
    Ui::registWidget *ui;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_sub_clicked();
};

#endif // REGISTWIDGET_H
