#ifndef CARRENTALMAINWINDOW_H
#define CARRENTALMAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class CarRentalMainWindow; }
QT_END_NAMESPACE

class CarRentalMainWindow : public QMainWindow {
    Q_OBJECT
public:
    CarRentalMainWindow(QWidget *parent = nullptr);
    ~CarRentalMainWindow();

public:
    Ui::CarRentalMainWindow *ui;

private slots:
    void on_addCarButton_clicked();
    void on_removeCarButton_clicked();
    void on_editCarButton_clicked();
    void on_addCustomerButton_clicked();
    void on_removeCustomerButton_clicked();
    void on_unAssignCarButton_clicked();
    void on_searchCarButton_clicked();
    void on_editCustomerButton_clicked();
    void on_assignCarButton_clicked();
    void on_searchCustomerButton_clicked();
};
#endif // CARRENTALMAINWINDOW_H
