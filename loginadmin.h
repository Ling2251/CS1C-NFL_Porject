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
    void on_pushButton_clicked();

private:
    Ui::LoginAdmin *ui;
};

#endif // LOGINADMIN_H
