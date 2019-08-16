#include "Terreno.h"
#include <iostream>
#include <string>

using namespace std;

Terreno::Terreno()
{
}

double Terreno::getArea()
{
    return area;
}

void Terreno::setArea()
{
    double a;
    cout << "Area do terreno: ";
    cin >> a;
    area = a;
}
