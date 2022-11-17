#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>

namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();
signals:
    void on_expandTeamsButton_clicked();

private slots:
    void on_pushButton_clicked();

    void on_expandTeamsButton_released();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
