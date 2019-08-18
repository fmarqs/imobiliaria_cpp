#include "Casas.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Casas::Casas()
{
    id = 1;
}

void Casas::setPavimentos()
{
    int pav;
    cout << "Pavimentos: ";
    cin >> pav;
    pavimentos = pav;
}

void Casas::setQuartos()
{
    int q;
    cout << "Quartos: ";
    cin >> q;
    quartos = q;
}

void Casas::setAreaC()
{
    double areac;
    cout << "Area construida: ";
    cin >> areac;
    areaConstruida = areac;
}

void Casas::setAreaT()
{
    double areat;
    cout << "Area do terreno: ";
    cin >> areat;
    areaTerreno = areat;
}

int Casas::getPavimentos()
{
    return pavimentos;
}

int Casas::getQuartos()
{
    return quartos;
}

double Casas::getAreaC()
{
    return areaConstruida;
}

double Casas::getAreaT()
{
    return areaTerreno;
}

void Casas::lerCasas(int tipo, double val, string tit, string r, int num, string b, string ci, string ce, 
int pav, int q, double areac, double areat)
{
    tipoOferta = tipo;
    valor = val;
    rua = r;
    numero = num;
    bairro = b;
    cidade = ci;
    cep = ce;
    pavimentos = pav;
    q = quartos;
    areaConstruida = areac;
    areaTerreno = areat;

}
