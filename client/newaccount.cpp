#include "newaccount.h"
#include "ui_newaccount.h"
#include "client.h"
#include<QMessageBox>

newaccount::newaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newaccount)
{
    ui->setupUi(this);
}

newaccount::~newaccount()
{
    delete ui;
}

void newaccount::on_pushButton_clicked()
{
    QString nickname = ui->nickname->text();
    QString password = ui->password->text();
    if (nickname != "" &&  password != "") {
    int return_code = Client::sing_up(nickname, password);
    switch (return_code) {
        case 0:
            QMessageBox::warning(this, "Failed to connect", "No connection to server");
            break;
        case 1:
            QMessageBox::about(this, "Select new nickname", "Nickname is already in use");
            break;
        case 2:
            hide();
            win = new MenuWindow(this, nickname);
            win->show();
        break;

        }
    }
    else {
        QMessageBox::about(this, "Empty fields", "Enter all data");
    }
}
