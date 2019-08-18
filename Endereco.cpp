#include "Endereco.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Endereco::Endereco()
{

}

void Endereco::setRua()
{
    string r;
    cout << "Rua: ";
    getline(cin, r);
    rua = r;
}

void Endereco::setBairro()
{
    string b;
    cin.ignore();
    cout << "Bairro: ";
    getline(cin, b);
    bairro = b;
}

void Endereco::setNumero()
{
    int n;
    cout << "Numero: ";
    cin >> n;
    numero = n;
}

void Endereco::setCep()
{
    string ce;
    cout << "CEP: ";
    getline(cin, ce);
    cep = ce;
}

void Endereco::setCidade()
{
    string ci;
    cout << "Cidade: ";
    getline(cin, ci);
    cidade = ci;
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
