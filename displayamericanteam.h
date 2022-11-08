#ifndef DISPLAYAMERICANTEAM_H
#define DISPLAYAMERICANTEAM_H

#include <QWidget>

namespace Ui {
class DisplayAmericanTeam;
}

class DisplayAmericanTeam : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayAmericanTeam(QWidget *parent = nullptr);
    ~DisplayAmericanTeam();

private slots:


private:
    Ui::DisplayAmericanTeam *ui;
};

#endif // DISPLAYAMERICANTEAM_H
