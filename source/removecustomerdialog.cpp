#include "removecustomerdialog.h"
#include "ui_removecustomerdialog.h"
#include "database.h"
removecustomerdialog::removecustomerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecustomerdialog)
{
    ui->setupUi(this);
}

removecustomerdialog::~removecustomerdialog()
{
    delete ui;
}

void removecustomerdialog::on_removeCustomerDialogConfirmButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.removeCustomer(*ui);
    carRentalDatabase.closeConnection();
}


void removecustomerdialog::on_removeCustomerDialogCancelButton_clicked()
{
close();
}

