#ifndef FORMULAS
#define FORMULAS


std::string Pega_Filamento(std::string caminho);
std::string Limpa_String(std::string caminho);
void replace_str(std::string& str, const std::string de,const std::string para);
double Calculos(int quantidade,double preco,double volume,double lucro);
void Saida_orcamento(std::string arquivo_usado,std::string material,std::string diametro,int quantidade,double preco,double volume,double lucro,double total);

#endif // FORMULAS

