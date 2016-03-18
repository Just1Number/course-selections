#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>
#include <QTextBrowser>
#include <QString>

namespace Ui {
class MessageBox;
}

class MessageBox : public QDialog
{
    Q_OBJECT

public:
    void display_msg(QString str);
    explicit MessageBox(QWidget *parent = 0);
    ~MessageBox();

private:
    Ui::MessageBox *ui;
    QTextBrowser textBrowser;
};

#endif // MESSAGEBOX_H
