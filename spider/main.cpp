#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMap<QString, QString> sites;
    sites["avito"] = "https://www.avito.ru/tver/noutbuki?cd=1";
    MainWindow w(sites);

    w.show();

    return a.exec();
}
