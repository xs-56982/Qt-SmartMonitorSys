#include "mywidget.h"
#include "loginwidgit.h"
#include "userManager/userwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWidgit w;
    w.show();
    return a.exec();
}
