#include <iostream>
#include "Imobiliaria.h"
#include <string>
#include <fstream>

using namespace std;

Imobiliaria::Imobiliaria()
{

}

void Imobiliaria::setCasas(int c)
{
    n_casas = c + 1;
}

void Imobiliaria::setApt(int a)
{
    n_apt = a + 1;
}

void Imobiliaria::setTer(int t)
{
    n_ter = t + 1;
}

void Imobiliaria::cadastroCasa(Casas obj)
{
    obj.setTipo();
    obj.setValor();
    obj.cadastraEndereco();
    obj.cadastraCasa();
    casas.push_back(obj);
    setCasas(1);
}

void Imobiliaria::cadastroApartamento(Apartamento obj)
{
    obj.setTipo();
    obj.setValor();
    obj.cadastraEndereco();
    obj.cadastraApt();
    apt.push_back(obj);
    setApt(1);
}

void Imobiliaria::cadastroTerreno(Terreno obj)
{
    obj.setValor();
    obj.cadastraEndereco();
    obj.cadastraTerreno();
    ter.push_back(obj);
    setTer(1);
}

void Imobiliaria::printCasas()
{

    for(int i=0; i<n_casas; i++)
    {
        cout << "Tipo: " << casas[i].getTipo() << endl;
        cout << "Valor: " << casas[i].getValor() << endl;
        cout << "Rua: " << casas[i].getRua() << endl;
        cout << "Numero: " << casas[i].getNumero() << endl;
        cout << "Bairro: " << casas[i].getBairro() << endl;
        cout << "Cidade: " << casas[i].getCidade() << endl;
        cout << "CEP: " << casas[i].getCep() << endl;
        cout << "Pavimentos: " << casas[i].getPavimentos() << endl;
        cout << "Quartos: " << casas[i].getQuartos() << endl;
        cout << "Area construida: " << casas[i].getAreaC() << endl;
        cout << "Area do terreno: " << casas[i].getAreaT() << endl;

    }
}

void Imobiliaria::printApartamento()
{
    
    for(int i=0; i<n_apt; i++)
    {
        cout << "Tipo: " << apt[i].getTipo() << endl;
        cout << "Valor: " << apt[i].getValor() << endl;
        cout << "Rua: " << apt[i].getRua() << endl;
        cout << "Numero: " << apt[i].getNumero() << endl;
        cout << "Bairro: " << apt[i].getBairro() << endl;
        cout << "Cidade: " << apt[i].getCidade() << endl;
        cout << "CEP: " << apt[i].getCep() << endl;
        cout << "Area: " << apt[i].getArea() << endl;
        cout << "Condominio: " << apt[i].getCondominio() << endl;
        cout << "Quartos: " << apt[i].getQuartos() << endl;
        cout << "Andar: " << apt[i].getAndar() << endl;
        cout << "Garagem: " << apt[i].getGaragem() << endl;
        cout << "Posicao: " << apt[i].getPosicao() << endl;
    }
}

void Imobiliaria::printTerreno()
{
    for(int i=0; i<n_ter; i++)
    {
        cout << "Valor: " << ter[i].getPreco() << endl;
        cout << "Rua: " << ter[i].getRua() << endl;
        cout << "Numero: " << ter[i].getNumero() << endl;
        cout << "Bairro: " << ter[i].getBairro() << endl;
        cout << "Cidade: " << ter[i].getCidade() << endl;
        cout << "CEP: " << ter[i].getCep() << endl;
        cout << "Area: " << ter[i].getArea() << endl;
    }

}

int Imobiliaria::lerDados()
{
     ifstream lista, imov;
     imov.open("numeroImov.txt", ios::in);
     lista.open("ListaImoveis.txt", ios::in);
     if(!lista.is_open() || !imov.is_open())
     {
         cout << "Impossivel abrir arquivo" << endl;
         lista.close();
         imov.close();
         return 0;
     }

    imov >> n_casas;
    imov >> n_apt;
    imov >> n_ter;
    imov.close();

    string b, ci, ce, r;
    int tipo;
    double val;
    int num;

    for(int i=0; i<n_casas; i++)
    {
        double areac, areat;
        int pav, q;
        if(lista.eof())
            return 0;
        lista >> tipo;
        lista >> val;
        lista.ignore();
        getline(lista, r);
        lista >> num;
        lista.ignore();
        getline(lista, b);
        getline(lista, ci);
        getline(lista, ce);
        lista >> pav;
        lista >> q;
        lista >> areac;
        lista >> areat;
        lista.ignore();
        Casas obj = Casas();
        obj.lerCasas(tipo,val, r, num, b, ci, ce, pav, q, areac, areat);
        casas.push_back(obj);
    }

    for(int i=0; i<n_apt; i++)
    {
        string pos;
        double cond, area;
        int a, q, vagas;

        if(lista.eof())
            return 0;

        lista >> tipo;
        lista >> val;
        lista.ignore();
        getline(lista, r);
        lista >> num;
        lista.ignore();
        getline(lista, b);
        getline(lista, ci);
        getline(lista, ce);
        lista >> area;
        lista >> cond;
        lista >> q;
        lista >> a;
        lista >> vagas;
        lista.ignore();
        getline(lista, pos);
        Apartamento obj = Apartamento();
        obj.lerApt(tipo, val, r, num, b, ci, ce, area, cond, q, a, vagas, pos);
        apt.push_back(obj);

    }

    for(int i=0; i<n_ter; i++)
    {
        double ar, pre;

        if(lista.eof())
            return 0;

        lista >> pre;
        lista.ignore();
        getline(lista, r);
        lista >> num;
        lista.ignore();
        getline(lista, b);
        getline(lista, ci);
        getline(lista, ce);
        lista >> ar;
        lista.ignore();
        Terreno obj = Terreno();
        obj.lerTerreno(pre, r, num, b, ci, ce, ar);
        ter.push_back(obj);

    }


}

int Imobiliaria::salvarDados()
{
    ofstream lista, imov;
    imov.open("numeroImov.txt", ios::trunc);
    lista.open("ListaImoveis.txt", ios::app);

    if(!lista.is_open() || !imov.is_open())
    {
        cout << "Impossivel abrir arquivo" << endl;
        lista.close();
        imov.close();
        return 0;
    }

    imov << n_casas << endl;
    imov << n_apt << endl;
    imov << n_ter << endl;

    for(int i=0; i<n_casas; i++)
    {
        lista << casas[i].getTipo() << endl;
        lista << casas[i].getValor() << endl;
        lista << casas[i].getRua() << endl;
        lista << casas[i].getBairro() << endl;
        lista << casas[i].getNumero() << endl;
        lista << casas[i].getCidade() << endl;
        lista << casas[i].getCep() << endl;
        lista << casas[i].getPavimentos() << endl;
        lista << casas[i].getQuartos() << endl;
        lista << casas[i].getAreaC() << endl;
        lista << casas[i].getAreaT() << endl;
    }

    for(int i=0; i<n_apt; i++)
    {
        lista << apt[i].getTipo() << endl;
        lista << apt[i].getValor() << endl;
        lista << apt[i].getRua() << endl;
        lista << apt[i].getBairro() << endl;
        lista << apt[i].getNumero() << endl;
        lista << apt[i].getCidade() << endl;
        lista << apt[i].getCep() << endl;
        lista << apt[i].getArea() << endl;
        lista << apt[i].getCondominio() << endl;
        lista << apt[i].getQuartos() << endl;
        lista << apt[i].getAndar() << endl;
        lista << apt[i].getGaragem() << endl;
        lista << apt[i].getPosicao() << endl;
    }

    for(int i=0; i<n_ter; i++)
    {
        lista << ter[i].getPreco() << endl;
        lista << ter[i].getRua() << endl;
        lista << ter[i].getBairro() << endl;
        lista << ter[i].getNumero() << endl;
        lista << ter[i].getCidade() << endl;
        lista << ter[i].getCep() << endl;
        lista << ter[i].getArea() << endl;
    }

    lista.close();
    imov.close();
}
