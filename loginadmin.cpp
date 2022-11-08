#include "loginadmin.h"
#include "ui_loginadmin.h"
#include <QMessageBox>

LoginAdmin::LoginAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

void LoginAdmin::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (username == "Admin" && password == "1234")
    {
        QMessageBox::information(this, "Login", "Logged in");
        hide();

    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or Password is Incorrect");
    }

}

