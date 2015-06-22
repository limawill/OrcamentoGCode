#include "mainwindow.h"
#include <string>
#include <iostream>
#include <fstream>
#include <QtGui>
#include <QtCore>
#include <QMessageBox>



//Função coringa para subistiuir caracter
void replace_str(std::string& str, const std::string de,const std::string para)
{

    int i = 0, loc;
    if(str.empty())
    {
        str = de;
        return;
    }

    while(i < str.size()){
        loc = str.find(de, 0);
        if(loc >= 0)
            str.replace(loc, de.length(), para);
        else
        return;
        i++;
    }
}




// linha do gcode a ser lida:  ; filament used = 2481.7mm (5.6cm3)
std::string Limpa_String(std::string caminho)
{
    //Removendo parte que pode variar
    std::string::size_type i = caminho.find("(");
    //std::cout << i << std::endl;

    //Removendo tudo antes do parenteses
    caminho.erase (0,i);

    // Substitui as ocorrências
      replace_str(caminho, "(", "");
      replace_str(caminho, ")", "");
      replace_str(caminho, "cm3", "");

   // std::cout << "Dentro da função limpeza: " << caminho.c_str()<<std::endl;
        return caminho;
}



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

double Calculos(int quantidade,double preco,double volume,double lucro)
{

    double Custo;

    Custo = ((quantidade*volume*preco)*lucro);

    return Custo;

}

void Saida_orcamento (std::string arquivo_usado,std::string material,std::string diametro,int quantidade,double preco,double volume,double lucro,double total)
{

    std::ofstream myfile ("orcamento.txt");
    if (myfile.is_open())
    {
        myfile << "\t\t ORÇAMENTO\n";
        myfile << "\n";
        myfile << "\n";
        myfile <<"Arquivo  Usado: " << arquivo_usado.c_str()<<std::endl;
        myfile <<"Material Usado: " << material.c_str()<<std::endl;
        myfile <<"Diametro Usado: " << diametro.c_str()<<std::endl;
        myfile <<"Quantidade    : " << quantidade<<std::endl;
        myfile <<"Preço R$      : " << preco<<std::endl;
        myfile <<"Volume (cm3)  : " << volume<<std::endl;
        myfile <<"Fator Lucro   : " << lucro<<std::endl;
        myfile <<"Total R$      : " << total<<std::endl;
        myfile.close();
      }




    std::system("gedit orcamento.txt");


}
