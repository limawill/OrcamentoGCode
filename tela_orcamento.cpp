#include "tela_orcamento.h"
#include "ui_tela_orcamento.h"
#include "mainwindow.h"
#include <qstring.h>
#include <string>
#include <iostream>
#include <QDebug>
#include <QtGui>
#include <QtCore>

Tela_Orcamento::Tela_Orcamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tela_Orcamento)
{
    ui->setupUi(this);
}

Tela_Orcamento::~Tela_Orcamento()
{
    delete ui;
}
