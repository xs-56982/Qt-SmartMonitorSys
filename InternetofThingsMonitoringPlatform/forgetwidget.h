#ifndef FORGETWIDGET_H
#define FORGETWIDGET_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class forgetWidget;
}

class forgetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit forgetWidget(QWidget *parent = nullptr);
    ~forgetWidget();
    void clearText();

signals:
    void openWindows();

private:
    Ui::forgetWidget *ui;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_clicked();
};

#endif // FORGETWIDGET_H
