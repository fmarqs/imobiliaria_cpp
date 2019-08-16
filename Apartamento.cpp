#include "Apartamento.h"
#include <iostream>
#include <string>

using namespace std;

Apartamento::Apartamento()
{
    
}

double Apartamento::getArea()
{
    return area;
}

int Apartamento::getAndar()
{
    return andar;
}

double Apartamento::getCondominio()
{
    return condominio;
}

int Apartamento::getQuartos()
{
    return quartos;
}

int Apartamento::getGaragem()
{
    return garagem;
}

string Apartamento::getPosicao()
{
    return posicao;
}

void Apartamento::setArea()
{
    double a;
    cout << "Area: ";
    cin >> a;
    area = a;
}

void Apartamento::setCondominio()
{
    double cond;
    cout << "Valor do condominio: ";
    cin >> cond;
    condominio = cond;
}

void Apartamento::setQuartos()
{
    int qua;
    cout << "Quartos: ";
    cin >> qua;
    quartos = qua;
}

void Apartamento::setAndar()
{
    int seila;
    cout << "Andar: ";
    cin >> seila;
    andar = seila;
}

void Apartamento::setGaragem()
{
    int garag;
    cout << "Vagas na garagem: ";
    cin >> garag;
    garagem = garag;
}

void Apartamento::setPosicao()
{
    string pos;
    cout << "Posicao: ";
    getline(cin, pos);
    posicao = pos;
}

void Apartamento::print()
{
    
}