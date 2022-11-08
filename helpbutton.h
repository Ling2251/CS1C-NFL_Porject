#ifndef HELPBUTTON_H
#define HELPBUTTON_H

#include <QDialog>

namespace Ui {
class helpButton;
}

class helpButton : public QDialog
{
    Q_OBJECT

public:
    explicit helpButton(QWidget *parent = nullptr);
    ~helpButton();

private slots:
    void on_HelpButton_clicked();

private:
    Ui::helpButton *ui;
};

#endif // HELPBUTTON_H
