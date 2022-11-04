#include "helpbutton.h"
#include "ui_helpbutton.h"

helpButton::helpButton(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpButton)
{
    ui->setupUi(this);
}

helpButton::~helpButton()
{
    delete ui;
}
