#include "Casas.h"
#include <iostream>
#include <string>

using namespace std;

Casas::Casas()
{
}

double Casas::getAreaConstruida()
{
    return areaConstruida;
}

double Casas::getAreaTerreno()
{
    return areaTerreno;
}

int Casas::getPavimentos()
{
    return pavimentos;
}

int Casas::getQuartos()
{
    return quartos;
}

void Casas::setAreaConstruida()
{
    double areacons;
    cout << "Area construida: ";
    cin >> areacons;
    areaConstruida = areacons;
}

void Casas::setAreaTerreno()
{
    double areater;
    cout << "Area do terreno: ";
    cin >> areater;
    areaTerreno = areater;
}

void Casas::setPavimentos()
{
    int pav;
    cout << "Numero de pavimentos: ";
    cin >> pav;
    pavimentos = pav;    
}

void Casas::setQuartos()
{
    int quar;
    cout << "Numero de quartos: ";
    cin >> quar;
    quartos = quar;
}

