#include "removecardialog.h"
#include "ui_removecardialog.h"
#include "database.h"
removecardialog::removecardialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecardialog)
{
    ui->setupUi(this);
}

removecardialog::~removecardialog()
{
    delete ui;
}

void removecardialog::on_removeCarDialogConfirmButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.removeCar(*ui);
    carRentalDatabase.closeConnection();
}


void removecardialog::on_removeCarDialogCancelButton_clicked()
{
    close();
}

