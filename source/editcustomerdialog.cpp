#include "editcustomerdialog.h"
#include "ui_editcustomerdialog.h"
#include "database.h"
editcustomerdialog::editcustomerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcustomerdialog)
{
    ui->setupUi(this);
}

editcustomerdialog::~editcustomerdialog()
{
    delete ui;
}

void editcustomerdialog::on_editCustomerDialogSaveButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.editCustomer(*ui);
    carRentalDatabase.closeConnection();
}



void editcustomerdialog::on_editCustomerDialogCancelButton_clicked()
{
    close();
}

