#include "mainwindow.h"
#include "algorithm.h"
#include "jsontranslator.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    JsonTranslator jasy;
    jasy.read_file();
    return a.exec();
}
