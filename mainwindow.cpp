
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "loginadmin.h"
#include "helpbutton.h"
#include "NFL_input.h"
#include"string"
#include"sstream"
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
    ui->teamWidget->setRowCount(32); //32
    ui->teamWidget->setColumnCount(9);    //9
    ui->teamWidget->setColumnWidth(0,200);

    int i, j, arraysize = 32;

    NFLInput temp;

    // sort by team name
    for(i = 0; i<arraysize; i++) {
        for(j = i+1; j<arraysize; j++)
        {
            if(arr[j].getTeamName() < arr[i].getTeamName()) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // print the table headers
    ui->teamWidget->setItem(0,0, new QTableWidgetItem("Team Name"));
    ui->teamWidget->setItem(0,1, new QTableWidgetItem("Stadium Name"));
    ui->teamWidget->setItem(0,2, new QTableWidgetItem("Seating Capacity"));
    ui->teamWidget->setItem(0,3, new QTableWidgetItem("Location"));
    ui->teamWidget->setItem(0,4, new QTableWidgetItem("Conference"));
    ui->teamWidget->setItem(0,5, new QTableWidgetItem("Division"));
    ui->teamWidget->setItem(0,6, new QTableWidgetItem("Surface Type"));
    ui->teamWidget->setItem(0,7, new QTableWidgetItem("Stadium Roof Type"));
    ui->teamWidget->setItem(0,8, new QTableWidgetItem("Date Opened"));

    // fill out the table
    for (i=0; i<arraysize; i++) {
        ui->teamWidget->setItem(i, 0, new QTableWidgetItem(arr[i].getTeamName().c_str()));
        ui->teamWidget->setItem(i, 1, new QTableWidgetItem(arr[i].getStadiumName().c_str()));
        ui->teamWidget->setItem(i, 2, new QTableWidgetItem(to_string(arr[i].getSeatingCapacity()).c_str()));
        ui->teamWidget->setItem(i, 3, new QTableWidgetItem(arr[i].getLocation().c_str()));
        ui->teamWidget->setItem(i, 4, new QTableWidgetItem(arr[i].getConference().c_str()));
        ui->teamWidget->setItem(i, 5, new QTableWidgetItem(arr[i].getDivision().c_str()));
        ui->teamWidget->setItem(i, 6, new QTableWidgetItem(arr[i].getSurfaceType().c_str()));
        ui->teamWidget->setItem(i, 7, new QTableWidgetItem(arr[i].getStadiumRoofType().c_str()));
        ui->teamWidget->setItem(i, 8, new QTableWidgetItem(to_string(arr[i].getDateOpened()).c_str()));
    }

}

void MainWindow::on_TotalCapacity_clicked()
{
    NFLInput tempCapacity;

    // declare a total num, and two temp num to store seating num
    long total = 0;
    int temp1 = 0;
    int temp2 = 0;

    // for loop to calculate the total
    for(int i=0; i<AR_SIZE;i++)
    {
        temp1 = arr[i].getSeatingCapacity();
        temp2 = arr[i+1].getSeatingCapacity();
        total += temp1;
        if(temp1 == temp2)
        {
            total -= temp2;
        }

    }

    // change the long datatype to string then it can output as a text
        stringstream stream;
        stream << total;
        string total_to_string;
        total_to_string = stream.str();
        ui->TotalCapacity->setText(total_to_string.c_str());
}



void MainWindow::on_Stadiumposition_clicked()
{
    ui->teamWidget->setRowCount(32); //32
    ui->teamWidget->setColumnCount(9);    //9
    ui->teamWidget->setColumnWidth(0,200);

    int i, j, arraysize = 32;

    NFLInput temp;

    // sort by team stadium
    for(i = 0; i<arraysize; i++) {
        for(j = i+1; j<arraysize; j++)
        {
            if(arr[j].getStadiumName() < arr[i].getStadiumName()) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // print the table headers
    ui->teamWidget->setItem(0,0, new QTableWidgetItem("Team Name"));
    ui->teamWidget->setItem(0,1, new QTableWidgetItem("Stadium Name"));
    ui->teamWidget->setItem(0,2, new QTableWidgetItem("Seating Capacity"));
    ui->teamWidget->setItem(0,3, new QTableWidgetItem("Location"));
    ui->teamWidget->setItem(0,4, new QTableWidgetItem("Conference"));
    ui->teamWidget->setItem(0,5, new QTableWidgetItem("Division"));
    ui->teamWidget->setItem(0,6, new QTableWidgetItem("Surface Type"));
    ui->teamWidget->setItem(0,7, new QTableWidgetItem("Stadium Roof Type"));
    ui->teamWidget->setItem(0,8, new QTableWidgetItem("Date Opened"));

    // fill out the table
    for (i=0; i<arraysize; i++) {
        ui->teamWidget->setItem(i, 0, new QTableWidgetItem(arr[i].getTeamName().c_str()));
        ui->teamWidget->setItem(i, 1, new QTableWidgetItem(arr[i].getStadiumName().c_str()));
        ui->teamWidget->setItem(i, 2, new QTableWidgetItem(to_string(arr[i].getSeatingCapacity()).c_str()));
        ui->teamWidget->setItem(i, 3, new QTableWidgetItem(arr[i].getLocation().c_str()));
        ui->teamWidget->setItem(i, 4, new QTableWidgetItem(arr[i].getConference().c_str()));
        ui->teamWidget->setItem(i, 5, new QTableWidgetItem(arr[i].getDivision().c_str()));
        ui->teamWidget->setItem(i, 6, new QTableWidgetItem(arr[i].getSurfaceType().c_str()));
        ui->teamWidget->setItem(i, 7, new QTableWidgetItem(arr[i].getStadiumRoofType().c_str()));
        ui->teamWidget->setItem(i, 8, new QTableWidgetItem(to_string(arr[i].getDateOpened()).c_str()));
    }
}


void MainWindow::on_SeatingCapacityButtoon_clicked()
{
    ui->teamWidget->setRowCount(32); //32
    ui->teamWidget->setColumnCount(9);    //9
    ui->teamWidget->setColumnWidth(0,200);

    int i, j, arraysize = 32;

    NFLInput temp;

    // sort by team seating capacity
    for(i = 0; i<arraysize; i++) {
        for(j = i+1; j<arraysize; j++)
        {
            if(arr[j].getSeatingCapacity() < arr[i].getSeatingCapacity()) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // print the table headers
    ui->teamWidget->setItem(0,0, new QTableWidgetItem("Team Name"));
    ui->teamWidget->setItem(0,1, new QTableWidgetItem("Stadium Name"));
    ui->teamWidget->setItem(0,2, new QTableWidgetItem("Seating Capacity"));
    ui->teamWidget->setItem(0,3, new QTableWidgetItem("Location"));
    ui->teamWidget->setItem(0,4, new QTableWidgetItem("Conference"));
    ui->teamWidget->setItem(0,5, new QTableWidgetItem("Division"));
    ui->teamWidget->setItem(0,6, new QTableWidgetItem("Surface Type"));
    ui->teamWidget->setItem(0,7, new QTableWidgetItem("Stadium Roof Type"));
    ui->teamWidget->setItem(0,8, new QTableWidgetItem("Date Opened"));

    // fill out the table
    for (i=0; i<arraysize; i++) {
        ui->teamWidget->setItem(i, 0, new QTableWidgetItem(arr[i].getTeamName().c_str()));
        ui->teamWidget->setItem(i, 1, new QTableWidgetItem(arr[i].getStadiumName().c_str()));
        ui->teamWidget->setItem(i, 2, new QTableWidgetItem(to_string(arr[i].getSeatingCapacity()).c_str()));
        ui->teamWidget->setItem(i, 3, new QTableWidgetItem(arr[i].getLocation().c_str()));
        ui->teamWidget->setItem(i, 4, new QTableWidgetItem(arr[i].getConference().c_str()));
        ui->teamWidget->setItem(i, 5, new QTableWidgetItem(arr[i].getDivision().c_str()));
        ui->teamWidget->setItem(i, 6, new QTableWidgetItem(arr[i].getSurfaceType().c_str()));
        ui->teamWidget->setItem(i, 7, new QTableWidgetItem(arr[i].getStadiumRoofType().c_str()));
        ui->teamWidget->setItem(i, 8, new QTableWidgetItem(to_string(arr[i].getDateOpened()).c_str()));
    }
}




void MainWindow::on_LocationButton_clicked()
{
    ui->teamWidget->setRowCount(32); //32
    ui->teamWidget->setColumnCount(9);    //9
    ui->teamWidget->setColumnWidth(0,200);

    int i, j, arraysize = 32;

    NFLInput temp;

    // sort by team seating capacity
    for(i = 0; i<arraysize; i++) {
        for(j = i+1; j<arraysize; j++)
        {
            if(arr[j].getLocation() < arr[i].getLocation()) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // print the table headers
    ui->teamWidget->setItem(0,0, new QTableWidgetItem("Team Name"));
    ui->teamWidget->setItem(0,1, new QTableWidgetItem("Stadium Name"));
    ui->teamWidget->setItem(0,2, new QTableWidgetItem("Seating Capacity"));
    ui->teamWidget->setItem(0,3, new QTableWidgetItem("Location"));
    ui->teamWidget->setItem(0,4, new QTableWidgetItem("Conference"));
    ui->teamWidget->setItem(0,5, new QTableWidgetItem("Division"));
    ui->teamWidget->setItem(0,6, new QTableWidgetItem("Surface Type"));
    ui->teamWidget->setItem(0,7, new QTableWidgetItem("Stadium Roof Type"));
    ui->teamWidget->setItem(0,8, new QTableWidgetItem("Date Opened"));

    // fill out the table
    for (i=0; i<arraysize; i++) {
        ui->teamWidget->setItem(i, 0, new QTableWidgetItem(arr[i].getTeamName().c_str()));
        ui->teamWidget->setItem(i, 1, new QTableWidgetItem(arr[i].getStadiumName().c_str()));
        ui->teamWidget->setItem(i, 2, new QTableWidgetItem(to_string(arr[i].getSeatingCapacity()).c_str()));
        ui->teamWidget->setItem(i, 3, new QTableWidgetItem(arr[i].getLocation().c_str()));
        ui->teamWidget->setItem(i, 4, new QTableWidgetItem(arr[i].getConference().c_str()));
        ui->teamWidget->setItem(i, 5, new QTableWidgetItem(arr[i].getDivision().c_str()));
        ui->teamWidget->setItem(i, 6, new QTableWidgetItem(arr[i].getSurfaceType().c_str()));
        ui->teamWidget->setItem(i, 7, new QTableWidgetItem(arr[i].getStadiumRoofType().c_str()));
        ui->teamWidget->setItem(i, 8, new QTableWidgetItem(to_string(arr[i].getDateOpened()).c_str()));
    }
}

// This is where the user can choose to to see all team list or just the NFC team or sthe AFC Team
void MainWindow::on_AllTeam_clicked()
{
    ui->teamWidget->setVisible(true);
    ui->NFCWidget->setVisible(false);
    ui->AFCWidget->setVisible(false);
}


void MainWindow::on_NFCTeam_clicked()
{
    ui->teamWidget->setVisible(false);
    ui->NFCWidget->setVisible(true);
    ui->AFCWidget->setVisible(false);
}


void MainWindow::on_AFCTem_clicked()
{
    ui->teamWidget->setVisible(false);
    ui->NFCWidget->setVisible(false);
    ui->AFCWidget->setVisible(true);
}

