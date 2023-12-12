#include "mainwindow.h"
#include<QTextCodec>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.setWindowTitle("Translate");
    w.show();
    return a.exec();
}
