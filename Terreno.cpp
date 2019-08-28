#include "Terreno.h"
using namespace std;

Terreno::Terreno()
{
    id = 3;
}

void Terreno::set_ter(string t,string tipo, double val, string r, string b, string c, string ce, string num, double ar)
{
    title = t;
    type = tipo;
    value = val;
    adress.set_endr(r,b,c,ce,num);
    area = ar;

}

void Terreno::set_ground()
{
    double area;
    cout << "Insira a área do terreno: ";
    cin >> area;
    cin.ignore();

    this->area = area;
}

void Terreno::set_ground2(double ar)
{
    area = ar;
}

double Terreno::get_area()
{
    return area;
}
