#ifndef TELA_ORCAMENTO_H
#define TELA_ORCAMENTO_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class Tela_Orcamento;
}

class Tela_Orcamento : public QDialog
{
    Q_OBJECT

public:
    explicit Tela_Orcamento(QWidget *parent = 0);
    ~Tela_Orcamento();

private:
    Ui::Tela_Orcamento *ui;
};

#endif // TELA_ORCAMENTO_H
