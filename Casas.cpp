#include "Casas.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Casas::Casas()
{
}

void Casas::cadastraCasa()
{
    int pav, q;
    double areat, areac;
    cout << "Numero de pavimentos: ";
    cin >> pav;
    cout << "Quartos: ";
    cin >> q;
    cout << "Area construida: ";
    cin >> areac;
    cout << "Area do terreno: ";
    cin >> areat;

    setCasa(pav, q, areac, areat);
}

void Casas::setCasa(int pav, int q, double areac, double areat)
{
    pavimentos = pav;
    quartos = q;
    areaConstruida = areac;
    areaTerreno = areat;
}

string Casas::toStringCasas()
{
    stringstream cas;

    cas << pavimentos << quartos << areaConstruida << areaTerreno << endl;

    return cas.str();
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

void Casas::lerCasas(int tipo, double val, string r, int num, string b, string ci, string ce, int pav, int q, double areac, double areat)
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
