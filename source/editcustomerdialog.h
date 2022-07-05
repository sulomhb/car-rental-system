#ifndef EDITCUSTOMERDIALOG_H
#define EDITCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class editcustomerdialog;
}

class editcustomerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit editcustomerdialog(QWidget *parent = nullptr);
    ~editcustomerdialog();

private slots:
    void on_editCustomerDialogSaveButton_clicked();

    void on_editCustomerDialogCancelButton_clicked();

private:
    Ui::editcustomerdialog *ui;
};

#endif // EDITCUSTOMERDIALOG_H
