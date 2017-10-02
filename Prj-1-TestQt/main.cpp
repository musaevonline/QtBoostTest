#include<QApplication>
#include"mywindow.h"
int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    MyWindow *window=new MyWindow;
    Str *str=new Str();
    window->show();
    QObject::connect(window,SIGNAL(Register(QString)),str,SLOT(Register(QString)));
    QObject::connect(window,SIGNAL(Inverse(QString)),str,SLOT(Inverse(QString)));
    QObject::connect(window,SIGNAL(Simple(QString)),str,SLOT(Simple(QString)));
    QObject::connect(window,SIGNAL(Full(QString)),str,SLOT(Full(QString)));
    return app.exec();
}
