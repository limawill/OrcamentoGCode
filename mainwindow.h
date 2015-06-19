#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::string  material,diametro,filamento_usado;
    float preco,lucro,volume;
    int quantidade;


private slots:
    void on_Button_abreArquivo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
