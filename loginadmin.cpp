#include "loginadmin.h"
#include "ui_loginadmin.h"

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

}

