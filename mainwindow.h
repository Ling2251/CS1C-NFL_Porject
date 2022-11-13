#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <cstring>
#include <QDebug>
#include "NFL_input.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    NFLInput arr[AR_SIZE];
    const int HEADER_SIZE = 9;

private slots:
    void on_ContactUsButton_clicked();

    void on_Login_clicked();

    void on_HelpButton_clicked();

    //void on_TeamName_clicked();



    void on_TotalCapacity_clicked();

    //void on_Stadiumposition_clicked();

    //void on_SeatingCapacityButtoon_clicked();

   // void on_LocationButton_clicked();

    //void on_AllTeam_clicked();

    void on_NFCTeam_clicked();

    void on_AFCTem_clicked();



    void on_AllTeam_clicked();

private:
    Ui::MainWindow *ui;
    void MainWindow::ListDisplay();
};
#endif // MAINWINDOW_H
