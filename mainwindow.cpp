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
    VotingData voting_data;
    //voting_data.getMatchlist().push_back("NoWay");
    vector<QString> matchlist;
    matchlist.push_back("Pls dont crash");
    voting_data.setMatchlist(matchlist);
    QString output = voting_data.getMatchlist()[0];
    ui->textBrowser->setText(output);
    voting_data.getMatchlist().push_back("maybe?");
    output = voting_data.getMatchlist()[0];
    ui->textBrowser->append(output);

}
