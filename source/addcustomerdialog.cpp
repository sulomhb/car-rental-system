#include "addcustomerdialog.h"
#include "ui_addcustomerdialog.h"
#include "database.h"
addcustomerdialog::addcustomerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcustomerdialog)
{
    ui->setupUi(this);
}

addcustomerdialog::~addcustomerdialog()
{
    delete ui;
}

void addcustomerdialog::on_addCustomerDialogAddButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.addCustomer(*ui);
    carRentalDatabase.closeConnection();
}


void addcustomerdialog::on_addCustomerDialogCancelButton_clicked()
{
close();
}

