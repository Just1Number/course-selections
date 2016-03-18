#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString str = "Hi";
    ui->textBrowser->setText(str);;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText("Button pressed");
    QString h = "nein";
    msgbox.show();
    msgbox.display_msg(h);
}
