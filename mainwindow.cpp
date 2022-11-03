
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Gave some of the buttom icon
    ui->HelpButton->setIcon(QIcon(":/Images/Help.jpg"));
    ui->ContactUsButton->setIcon(QIcon(":/Images/Contact us.png"));
    ui->ContactUsButton->setText("Hello, we are glad that you are contact us, our phone number is: 110220330,"
                                       "call us in any time.");

}

MainWindow::~MainWindow()
{
    delete ui;
}
