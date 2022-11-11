#include "loginadmin.h"
#include "ui_loginadmin.h"
#include <QMessageBox>
#include <QStackedWidget>

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

void LoginAdmin::on_pushButton_clicked() //Admin Login
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (username == "Admin" && password == "1234")
    {
        QMessageBox::information(this, "Login", "Logged in");
        //hide(); //exits back to main screen
        ui->stackedWidget->setCurrentIndex(1);//Redirect you to second page to add NEW team


    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or Password is Incorrect");
    }

}




void LoginAdmin::on_Admin_cancel_clicked() //Admin Team Page (page 2)
{
    hide(); //closes admin add team page
}


void LoginAdmin::on_Admin_Add_clicked() //Admin Adds new team
{

}

