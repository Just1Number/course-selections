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
    JsonTranslator get_json;
//    if(get_json.read_file()){
//        vote_data = get_json.getVoteData();
//        vote_data.matchCourses();
//        vector<QString> matchlist = vote_data.matchlist();
//        QString matches;
//        for (int match_index = 0; match_index < matchlist.size(); ++match_index) {
//            matches.append(matchlist[match_index]);
//            matches.append(", ");
//        }
//        this->msgbox.setText(matches);
//        this->msgbox.setWindowTitle("Information");
//        this->msgbox.exec();
//    } else {
//        this->msgbox.setText("Button pushed");
//        this->msgbox.setWindowTitle("Information");
//        this->msgbox.exec();
//    }
}
