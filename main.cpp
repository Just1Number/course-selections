#include "mainwindow.h"
#include <QApplication>
#include "algorithm.h"
#include "messagebox.h"
#include "jsontranslator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    JsonTranslator jasy;
    jasy.read_file();
    return a.exec();
}
