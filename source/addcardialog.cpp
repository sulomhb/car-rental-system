#include "addcardialog.h"
#include "ui_addcardialog.h"
#include "carrentalmainwindow.h"
#include "database.h"

addCarDialog::addCarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCarDialog)
{
    ui->setupUi(this);
}

addCarDialog::~addCarDialog()
{
    delete ui;
}

void addCarDialog::on_addCarDialogAddButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.addCar(*ui);
    carRentalDatabase.closeConnection();
};



void addCarDialog::on_addCarDialogCancelButton_clicked()
{
    close();
};

