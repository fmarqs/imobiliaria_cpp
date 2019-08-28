#include "Endereco.h"
using namespace std;

Endereco::Endereco()
{
    //default
}

void Endereco::set_adress()
{
    string street,district,city,code,number;

    cout << "CADASTRANDO ENDERE�O" << endl;
    cout << "Insira a rua: " << endl;
    getline(cin,street);
    cout << "Insira o bairro: " << endl;
    getline(cin,district);
    cout << "Insira a cidade: " << endl;
    getline(cin, city);
    cout << "Insira o CEP: " << endl;
    getline(cin,code);
    cout << "Insira o n�mero do im�vel: " << endl;
    getline(cin,number);

    this->street = street;
    this->district = district;
    this->city = city;
    this->code = code;
    this->number = number;
}

void Endereco::set_endr(string r, string b, string c, string ce, string n)
{
    street = r;
    district = b;
    city = c;
    code = ce;
    number = n;
}

string Endereco::get_adress()
{
    return street + "\n" + district + "\n" + city + "\n" + code + "\n" + number + "\n";

}


string Endereco::retornando_adress()
{
    return "Rua: " + street + "\nBairro: " + district + "\nCidade: " + city + "\nCEP: " + code + "\nN�mero: "
    + number;

}

string Endereco::return_disc()
{
    return "Bairro: " + district + "\nCidade: " + city;
}

string Endereco::getBairro()
{
    return district;
}

string Endereco::getCidade()
{
    return city;
}