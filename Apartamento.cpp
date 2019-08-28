#include "Apartamento.h"
using namespace std;

Apartamento::Apartamento()
{
    id = 2;
}

void Apartamento::set_Apt(string t, string tipo, double val, string r, string b, string c, string ce, string num
,int a, int q, int v,string pos, double cond, double ar)
{
    title = t;
    type = tipo;
    value = val;
    adress.set_endr(r,b,c,ce,num);
    floor = a;
    rooms = q;
    vanc = v;
    value_cond = cond;
    area = ar;
    position = pos;

}

void Apartamento::set_apartment()
{
    int floor,rooms,vanc;
    double value_cond, area;
    string position;
    cout << "Insira o andar do apartamento: ";
    cin >> floor;
    cout << "Insira o n�mero de quartos: ";
    cin >> rooms;
    cout << "Insira o n�mero de vagas na garagem: ";
    cin >> vanc;
    cin.ignore();
    cout << "Insira a posi��o do apartamento: ";
    getline(cin,position);
    cout << "Insira o valor do condom�nio: ";
    cin >> value_cond;
    cout << "Insira a �rea total: ";
    cin >> area;
    cin.ignore();

    this->floor = floor;
    this->rooms = rooms;
    this->vanc = vanc;
    this->value_cond = value_cond;
    this->area = area;
    this->position = position;
}

void Apartamento::set_floor(int f)
{
    floor = f;
}

void Apartamento::set_rooms(int r)
{
    rooms = r;
}

void Apartamento::set_vanc(int v)
{
    vanc = v;
}

void Apartamento::set_area(double ar)
{
    area = ar;
}

void Apartamento::set_position(string pos)
{
    position = pos;
}

void Apartamento::set_value_cond(double val)
{
    value_cond = val;
}

int Apartamento::get_floor()
{
    return floor;
}

int Apartamento::get_rooms()
{
    return rooms;
}

int Apartamento::get_vanc()
{
    return vanc;
}

double Apartamento::get_area()
{
    return area;
}

double Apartamento::get_value_cond()
{
    return value_cond;
}

string Apartamento::get_position()
{
    return position;
}
