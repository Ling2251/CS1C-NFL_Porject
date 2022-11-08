#include "displayamericanteam.h"
#include "ui_displayamericanteam.h"

DisplayAmericanTeam::DisplayAmericanTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayAmericanTeam)
{
    ui->setupUi(this);
}

DisplayAmericanTeam::~DisplayAmericanTeam()
{
    delete ui;
}



