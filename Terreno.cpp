#include "Terreno.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Terreno::Terreno()
{
}

void Terreno::cadastraTerreno()
{
    double ar, pre;

    cout << "\nArea do terreno: ";
    cin >> ar;
    cout << "\nValor do terreno: ";
    cin >> pre;

    setTerreno(ar, pre);
}

void Terreno::setTerreno(double ar, double pre)
{
    area = ar;
    preco = pre;
}

double Terreno::getArea()
{
    return area;
}

double Terreno::getPreco()
{
    return preco;
}

void Terreno::lerTerreno(double val, std::string r, int num, std::string b, std::string ci,
        std::string ce, double ar)
{
    preco = val;
    rua = r;
    numero = num;
    bairro = b;
    cidade = ci;
    cep = ce;
    area = ar;
}
