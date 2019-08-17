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
}

void Imobiliaria::cadastroApartamento(Apartamento obj)
{
    obj.setTipo();
    obj.setValor();
    obj.cadastraEndereco();
    obj.cadastraApt();
    apt.push_back(obj);
}

void Imobiliaria::cadastroTerreno(Terreno obj)
{
    obj.setValor();
    obj.cadastraEndereco();
    obj.cadastraTerreno();
    ter.push_back(obj);

}

void Imobiliaria::printCasas()
{
    for(int i=0; i<casas.size(); i++)
        cout << casas[i] << endl;
}

void Imobiliaria::printApartamento()
{
    for(int i=0; i<apt.size(); i++)
        cout << apt[i] << endl;
}

void Imobiliaria::printTerreno()
{
    for(int i=0; i<ter.size(); i++)
        cout << ter[i] << endl;

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
    bool tipo;
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
        obj.setCasa(tipo,val, r, num, b, ci, ce, pav, q, areac, areat); //mudar isso aq
        casas.push_back(obj);
    }

    for(int i=0; i<n_apt; i++)
    {
        string pos;
        double cond, area;
        int a, q, vagas;

        if(lista.eof())
            return 0;
        
        getline(lista, tipo);
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
        obj.setApartamento(area, cond, q, a, vagas, pos);
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
        obj.setTerreno(ar, pre);
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
        lista << casas[i].getEndereco() << endl;
        lista << casas[i].getPavimentos() << endl;
        lista << casas[i].getQuartos() << endl;
        lista << casas[i].getAreaC() << endl;
        lista << casas[i].getAreaT() << "\n" << endl;
    }

    for(int i=0; i<n_apt; i++)
    {
        lista << apt[i].getTipo() << endl;
        lista << apt[i].getValor() << endl;
        lista << apt[i].getEndereco() << endl;
        lista << apt[i].getArea() << endl;
        lista << apt[i].getCondominio() << endl;
        lista << apt[i].getQuartos() << endl;
        lista << apt[i].getAndar() << endl;
        lista << apt[i].getGaragem() << endl;
        lista << apt[i].getPosicao() << "\n" << endl;
    }

    for(int i=0; i<n_ter; i++)
    {
        lista << ter[i].getPreco() << endl;
        lista << ter[i].getEndereco() << endl;
        lista << ter[i].getArea() << "\n" << endl;
    }

    lista.close();
    imov.close();
}