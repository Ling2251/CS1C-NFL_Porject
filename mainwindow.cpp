#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "loginadmin.h"
#include "helpbutton.h"
#include "NFL_input.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Gave some of the buttom icon
    ui->HelpButton->setIcon(QIcon(":/Images/Help.jpg"));
    ui->ContactUsButton->setIcon(QIcon(":/Images/Contact us.png"));
    ui->ContactUsButton->setText("Contact Us");



    QString fName = ":/InputFiles/NFL_Information_Input.txt";
    arr->inputFn(fName, arr, AR_SIZE);

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


void MainWindow::on_Login_clicked()
{
    LoginAdmin login;
    login.setModal(true);
    login.exec();

    //QString username = ui->lineEdit->text();
}


void MainWindow::on_HelpButton_clicked()
{
   helpButton helpButton;
   helpButton.setModal(true);
   helpButton.exec();
}

void MainWindow::on_TeamName_clicked()
{
    ui->teamWidget->setRowCount(32);
    ui->teamWidget->setColumnCount(1);
    for (int i=0; i<32; i++) {
        ui->teamWidget->setItem(0,i,  new QTableWidgetItem(arr[i].getTeamName().c_str())) ;
    }

}


void MainWindow::on_teamWidget_cellActivated(int row, int column)
{

}

