#ifndef ADDCUSTOMERDIALOG_H
#define ADDCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class addcustomerdialog;
}

class addcustomerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addcustomerdialog(QWidget *parent = nullptr);
    ~addcustomerdialog();

private slots:
    void on_addCustomerDialogAddButton_clicked();

    void on_addCustomerDialogCancelButton_clicked();

private:
    Ui::addcustomerdialog *ui;
};

#endif // ADDCUSTOMERDIALOG_H
