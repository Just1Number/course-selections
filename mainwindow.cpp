#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    VotingData vote_data;
    vote_data.matchCourses();
    this->msgbox.setText("Button pushed");
    this->msgbox.setWindowTitle("Information");
    this->msgbox.exec();
}
