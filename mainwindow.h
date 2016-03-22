#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QMessageBox>
#include "algorithm.h"
#include "jsontranslator.h"
#include "votingdata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTextBrowser textBrowser;
    QMessageBox msgbox;
    void sleepcp(int milliseconds);
};

#endif // MAINWINDOW_H
