#ifndef REMOVECUSTOMERDIALOG_H
#define REMOVECUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class removecustomerdialog;
}

class removecustomerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit removecustomerdialog(QWidget *parent = nullptr);
    ~removecustomerdialog();

private slots:
    void on_removeCustomerDialogConfirmButton_clicked();

    void on_removeCustomerDialogCancelButton_clicked();

private:
    Ui::removecustomerdialog *ui;
};

#endif // REMOVECUSTOMERDIALOG_H
