#include "Terreno.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Terreno::Terreno()
{
    id = 3;
}

void Terreno::setArea()
{
    double ar;
    cout << "Area: ";
    cin >> ar;
    area = ar;

}

double Terreno::getArea()
{
    return area;
}


void Terreno::lerTerreno(double val, string tit, std::string r, int num, std::string b, std::string ci,
        std::string ce, double ar)
{
    valor = val;
    rua = r;
    numero = num;
    bairro = b;
    cidade = ci;
    cep = ce;
    area = ar;
}