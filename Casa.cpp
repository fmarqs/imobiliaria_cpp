#include "Casa.h"
using namespace std;

Casa::Casa()
{
    id = 1;
}

void Casa::set_Casa(string t, string tipo, double val, string r, string b, string c, string ce, string num
,int pav, int q, double ar, double a)
{
    title = t;
    type = tipo;
    value = val;
    adress.set_endr(r,b,c,ce,num);
    floors = pav;
    rooms = q;
    area_const = ar;
    area_ter = a;
}

void Casa::set_houses()
{
    int floors, rooms;
    double area_const, area_ter;
    cout << "Insira o número de pavimentos: ";
    cin >> floors;
    cout << "Insira o número de quartos: ";
    cin >> rooms;
    cout << "Insira a área construída: ";
    cin >> area_const;
    cout << "Insira a área total: ";
    cin >> area_ter;

    this->floors = floors;
    this->rooms = rooms;
    this->area_const = area_const;
    this->area_ter = area_ter;
}

void Casa::set_floors(int f)
{
    floors = f;
}

void Casa::set_rooms(int r)
{
    rooms = r;
}

void Casa::set_areaC(double ar)
{
    area_const = ar;
}

void Casa::set_areaT(double a)
{
    area_ter = a;
}

int Casa::get_floors()
{
    return floors;
}

int Casa::get_rooms()
{
    return rooms;
}

double Casa::get_areaC()
{
    return area_const;
}

double Casa::get_areaT()
{
    return area_ter;
}
