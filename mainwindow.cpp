
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"contact.h"
#include"helpbutton.h"
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Gave some of the buttom icon
    ui->HelpButton->setIcon(QIcon(":/Images/Help.jpg"));
    ui->ContactUsButton->setIcon(QIcon(":/Images/Contact us.png"));
    ui->ContactUsButton->setText("Contact Us");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ContactUsButton_clicked()
{
    contact contact;
    contact.setModal(true);
    contact.exec();
}


void MainWindow::on_HelpButton_clicked()
{
    helpButton helpButton;
    helpButton.setModal(true);
    helpButton.exec();
}

