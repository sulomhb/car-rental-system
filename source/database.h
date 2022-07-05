#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QtDebug>
#include "carrentalmainwindow.h"
#include "addcardialog.h"
#include "ui_addcardialog.h"
#include "editcardialog.h"
#include "ui_addcustomerdialog.h"
#include "ui_editcardialog.h"
#include "ui_removecardialog.h"
#include "removecardialog.h"
#include "editcustomerdialog.h"
#include "ui_editcustomerdialog.h"
#include "removecustomerdialog.h"
#include "ui_removecustomerdialog.h"
#include "ui_carrentalmainwindow.h"

class Database {
public:
    QSqlDatabase carRentalDatabase = QSqlDatabase::contains("qt_sql_default_connection") ? QSqlDatabase::database("qt_sql_default_connection") : QSqlDatabase::addDatabase("QSQLITE");
    // -------------------------------------- DATABASE CONNECTION -------------------------------------------------

    void openConnection() {
        carRentalDatabase.setDatabaseName("/home/sesu/Documents/dev/cpp/CarRentalGUI/db/carRentalDatabase");
        if(carRentalDatabase.open()) {
            qDebug() << "Connected to database!";
        } else {
            qDebug() << "Failed connection to database!";
        }
    }

    void closeConnection() {
        carRentalDatabase.close();
        carRentalDatabase.removeDatabase("carRentalDatabase");
    }

    // --------------------------------------- CAR OPERATIONS -----------------------------------------------
    void addCar(Ui::addCarDialog ui) {
        QString car_brand, car_registrationNumber, car_color, car_transmission;
        car_brand = ui.addCarDialogBrandInput->text();
        car_registrationNumber = ui.addCarDialogRegistrationInput->text();
        car_color = ui.addCarDialogColorInput->text();
        car_transmission = ui.addCarDialogTransmissionInput->currentText();

        openConnection();

        QSqlQuery * addCarQuery = new QSqlQuery(carRentalDatabase);
        addCarQuery->prepare("INSERT INTO Car (car_id, car_brand,car_registrationNumber, car_color, car_transmission) VALUES (null, :car_brand, :car_registrationNumber, :car_color, :car_transmission);");
        addCarQuery->bindValue(":car_brand", car_brand);
        addCarQuery->bindValue(":car_registrationNumber", car_registrationNumber);
        addCarQuery->bindValue(":car_color", car_color);
        addCarQuery->bindValue(":car_transmission", car_transmission);
        if(addCarQuery->exec()) {
            qDebug() << "Executed command Add Car";
            ui.addCarDialogConfirmationMessage->setText("Car added successfully!");
        } else {
            qDebug() << "Could not ADD Car";
            ui.addCarDialogConfirmationMessage->setText("Car could not be added!");
            qDebug()<<addCarQuery->exec();
        }
        closeConnection();
        return;
    }

    void editCar(Ui::editcardialog ui) {
        QString car_id,car_brand, car_registrationNumber, car_color, car_transmission;
        car_id = ui.editCarDialogSelectCarID->text();
        car_brand = ui.editCarDialogNewBrand->text();
        car_registrationNumber = ui.editCarDialogNewRegistrationNumber->text();
        car_color = ui.editCarDialogNewColor->text();
        car_transmission = ui.editCarNewTransmission->currentText();

        openConnection();

        QSqlQuery * editCarQuery = new QSqlQuery(carRentalDatabase);
        editCarQuery->prepare("UPDATE Car SET car_brand = :car_brand, car_registrationNumber = :car_registrationNumber, car_color = :car_color, car_transmission = :car_transmission WHERE car_id = :car_id;");
        editCarQuery->bindValue(":car_id", car_id);
        editCarQuery->bindValue(":car_brand", car_brand);
        editCarQuery->bindValue(":car_registrationNumber", car_registrationNumber);
        editCarQuery->bindValue(":car_color", car_color);
        editCarQuery->bindValue(":car_transmission", car_transmission);
        if(editCarQuery->exec()) {
            qDebug() << "Executed command DELETE Car";
            ui.editCarDialogConfirmationMessage->setText("Car updated successfully!");
        } else {
            qDebug() << "Could not DELETE Car";
            ui.editCarDialogConfirmationMessage->setText("This car does not exist!");
            qDebug()<<editCarQuery->exec();

        }
    };

    void removeCar(Ui::removecardialog ui) {
        QString car_id,car_brand, car_registrationNumber, car_color, car_transmission;
        car_id = ui.removeCarDialogCarIDInput->text();

        openConnection();

        QSqlQuery * removeCarQuery = new QSqlQuery(carRentalDatabase);
        removeCarQuery->prepare("DELETE FROM Car WHERE car_id = :car_id;");
        removeCarQuery->bindValue(":car_id", car_id);

        if(removeCarQuery->exec()) {
            qDebug() << "Executed command DELETE Car";
            ui.removeCarDialogConfirmationMessage->setText("Car removed from database successfully!");
        } else {
            qDebug() << "Could not DELETE Car";
            ui.removeCarDialogConfirmationMessage->setText("This car does not exist!");
            qDebug()<<removeCarQuery->exec();

        }

    }

    void loadAllCars(Ui::CarRentalMainWindow ui) {
        QSqlQueryModel * modal = new QSqlQueryModel();

        openConnection();

        QSqlQuery * loadAllCarsQuery = new QSqlQuery(carRentalDatabase);
        loadAllCarsQuery->prepare("SELECT * FROM Car;");
        if(loadAllCarsQuery->exec()) {
            qDebug() << "Executed command Select from car";
        } else {
            qDebug() << "Could not execute command";
        }

        modal->setQuery(*loadAllCarsQuery);
        ui.assignCarTableView->setModel(modal);
        qDebug() << (modal -> rowCount());
        closeConnection();
    }

    // --------------------------------------- CUSTOMER OPERATIONS -----------------------------------------------

    void addCustomer(Ui::addcustomerdialog ui) {
        QString customer_firstName, customer_lastName, customer_phone;
        customer_firstName = ui.addCustomerDialogFirstNameInput->text();
        customer_lastName = ui.addCustomerDialogLastNameInput->text();
        customer_phone = ui.addCustomerDialogPhoneInput->text();

        openConnection();

        QSqlQuery * addCustomerQuery = new QSqlQuery(carRentalDatabase);
        addCustomerQuery->prepare("INSERT INTO Customer (customer_id, customer_firstName,customer_lastName, customer_phone) VALUES (null, :customer_firstName, :customer_lastName, :customer_phone);");
        addCustomerQuery->bindValue(":customer_firstName", customer_firstName);
        addCustomerQuery->bindValue(":customer_lastName", customer_lastName);
        addCustomerQuery->bindValue(":customer_phone", customer_phone);
        if(addCustomerQuery->exec()) {
            qDebug() << "Executed command INSERT INTO Customer";
            ui.addCustomerDialogConfirmationMessage->setText("Customer added to database successfully!");

        } else {
            qDebug() << "Could not INSERT INTO Customer";
            ui.addCustomerDialogConfirmationMessage->setText("Failed to add customer to database!");
            qDebug()<<addCustomerQuery->exec();
        }
        closeConnection();
        return;
    }


    void editCustomer(Ui::editcustomerdialog ui) {
        QString customer_id, customer_firstName, customer_lastName, customer_phone;
        customer_id = ui.editCustomerDialogSelectCustomerID->text();
        customer_firstName = ui.editCustomerDialogNewFirstName->text();
        customer_lastName = ui.editCustomerDialogNewLastName->text();
        customer_phone = ui.editCustomerDialogNewPhone->text();

        openConnection();

        QSqlQuery * editCustomerQuery = new QSqlQuery(carRentalDatabase);
        editCustomerQuery->prepare("UPDATE Customer SET customer_firstName = :customer_firstName, customer_lastName = :customer_lastName, customer_phone = :customer_phone WHERE customer_id = :customer_id;");
        editCustomerQuery->bindValue(":customer_id", customer_id);
        editCustomerQuery->bindValue(":customer_firstName", customer_firstName);
        editCustomerQuery->bindValue(":customer_lastName", customer_lastName);
        editCustomerQuery->bindValue(":customer_phone", customer_phone);
        if(editCustomerQuery->exec()) {
            qDebug() << "Executed command UPDATE Customer";
            ui.editCustomerDialogConfirmationMessage->setText("Customer updated successfully!");

        } else {
            qDebug() << "Could not UPDATE Customer";
            ui.editCustomerDialogConfirmationMessage->setText("Failed to update customer!");
            qDebug()<<editCustomerQuery->exec();
        }
        closeConnection();
        return;
    }

    void removeCustomer(Ui::removecustomerdialog ui) {

        QString customer_id;
        customer_id = ui.removeCustomerDialogCustomerIDInput->text();

        openConnection();

        QSqlQuery * removeCustomerQuery = new QSqlQuery(carRentalDatabase);
        removeCustomerQuery->prepare("DELETE FROM Customer WHERE customer_id = :customer_id;");
        removeCustomerQuery->bindValue(":customer_id", customer_id);

        if(removeCustomerQuery->exec()) {
            qDebug() << "Executed command DELETE Customer";
            ui.removeCustomerDialogConfirmationMessage->setText("Customer removed from database successfully!");
        } else {
            qDebug() << "Could not DELETE Customer";
            ui.removeCustomerDialogConfirmationMessage->setText("This customer does not exist!");
            qDebug()<<removeCustomerQuery->exec();

        }
    }

    void loadAllCustomers(Ui::CarRentalMainWindow ui) {
        QSqlQueryModel * modal = new QSqlQueryModel();

        openConnection();

        QSqlQuery * loadAllCustomersQuery = new QSqlQuery(carRentalDatabase);
        loadAllCustomersQuery->prepare("SELECT * FROM Customer;");
        if(loadAllCustomersQuery->exec()) {
            qDebug() << "Executed command SELECT * FROM Customer";
        } else {
            qDebug() << "Could not execute command";
        }

        modal->setQuery(*loadAllCustomersQuery);
        ui.assignCustomerTableView->setModel(modal);
        qDebug() << (modal -> rowCount());
        closeConnection();
    }

    // --------------------------------------- ASSIGNMENT OPERATIONS -----------------------------------------------

    void assignCarToCustomer(Ui::CarRentalMainWindow ui) {
        QString assignCarIDInput, assignCustomerIDInput;
        assignCarIDInput = ui.assignCarIDInput->text();
        assignCustomerIDInput = ui.assignCustomerIDInput->text();

        openConnection();

        QSqlQuery * assignCarToCustomerQuery = new QSqlQuery(carRentalDatabase);
        assignCarToCustomerQuery->prepare("INSERT INTO Assignment (assignment_id, car_id, customer_id, assignmentDateTime) VALUES (null, :assignCarIDInput, :assignCustomerIDInput, DATETIME());");
        assignCarToCustomerQuery->bindValue(":assignCarIDInput", assignCarIDInput);
        assignCarToCustomerQuery->bindValue(":assignCustomerIDInput", assignCustomerIDInput);
        if(assignCarToCustomerQuery->exec()) {
            qDebug() << "Executed command INSERT INTO Assignment";
            ui.assignCarToCustomerConfirmationMessage->setText("Car assigned to customer successfully!");

        } else {
            qDebug() << "Could not INSERT INTO Assignment";
            ui.assignCarToCustomerConfirmationMessage->setText("Failed to assign car to customer! One car can only be assigned to one customer");
            qDebug()<<assignCarToCustomerQuery->exec();
        }
        closeConnection();
        return;

    }

    void unAssignCarFromCustomer(Ui::CarRentalMainWindow ui) {
        QString deleteAssignmentIndput;
        deleteAssignmentIndput = ui.assignCarTabDeleteAssignmentCarIDInput->text();

        openConnection();

        QSqlQuery * unAssignCarFromCustomer = new QSqlQuery(carRentalDatabase);
        unAssignCarFromCustomer->prepare("DELETE FROM Assignment WHERE assignment_id = :assignment_id");
        unAssignCarFromCustomer->bindValue(":assignment_id", deleteAssignmentIndput);

        if(unAssignCarFromCustomer->exec()) {
            qDebug() << "Executed command DELETE Assignment¨";
            ui.assignCarToCustomerConfirmationMessage->setText("Unassigned car from customer successfully!");
        } else {
            qDebug() << "Could not DELETE Assignment";
            ui.assignCarToCustomerConfirmationMessage->setText("Failed to unassign car from customer!");
            qDebug()<<unAssignCarFromCustomer->exec();

        }
        closeConnection();
        return;
    }

    void searchCustomer(Ui::CarRentalMainWindow ui) {
        QSqlQueryModel * modal = new QSqlQueryModel();

        openConnection();

        QString customer_firstName;
        customer_firstName = ui.searchCustomerFirstNameInput->text();

        QSqlQuery * getCustomerWithFirstNameQuery = new QSqlQuery(carRentalDatabase);
        getCustomerWithFirstNameQuery->prepare("SELECT * FROM Customer WHERE customer_firstName = :customer_firstName;");
        getCustomerWithFirstNameQuery->bindValue(":customer_firstName", customer_firstName);
        if(getCustomerWithFirstNameQuery->exec()) {
            qDebug() << "Executed command SELECT * FROM Customer Given Customer Firstname";
        } else {
            qDebug() << "Could not execute command";
        }

        modal->setQuery(*getCustomerWithFirstNameQuery);
        ui.searchCustomerResult->setModel(modal);
        qDebug() << (modal -> rowCount());
        if(modal->rowCount() == 0) {
            ui.searchCustomerConfirmationMessage->setText("There are no customers with this first name!");
        } else {
            ui.searchCustomerConfirmationMessage->setText("Found this first name in the database!");
        }
        closeConnection();
    }

    void searchCar(Ui::CarRentalMainWindow ui) {
        QSqlQueryModel * modal = new QSqlQueryModel();

        openConnection();

        QString car_registrationNumber;
        car_registrationNumber = ui.searchCarRegistrationNumberInput->text();

        QSqlQuery * getCarWithRegNumberQuery = new QSqlQuery(carRentalDatabase);
        getCarWithRegNumberQuery->prepare("SELECT * FROM Car WHERE car_registrationNumber = :car_registrationNumber;");
        getCarWithRegNumberQuery->bindValue(":car_registrationNumber", car_registrationNumber);
        if(getCarWithRegNumberQuery->exec()) {
            qDebug() << "Executed command SELECT * FROM Car Given Car Reg Number";
        } else {
            qDebug() << "Could not execute command";
        }

        modal->setQuery(*getCarWithRegNumberQuery);
        ui.searchCarResult->setModel(modal);
        qDebug() << (modal -> rowCount());
        if(modal->rowCount() <= 0) {
            ui.searchCarConfirmationMessage->setText("Could not find this registration number in the database!");
        } else {
            ui.searchCarConfirmationMessage->setText("Found this registration number in the database!");
        }
        closeConnection();
    }

    void loadAllAssignments(Ui::CarRentalMainWindow ui) {
        QSqlQueryModel * modal = new QSqlQueryModel();

        openConnection();

        QSqlQuery * loadAllAssignmentsQuery = new QSqlQuery(carRentalDatabase);
        loadAllAssignmentsQuery->prepare("SELECT * FROM Assignment;");
        if(loadAllAssignmentsQuery->exec()) {
            qDebug() << "Executed command SELECT * FROM Assignment";
        } else {
            qDebug() << "Could not execute command";
        }

        modal->setQuery(*loadAllAssignmentsQuery);
        ui.allAssignmentTableView->setModel(modal);
        qDebug() << (modal -> rowCount());
        closeConnection();
    }
};

#endif // DATABASE_H
