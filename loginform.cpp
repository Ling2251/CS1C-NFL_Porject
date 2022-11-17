#include "loginform.h"
#include "ui_loginform.h"
#include <QFile>
#include "NFL_input.h"

LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    ui->teamsAdded->setVisible(false);
    ui->invalidLabel->setVisible(false);
    ui->expandTeamsButton->setVisible(false);
    ui->progressBar->setVisible(false);
//    connect(ui->expandTeamsButton, &QPushButton::clicked, this, &LoginForm::on_expandTeamsButton_clicked);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_clicked()
{
    if(ui->userName->text().toStdString() == "admin" && ui->passWord->text().toStdString() == "admin123")
    {
        ui->passWord->setVisible(false);
        ui->userName->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        ui->invalidLabel->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->expandTeamsButton->setVisible(true);
        ui->adminLabel->setText("Admin Control Panel");
    } else ui->invalidLabel->setVisible(true);
}

void LoginForm::on_expandTeamsButton_released()
{
    ui->progressBar->setVisible(true);
    ui->progressBar->setValue(0);
    for(int i = 0; i <= 100; i++) ui->progressBar->setValue(i);
    ui->expandTeamsButton->setEnabled(false);
    ui->teamsAdded->setVisible(true);
}

