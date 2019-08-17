#include "Apartamento.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Apartamento::Apartamento()
{
    
}

void Apartamento::cadastraApt()
{
    double ar, cond;
    int qua, an, gar;
    string pos;

    cout << "\nArea: ";
    cin >> ar;
    area = ar;
    cout << "\nValor do condominio: ";
    cin >> cond;
    condominio = cond;
    cout << "\nQuartos: ";
    cin >> qua;
    quartos = qua;
    cout << "\nAndar: ";
    cin >> an;
    andar = an;
    cout << "\nGaragem: ";
    cin >> gar;
    garagem = gar;
    cin.ignore();
    cout << "\nPosicao: "; 
    getline(cin, pos);
    

    setApartamento(ar, cond, qua, an, gar, pos);

}

void Apartamento::setApartamento(double ar, double cond, int qua, int an, int gar, std::string pos)
{
    area = ar;
    condominio = cond;
    quartos = qua;
    andar = an;
    garagem = gar;
    posicao = pos;
}


string Apartamento::toStringApt()
{
    stringstream apart;

    apart << area << endl << condominio << endl << quartos << endl << andar << endl << garagem << endl << posicao << endl;


    return apart.str();
}

double Apartamento::getArea()
{
    return area;
}

double Apartamento::getCondominio()
{
    return condominio;
}

int Apartamento::getAndar()
{
    return andar;
}

int Apartamento::getGaragem()
{
    return garagem;
}

int Apartamento::getQuartos()
{
    return quartos;
}

string Apartamento::getPosicao()
{
    return posicao;
}
