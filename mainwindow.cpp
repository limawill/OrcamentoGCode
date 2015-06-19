#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include <string>
#include <iostream>
#include <formulas.h>
#include <QDebug>

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
    QString filename = QFileDialog::getOpenFileName(this,tr("Open text file"), "", tr("Text Files (*.gcode)"));
    ui->line_caminho->setText(filename);

    filamento_usado = filename.toStdString();

    diametro = Pega_Filamento(filamento_usado);
    std::cout << diametro.c_str() << std::endl;



}
