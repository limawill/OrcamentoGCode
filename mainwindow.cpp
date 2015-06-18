#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Pega o caminho do arquivo a ser tratado
void MainWindow::on_Button_abreArquivo_clicked()
{
    //QString fileName = QFileDialog::getOpenFileName(this,tr("Open Text file"), "", tr("Text Files (*.txt)"));

    QString filename = QFileDialog::getOpenFileName(this,tr("Open text file"), "", tr("Text Files (*.gcode)"));
    ui->line_caminho->setText(filename);
}
