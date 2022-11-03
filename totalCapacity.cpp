#include "mainwindow.h"
#include "ui_mainwindow.h"


long calculateCapa(fstream & filename)
{
    long totalList[30];
    int num = 30000;
    for(int i=0;i<400;i++)
    {
        if(i>num)
        {
            filename[i] >> totalList[i];
        }
    }
}
