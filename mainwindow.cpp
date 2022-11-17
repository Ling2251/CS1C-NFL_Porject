#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "loginform.h"
#include "helpbutton.h"
#include "NFL_input.h"
#include"string"
#include"sstream"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QSortFilterProxyModel>
using namespace std;


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    connect(loginForm, &LoginForm::on_expandTeamsButton_clicked, this, &MainWindow::expandTables);
    ui->setupUi(this);
    ListDisplay();
    ui->NFCWidget->setVisible(false);
    ui->AFCWidget->setVisible(false);

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


void MainWindow::on_Login_clicked()
{
    LoginForm login;
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
/*
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
    QStringList hLabels;
    hLabels << "Team Name" << "Stadium Name" << "Seating Capacity" << "Location" << "Conference" << "Division"
            << "Surface Type" << "Roof Type" << "Date Opened";
    ui->teamWidget->setHorizontalHeaderLabels(hLabels);

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
*/


/*
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
    QStringList hLabels;
    hLabels << "Team Name" << "Stadium Name" << "Seating Capacity" << "Location" << "Conference" << "Division"
            << "Surface Type" << "Roof Type" << "Date Opened";
    ui->teamWidget->setHorizontalHeaderLabels(hLabels);

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
    QStringList hLabels;
    hLabels << "Team Name" << "Stadium Name" << "Seating Capacity" << "Location" << "Conference" << "Division"
            << "Surface Type" << "Roof Type" << "Date Opened";
    ui->teamWidget->setHorizontalHeaderLabels(hLabels);

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
    QStringList hLabels;
    hLabels << "Team Name" << "Stadium Name" << "Seating Capacity" << "Location" << "Conference" << "Division"
            << "Surface Type" << "Roof Type" << "Date Opened";
    ui->teamWidget->setHorizontalHeaderLabels(hLabels);

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
*/

void MainWindow::ListDisplay(){

    ui->teamWidget->setColumnCount(9);
    ui->teamWidget->setRowCount(AR_SIZE);
    ui->AFCWidget->setColumnCount(9);
    ui->AFCWidget->setRowCount(1);
    ui->NFCWidget->setColumnCount(9);
    ui->NFCWidget->setRowCount(1);

    int AFCTeams = -1;      // set it to -1 so when the loop started to count it goes to 0 for one.
    int NFLTeams = -1;

    // defulat is to display all team.
    bool DisplayAFCTeam = false;

    // Set the header labels for the table widget we have
    QStringList hLabels;
    hLabels << "Team Name" << "Stadium Name" << "Seating Capacity" << "Location" << "Conference" << "Division"
            << "Surface Type" << "Roof Type" << "Date Opened";
    ui->teamWidget->setHorizontalHeaderLabels(hLabels);
    ui->AFCWidget->setHorizontalHeaderLabels(hLabels);
    ui->NFCWidget->setHorizontalHeaderLabels(hLabels);

    // gave the input file
    QString fName = ":/InputFiles/NFL_Information_Input.txt";
    arr->inputFn(fName, arr, AR_SIZE);

    // insert the data into cells and also check and stored the NFL/ AFC team into different teams to display later
    for(int i = 0; i < ui->teamWidget->rowCount(); i++)
    {
        QTableWidgetItem *item;     // new pointer
        QTableWidgetItem *item2;

        //check to see if the team are AFC teams
        if(arr[i].getConference()[0] == 'A')
        {
            DisplayAFCTeam = true;
            AFCTeams++; // get the number of AFC teams in the list
            ui->AFCWidget->setRowCount(AFCTeams + 1);
        } else {
            NFLTeams++; // get the number of NFL teams in the list
            DisplayAFCTeam = false;
            ui->NFCWidget->setRowCount(NFLTeams + 1);
        }

        // loop through all the team in the list and get the data
        for(int j = 0; j < ui->teamWidget->columnCount(); j++)
        {
            item = new QTableWidgetItem;    // set a new pointer
            item2 = new QTableWidgetItem;   // set a new pointer

            // used the get function to input all the data to the list by column
            switch (j) {
                case 0: item->setText(QString::fromStdString(arr[i].getTeamName()));
                        item2->setText(QString::fromStdString(arr[i].getTeamName()));
                    break;
                case 1: item->setText(QString::fromStdString(arr[i].getStadiumName()));
                        item2->setText(QString::fromStdString(arr[i].getStadiumName()));
                    break;
                case 2: item->setText(QString::fromStdString(to_string(arr[i].getSeatingCapacity())));
                        item2->setText(QString::fromStdString(to_string(arr[i].getSeatingCapacity())));
                    break;
                case 3: item->setText(QString::fromStdString(arr[i].getLocation()));
                        item2->setText(QString::fromStdString(arr[i].getLocation()));
                    break;
                case 4: item->setText(QString::fromStdString(arr[i].getConference()));
                        item2->setText(QString::fromStdString(arr[i].getConference()));
                    break;
                case 5: item->setText(QString::fromStdString(arr[i].getDivision()));
                        item2->setText(QString::fromStdString(arr[i].getDivision()));
                    break;
                case 6: item->setText(QString::fromStdString(arr[i].getSurfaceType()));
                    item2->setText(QString::fromStdString(arr[i].getSurfaceType()));
                    break;
                case 7: item->setText(QString::fromStdString(arr[i].getStadiumRoofType()));
                        item2->setText(QString::fromStdString(arr[i].getStadiumRoofType()));
                    break;
                case 8: item->setText(QString::fromStdString(to_string(arr[i].getDateOpened())));
                        item2->setText(QString::fromStdString(to_string(arr[i].getDateOpened())));
                    break;
            }

            // default display the original list
            // Qt::ItemIsEditable flags is so the user can interact with the list
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->teamWidget->setItem(i, j, item);

            // check to see if the user wants to see only AFC or NFL teams
            if(DisplayAFCTeam == true)
            {
                item2->setFlags(item2->flags() ^ Qt::ItemIsEditable);
                // display only AFC teams
                ui->AFCWidget->setItem(AFCTeams, j, item2);
            }
            else
            {
                item2->setFlags(item2->flags() ^ Qt::ItemIsEditable);
                // display only NFC teams
                ui->NFCWidget->setItem(NFLTeams, j, item2);
            }
        }
        // totalCap function is at NFL_input.cpp file and it will return a integer
        // total size is initialize at MainWindow.h file
        totalSize = arr->totalCap(arr);
        // outputing the totalsize is display to the TotalCapacity button
        ui->TotalCapacity->setText(QString::fromStdString(to_string(totalSize)));
    }

    // used the built-in function in the table widget to sort all the data throughout the list
    // QHeaderView::ResizeToContents is a flage that will automatically resize the row and colmon size
    //  if it has changed
    ui->teamWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->teamWidget->setSortingEnabled(true);
    ui->NFCWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->NFCWidget->setSortingEnabled(true);
    ui->AFCWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->AFCWidget->setSortingEnabled(true);
}


// The admin has the ability to upload a new team by reading another input file after logging in

void MainWindow::expandTables(){
    // set a new array for the new team list
    NFLInput arr2[1];

    // reset all rows and columns to 0 so when call the listDisplay function
    // it will have the right numbers
    ui->teamWidget->setColumnCount(0);
    ui->teamWidget->setRowCount(0);
    ui->AFCWidget->setColumnCount(0);
    ui->AFCWidget->setRowCount(0);
    ui->NFCWidget->setColumnCount(0);
    ui->NFCWidget->setRowCount(0);

    // call the table with orginal team list read in already
    ListDisplay();

    // read in the new input file for the new team
    QString fileName = (":/InputFiles/NFL_New_Team.txt");
    arr2->inputFn(fileName,arr2, 1);    // 1 because ther is only one team to add

    //set the row to the last row of the list that is displaying
    int rows = ui->teamWidget->rowCount();
    // addting one because there is only one team added
    ui->teamWidget->setRowCount(rows + 1);

    // set new item pointer to point the data into the list
    QTableWidgetItem *item3;
    QTableWidgetItem *item4;

    // set the new team to the last row
    int AFCRows = ui->AFCWidget->rowCount();
    int NFLRows = ui->NFCWidget->rowCount();


    // arr2[0] the 0 is because there is only one new team so the index is zero
    if(arr2[0].getConference()[0] == 'A')
    {
        ui->AFCWidget->setRowCount(AFCRows + 1);
    } else {
        ui->NFCWidget->setRowCount(NFLRows + 1);
    }

    // loop through all the team in the list and get the data
    for(int j = 0; j < 9; j++)
    {
        item3 = new QTableWidgetItem;       // set a new pointer
        item4 = new QTableWidgetItem;       // set a new pointer

        // used the get function to input all the data to the list by column
        switch (j) {
            case 0: item3->setText(QString::fromStdString(arr2[0].getTeamName()));
                    item4->setText(QString::fromStdString(arr2[0].getTeamName()));
                break;
            case 1: item3->setText(QString::fromStdString(arr2[0].getStadiumName()));
                    item4->setText(QString::fromStdString(arr2[0].getStadiumName()));
                break;
            case 2: item3->setText(QString::fromStdString(to_string(arr2[0].getSeatingCapacity())));
                    item4->setText(QString::fromStdString(to_string(arr2[0].getSeatingCapacity())));
                break;
            case 3: item3->setText(QString::fromStdString(arr2[0].getLocation()));
                    item4->setText(QString::fromStdString(arr2[0].getLocation()));
                break;
            case 4: item3->setText(QString::fromStdString(arr2[0].getConference()));
                    item4->setText(QString::fromStdString(arr2[0].getConference()));
                break;
            case 5: item3->setText(QString::fromStdString(arr2[0].getDivision()));
                    item4->setText(QString::fromStdString(arr2[0].getDivision()));
                break;
            case 6: item3->setText(QString::fromStdString(arr2[0].getSurfaceType()));
                    item4->setText(QString::fromStdString(arr2[0].getSurfaceType()));
                break;
            case 7: item3->setText(QString::fromStdString(arr2[0].getStadiumRoofType()));
                    item4->setText(QString::fromStdString(arr2[0].getStadiumRoofType()));
                break;
            case 8: item3->setText(QString::fromStdString(to_string(arr2[0].getDateOpened())));
                    item4->setText(QString::fromStdString(to_string(arr2[0].getDateOpened())));
                break;
        }

        // default display the original list
        // Qt::ItemIsEditable flags is so the user can interact with the list
        item3->setFlags(item3->flags() ^ Qt::ItemIsEditable);
        ui->teamWidget->setItem(rows, j, item3);

        // check if the new team conference is AFC or NFL
        if(arr2[0].getConference()[0] == 'A')
        {
            item4->setFlags(item4->flags() ^ Qt::ItemIsEditable);
            ui->AFCWidget->setItem(AFCRows, j, item4);
        }
        else
        {
            item4->setFlags(item4->flags() ^ Qt::ItemIsEditable);
            ui->NFCWidget->setItem(NFLRows, j, item4);
        }
        ui->NFCWidget->setSortingEnabled(true);
        // add the seating capacity to the total size
        // total size is initialize at MainWindow.h file
        totalSize += arr2[0].getSeatingCapacity();
        // display the number on a button
        ui->TotalCapacity->setText(QString::fromStdString(to_string(totalSize)));

    }

}

// have to use the log in on the left top conner.
void MainWindow::on_actionLog_triggered()
{
    loginForm->setModal(true);
    loginForm->exec();
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



