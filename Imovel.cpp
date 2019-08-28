#include "Imovel.h"
#include <stdlib.h>
using namespace std;

Imovel::Imovel()
{

}

void Imovel::set_value()
{
    double val;
    cout << "Insira o valor do im�vel: ";
    cin >> val;
    cin.ignore();
    value = val;
}

void Imovel::set_type()
{
    int option;
    cout << "Im�vel dispon�vel para: " << endl;
    cout << "[0] VENDA |  [1] ALUGUEL" << endl;
    cin >> option;

    switch(option){
    case 0:
        type = "VENDA";
        break;
    case 1:
        type = "ALUGUEL";
        break;
    default:
        cout << "Insira algo v�lido" << endl;
        system("cls");
        set_type();
        }
}


void Imovel::set_title()
{   string title;
    cout << "Insira o t�tulo do im�vel: ";
    getline(cin,title);

    this->title = title;
}

string Imovel::get_title()
{
    return title;
}

string Imovel::return_adress()
{
    string add = adress.get_adress();
    return add;
}

void Imovel::set_adress()
{
    adress.set_adress();
}

string Imovel::get_type()
{
    return type;
}

double Imovel::get_value()
{
    return value;
}

int Imovel::get_id()
{
    return id;
}

string Imovel::print_adress()
{
    string add = adress.retornando_adress();
    return add;
}

string Imovel::print_adress_sep()
{
    string add = adress.return_disc();
    return add;
}

string Imovel::return_bairro()
{
    string bar = adress.getBairro();
    return bar;
}

string Imovel::return_cidade()
{
    string cid = adress.getCidade();
    return cid;
}

void Imovel::set_remov(int h)
{
    remov = h;
}

int Imovel::get_remov()
{
    return remov;
}