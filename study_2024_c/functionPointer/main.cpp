#include "mainwindow.h"

#include <QApplication>
#include<QDebug>
void func1(int a)
{
    qDebug("hello world");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //func1();
    //函数指针指向地址
    int * p=(int *)4199872;
    void (*pFunc)(int)=(void(*)(int))p;
    pFunc(10);
    qDebug("%d",func1);
    return a.exec();
}
