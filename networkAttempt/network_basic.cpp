#include "network_basic.h"
#include "ui_network_basic.h"
#include "computations.h"


bool classA = false;
bool classB = false;
bool classC = false;

network_basic::network_basic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::network_basic)
{
    ui->setupUi(this);
    connect(ui->calcButton, SIGNAL(clicked()), this, SLOT(validateInput()));
    connect(ui->classA, SIGNAL(clicked()), this, SLOT(subnetMaskA()));
    connect(ui->classB, SIGNAL(clicked()), this, SLOT(subnetMaskB()));
    connect(ui->classC, SIGNAL(clicked()), this, SLOT(subnetMaskC()));
}

network_basic::~network_basic()
{
    delete ui;
}
void network_basic::subnetMaskA()
{
   return ui->subnetOutput->setText("255.255.255.0");
}
void network_basic::subnetMaskB()
{
    return ui->subnetOutput->setText("255.255.0.0");
}
void network_basic::subnetMaskC()
{
    return ui->subnetOutput->setText("255.0.0.0");
}
void network_basic::validateInput()
{
    QString input = ui->inputLine->text();
    QString subnet = ui->subnetOutput->text();

    computations *data = new computations(input,subnet);
    if(data->checkInput())
    {
        data->compute();
        ui->hostOutput->setText(data->hostIP());
    }
    else{
        ui->inputLine->setText("invalid input");
    }
}
