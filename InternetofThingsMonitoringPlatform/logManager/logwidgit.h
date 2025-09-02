#ifndef LOGWIDGIT_H
#define LOGWIDGIT_H

#include <QWidget>

namespace Ui {
class logWidgit;
}

class logWidgit : public QWidget
{
    Q_OBJECT

public:
    explicit logWidgit(QWidget *parent = nullptr);
    ~logWidgit();

private:
    Ui::logWidgit *ui;
};

#endif // LOGWIDGIT_H
