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

    cout << "\nNumero de pavimentos: ";
    cin >> pav;
    cout << "\nQuartos: ";
    cin >> q;
    cout << "\nArea construida: ";
    cin >> areac;
    cout << "\nArea do terreno: ";
    cin >> areat;

    setCasa(tipo, val, r, num, b, ci, ce, pav, q, areac, areat);
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
