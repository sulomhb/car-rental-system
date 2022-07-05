#ifndef EDITCARDIALOG_H
#define EDITCARDIALOG_H

#include <QDialog>

namespace Ui {
class editcardialog;
}

class editcardialog : public QDialog
{
    Q_OBJECT

public:
    explicit editcardialog(QWidget *parent = nullptr);
    ~editcardialog();

private slots:
    void on_editCarDialogSaveEditButton_clicked();
    void on_editCarDialogCancelEditButton_clicked();

private:
    Ui::editcardialog *ui;
};

#endif // EDITCARDIALOG_H
