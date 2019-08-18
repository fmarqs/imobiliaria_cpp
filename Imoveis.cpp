#include "Imoveis.h"
#include <iostream>
#include <string>

using namespace std;

Imoveis::Imoveis()
{

}

double Imoveis::getValor()
{
    return valor;
}

int Imoveis::getTipo()
{
    return tipoOferta;
}

void Imoveis::setTipo()
{
    int type;
    cout << "Tipo da oferta (0 ALUGUEL - 1 VENDA): ";
    cin >> type;
    tipoOferta = type;

}

void Imoveis::setValor()
{
    double v;
    if(tipoOferta==0) //tipo == 0 == aluguel
    {
        cout << "Valor do aluguel: ";
        cin >> v;
        valor = v;
    }
    else if(tipoOferta==1)
    {
        cout << "Valor do imovel: ";
        cin >> v;
        valor = v;
    }

}


void Imoveis::setEndereco()
{
    endereco.cadastraEndereco();
}
