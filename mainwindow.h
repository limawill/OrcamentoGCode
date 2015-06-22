#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tela_orcamento.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::string  material,diametro,filamento_usado,arquivo_usado;
    double preco,lucro,volume,total;
    int quantidade;

private slots:
    void on_Button_abreArquivo_clicked();

    void on_comboBox_material_currentIndexChanged(const QString &arg1);

    void on_push_orcamento_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
