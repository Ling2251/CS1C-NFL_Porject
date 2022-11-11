#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QDialog>

namespace Ui {
class LoginAdmin;
}

class LoginAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit LoginAdmin(QWidget *parent = nullptr);
    ~LoginAdmin();

private slots:
    void on_pushButton_clicked(); //Admin Login

    void on_Admin_cancel_clicked(); //Admin Team Page (page 2)

    void on_Admin_Add_clicked(); //Admin Adds new team

    void on_Page1Exit_PushBut_clicked();

private:
    Ui::LoginAdmin *ui;
};

#endif // LOGINADMIN_H
