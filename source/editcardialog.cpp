#include "editcardialog.h"
#include "ui_editcardialog.h"
#include "carrentalmainwindow.h"
#include "database.h"

editcardialog::editcardialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcardialog)
{
    ui->setupUi(this);
}

editcardialog::~editcardialog()
{
    delete ui;
}


void editcardialog::on_editCarDialogSaveEditButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.editCar(*ui);
    carRentalDatabase.closeConnection();
}


void editcardialog::on_editCarDialogCancelEditButton_clicked()
{
    close();
}

