#include "Endereco.h"

#include <iostream>
#include <string>

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
    cout << "CEP: ";
    getline(cin, ce);

    setarEndereco(r,n,b,ci,ce);

}


void Endereco::setarEndereco(string r, int n, string b, string ce, string ci)
{
    rua = r;
    numero = n;
    bairro = b;
    cidade = ci;
    cep = ce;
}