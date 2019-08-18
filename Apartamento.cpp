#include "Apartamento.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Apartamento::Apartamento()
{
    id = 2;
}

void Apartamento::setArea()
{
    double ar;
    cout << "Area: ";
    cin >> ar;
    area = ar;
}

void Apartamento::setCondominio()
{
    double cond;
    cout << "Valor do condominio: ";
    cin >> cond;
    condominio = cond;
}

void Apartamento::setQuartos()
{
    int q;
    cout << "Numero de quartos: ";
    cin >> q;
    quartos = q;
}

void Apartamento::setAndar()
{
    int an;
    cout << "Andar: ";
    cin >> an;
    andar = an;
}

void Apartamento::setGaragem()
{
    int gar;
    cout << "Vagas na garagem: ";
    cin >> gar;
    garagem = gar;
}

void Apartamento::setPosicao()
{
    string pos;
    cin.ignore();
    cout << "Posicao: ";
    getline(cin, pos);
    posicao = pos;
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

void Apartamento::lerApt(int tipo, double val, string tit, std::string r, int num, std::string b, std::string ci,
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
