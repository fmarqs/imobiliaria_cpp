#include "Apartamento.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Apartamento::Apartamento()
{

}

void Apartamento::cadastraApt()
{
    double ar, cond;
    int qua, an, gar;
    string pos;

    cout << "Area: ";
    cin >> ar;
    cout << "Valor do condominio: ";
    cin >> cond;
    cout << "Quartos: ";
    cin >> qua;
    cout << "Andar: ";
    cin >> an;
    cout << "Garagem: ";
    cin >> gar;
    cin.ignore();
    cout << "Posicao: ";
    getline(cin, pos);


    setApartamento(ar, cond, qua, an, gar, pos);

}

void Apartamento::setApartamento(double ar, double cond, int qua, int an, int gar, std::string pos)
{
    area = ar;
    condominio = cond;
    quartos = qua;
    andar = an;
    garagem = gar;
    posicao = pos;
}


string Apartamento::toStringApt()
{
    stringstream apart;

    apart << area << endl << condominio << endl << quartos << endl << andar << endl << garagem << endl << posicao << endl;


    return apart.str();
}

double Apartamento::getArea()
{
    return area;
}

double Apartamento::getCondominio()
{
    return condominio;
}

int Apartamento::getAndar()
{
    return andar;
}

int Apartamento::getGaragem()
{
    return garagem;
}

int Apartamento::getQuartos()
{
    return quartos;
}

string Apartamento::getPosicao()
{
    return posicao;
}

void Apartamento::lerApt(int tipo, double val, std::string r, int num, std::string b, std::string ci,
        std::string ce, double ar, double cond, int qua, int an, int gar, std::string pos)
{
    tipoOferta = tipo;
    valor = val;
    rua = r;
    numero = num;
    bairro = b;
    cidade = ci;
    cep = ce;
    area = ar;
    condominio = cond;
    quartos = qua;
    andar = an;
    garagem = gar;
    posicao = pos;

}
