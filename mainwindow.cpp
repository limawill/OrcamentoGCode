#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "formulas.h"
#include <string>
#include <iostream>
#include <QDebug>


QString aux;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Setando valores
    aux = ui->comboBox_material->currentText();
    if(aux == "ABS")
        ui->line_preco->setText("0.25");

    ui->line_quantidade->setText("0");
    ui->line_fator->setText("10");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_abreArquivo_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open text file"), "", tr("Text Files (*.gcode)"));
    ui->line_caminho->setText(filename);
    filamento_usado = filename.toStdString();
    diametro = Pega_Filamento(filamento_usado);
    diametro = Limpa_String(diametro);
    ui->line_volume->setText(QString::fromUtf8(diametro.c_str()));
}


void MainWindow::on_comboBox_material_currentIndexChanged(const QString &arg1)
{
    aux = ui->comboBox_material->currentText();

    if(aux == "ABS")
        ui->line_preco->setText("0.25");
    if(aux == "PP")
        ui->line_preco->setText("0.26");
    else
        ui->line_preco->setText("0.27");
}

void MainWindow::on_push_orcamento_clicked()
{

    quantidade    = ui->line_quantidade->text().toInt();
    preco         = ui->line_preco->text().toDouble();
    volume        = ui->line_volume->text().toDouble();
    lucro         = ui->line_fator->text().toDouble();
    arquivo_usado = filamento_usado;
    material      = ui->comboBox_material->currentText().toStdString();
    diametro      = ui->comboBox_diametro->currentText().toStdString();
    total         = Calculos(quantidade,preco,volume,lucro);


    std::cout << "Arquivo  Usado: " << arquivo_usado.c_str()<<std::endl<<
                 "Material Usado: " << material.c_str()<<std::endl<<
                 "Diametro Usado: " << diametro.c_str()<<std::endl<<
                 "Quantidade    : " << quantidade<<std::endl<<
                 "Preço R$      : " << preco<<std::endl<<
                 "Volume (cm3)  : " << volume<<std::endl<<
                 "Fator Lucro   : " << lucro<<std::endl<<
                 "Total R$      : " << total<<std::endl;

/*
    //chamando a tela do orçamento
    Tela_Orcamento tela;
    tela.setModal(true);
    tela.exec();
*/
}
