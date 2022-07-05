#ifndef ADDCARDIALOG_H
#define ADDCARDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class addCarDialog;
}

class addCarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addCarDialog(QWidget *parent = nullptr);
    ~addCarDialog();

private slots:
    void on_addCarDialogAddButton_clicked();
    void on_addCarDialogCancelButton_clicked();


private:
    Ui::addCarDialog *ui;
};

#endif // ADDCARDIALOG_H
