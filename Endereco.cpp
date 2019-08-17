#include "Endereco.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Endereco::Endereco()
{

}

void Endereco::cadastraEndereco()
{
    string r, b, ci, ce;
    int n;

    cout << "MENU CADASTRAR" << endl;

    cout << "Rua: ";
    getline(cin, r);
    cout << "Bairro: ";
    getline(cin, b);
    cout << "Cidade: ";
    getline(cin, ci);
    cout << "Numero do imovel: ";
    cin >> n;
    cin.ignore();
    cout << "CEP: ";
    getline(cin, ce);

    setarEndereco(r,n,b,ci,ce);

}


void Endereco::setarEndereco(string r, int n, string b, string ci, string ce)
{
    rua = r;
    numero = n;
    bairro = b;
    cidade = ci;
    cep = ce;
}

string Endereco::toString()
{
    stringstream end;

    end << rua << endl << bairro << endl << cidade << endl << cep << endl << numero << endl;

    return end.str(); 
}

string Endereco::getRua()
{
    return rua;
}

string Endereco::getBairro()
{
    return bairro;
}

string Endereco::getCep()
{
    return cep;
}

string Endereco::getCidade()
{
    return cidade;
}

int Endereco::getNumero()
{
    return numero;
}
