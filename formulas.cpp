#include "mainwindow.h"
#include <string>
#include <iostream>
#include <fstream>
#include <QtGui>
#include <QtCore>
#include <QMessageBox>


// linha do gcode a ser lida:  ; filament used = 2481.7mm (5.6cm3)

std::string Pega_Filamento(std::string caminho)
{
    std::string Linha;
    unsigned int pos;
    std::ifstream myfile(caminho.c_str());
    if(myfile.is_open())
    {
        while (! myfile.eof())
        {
            std::getline(myfile,Linha);
            pos = Linha.find("; filament used");
            if(pos != -1)
                return Linha;
        }
        myfile.close();
    }
    else
    {
       QMessageBox::information(0,"Erro","Não foi possivel abrir o .gcode!!");
       return "error!";
    }



}

