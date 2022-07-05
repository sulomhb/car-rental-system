#ifndef REMOVECARDIALOG_H
#define REMOVECARDIALOG_H

#include <QDialog>

namespace Ui {
class removecardialog;
}

class removecardialog : public QDialog
{
    Q_OBJECT

public:
    explicit removecardialog(QWidget *parent = nullptr);
    ~removecardialog();

private slots:
    void on_removeCarDialogConfirmButton_clicked();

    void on_removeCarDialogCancelButton_clicked();

private:
    Ui::removecardialog *ui;
};

#endif // REMOVECARDIALOG_H
