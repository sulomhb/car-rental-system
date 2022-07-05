#include "carrentalmainwindow.h"
#include "./ui_carrentalmainwindow.h"
#include "addcardialog.h"
#include "editcardialog.h"
#include "addcustomerdialog.h"
#include "database.h"
#include <QMessageBox>


CarRentalMainWindow::CarRentalMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CarRentalMainWindow)
{
    ui->setupUi(this);
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.loadAllCars(*ui);
    carRentalDatabase.loadAllCustomers(*ui);
    carRentalDatabase.loadAllAssignments(*ui);
    carRentalDatabase.closeConnection();
}

CarRentalMainWindow::~CarRentalMainWindow()
{
    delete ui;
}


// Car operations
void CarRentalMainWindow::on_addCarButton_clicked()
{
    addCarDialog addCarDialog;
    addCarDialog.setModal(true);
    addCarDialog.exec(); // Execute dialog
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.loadAllCars(*ui);  // Load all cars to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}

void CarRentalMainWindow::on_editCarButton_clicked()
{
    editcardialog editCarDialog;
    editCarDialog.setModal(true);
    editCarDialog.exec(); // Execute dialog
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.loadAllCars(*ui); // Load all cars to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}

void CarRentalMainWindow::on_removeCarButton_clicked()
{
    removecardialog removeCarDialog;
    removeCarDialog.setModal(true);
    removeCarDialog.exec();
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.loadAllCars(*ui); // Load all cars to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}

// Customer operations
void CarRentalMainWindow::on_addCustomerButton_clicked() {
    addcustomerdialog addCustomerDialog;
    addCustomerDialog.setModal(true);
    addCustomerDialog.exec();
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.loadAllCustomers(*ui); // Load all customers to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}
void CarRentalMainWindow::on_editCustomerButton_clicked()
{
    editcustomerdialog editCustomerDialog;
    editCustomerDialog.setModal(true);
    editCustomerDialog.exec();
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.loadAllCustomers(*ui); // Load all customers to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}
void CarRentalMainWindow::on_removeCustomerButton_clicked()
{
    removecustomerdialog removeCustomerDialog;
    removeCustomerDialog.setModal(true);
    removeCustomerDialog.exec();
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.loadAllCustomers(*ui); // Load all cars to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}

//Assignment

void CarRentalMainWindow::on_unAssignCarButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.unAssignCarFromCustomer(*ui);
    carRentalDatabase.loadAllAssignments(*ui); // Load all cars to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}

void CarRentalMainWindow::on_assignCarButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.assignCarToCustomer(*ui);
    carRentalDatabase.loadAllAssignments(*ui); // Load all cars to "All cars" model, such that we can check if the edit was successful.
    carRentalDatabase.closeConnection();
}


void CarRentalMainWindow::on_searchCarButton_clicked() {
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.searchCar(*ui);
    carRentalDatabase.closeConnection();
}


void CarRentalMainWindow::on_searchCustomerButton_clicked()
{
    Database carRentalDatabase;
    carRentalDatabase.openConnection();
    carRentalDatabase.searchCustomer(*ui);
    carRentalDatabase.closeConnection();
}

