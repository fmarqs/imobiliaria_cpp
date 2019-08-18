#include <iostream>
#include "Imobiliaria.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

Imobiliaria::Imobiliaria()
{
    n_casas = 0;
    n_apt = 0;
    n_ter = 0;

}

void Imobiliaria::setCasas(int c)
{
    lerNumero();
    n_casas = n_casas + 1;
}

void Imobiliaria::setApt(int a)
{
    lerNumero();
    n_apt = n_apt + 1;
}

void Imobiliaria::setTer(int t)
{
    lerNumero();
    n_ter = n_ter + 1;
}

void Imobiliaria::cadastroCasa(Casas obj)
{
    obj.setTipo();
    obj.setValor();
    obj.setTitulo();
    obj.setRua();
    obj.setNumero();
    obj.setBairro();
    obj.setCidade();
    obj.setCep();
    obj.setPavimentos();
    obj.setQuartos();
    obj.setAreaC();
    obj.setAreaT();
    casas.push_back(obj);
    setCasas(1);
}

void Imobiliaria::cadastroApartamento(Apartamento obj)
{
    obj.setTipo();
    obj.setValor();
    obj.setTitulo();
    obj.setRua();
    obj.setNumero();
    obj.setBairro();
    obj.setCidade();
    obj.setCep();
    obj.setArea();
    obj.setAndar();
    obj.setCondominio();
    obj.setQuartos();
    obj.setGaragem();
    obj.setPosicao();
    apt.push_back(obj);
    setApt(1);
}

void Imobiliaria::cadastroTerreno(Terreno obj)
{
    obj.setValor();
    obj.setTitulo();
    obj.setRua();
    obj.setNumero();
    obj.setBairro();
    obj.setCidade();
    obj.setCep();
    obj.setArea();
    ter.push_back(obj);
    setTer(1);
}

void Imobiliaria::printCasas()
{
    lerNumero();
    for(int i=0; i<n_casas; i++)
    {
        cout << "Tipo: " << casas[i].getTipo() << endl;
        if(casas[i].getTipo() == 0)
        {
            cout << "Aluguel: " << casas[i].getValor() << endl;
        }else
        cout << "Valor: " << casas[i].getValor() << endl;
        cout << "Titulo: " << casas[i].getTitulo() << endl;
        cout << "Bairro: " << casas[i].getBairro() << endl;
        cout << "Cidade: " << casas[i].getCidade() << endl;
    }
}

void Imobiliaria::printApartamento()
{
    lerNumero();
    for(int i=0; i<n_apt; i++)
    {

        if(apt[i].getTipo() == 0)
        {
            cout << "Aluguel: " << apt[i].getValor() << endl;
        }else
        cout << "Valor: " << apt[i].getValor() << endl;
        cout << "Titulo: " << apt[i].getTitulo() << endl;
        cout << "Bairro: " << apt[i].getBairro() << endl;
        cout << "Cidade: " << apt[i].getCidade() << endl;
}
}

void Imobiliaria::printTerreno()
{
    lerNumero();
    for(int i=0; i<n_ter; i++)
    {
        cout << "Valor: " << ter[i].getValor() << endl;
        cout << "Titulo: " << ter[i].getTitulo() << endl;
        cout << "Bairro: " << ter[i].getBairro() << endl;
        cout << "Cidade: " << ter[i].getCidade() << endl;
    }

}

int Imobiliaria::lerNumero()
{
    ifstream imov;
    imov.open("numeroImov.txt", ios::in);
    if(!imov.is_open())
    {
        cout << "Impossivel abrir arquivo" << endl;
        imov.close();
        return 0;
    }

    imov >> n_casas;
    imov >> n_apt;
    imov >> n_ter;
}

int Imobiliaria::lerLista()
{

     ifstream lista;
     lista.open("ListaImoveis.txt", ios::in);
     if(!lista.is_open())
     {
         cout << "Impossivel abrir arquivo" << endl;
         lista.close();
         return 0;
     }

    lerNumero();

    string b, ci, ce, r, tit;
    int tipo;
    double val;
    int num, id;

    while(1){
        if(lista.eof() || lista.fail() || !lista.good())
            break;
        lista >> tipo;
        lista >> val;
        lista.ignore();
        getline(lista, tit);
        getline(lista, r);
        lista >> num;
        lista.ignore();
        getline(lista, b);
        getline(lista, ci);
        getline(lista, ce);
        if(id == 1)
        {
            int pav, q;
            double areac, areat;
            for(int i=0; i<n_casas; i++)
            {
                lista >> pav;
                lista >> q;
                lista >> areac;
                lista >> areat;
                Casas obj = Casas();
                obj.lerCasas(tipo, val, tit, r, num,  b,
        ci, ce, pav, q, areac, areat);
                casas.push_back(obj);
            }}
            else if(id == 2)
            {
                int an, q, gar;
                string pos;
                double cond, ar;
                for(int i =0; i<n_apt; i++)
                {
                    lista >> ar;
                    lista >> an;
                    lista >> cond;
                    lista >> q;
                    lista >> gar;
                    cin.ignore();
                    lista >> pos;
                    Apartamento obj = Apartamento();
                    obj.lerApt(tipo,val, tit, r, num,  b,  ci,ce, ar, cond, q, an, gar, pos);
                    apt.push_back(obj);
                }
            }else if(id == 3)
            {
              double ar;
              for(int i=0; i<n_ter; i++)
              {
                lista >> ar;
                Terreno obj = Terreno();
                obj.lerTerreno(val, tit,  r,  num,  b,  ci,ce, ar);
                ter.push_back(obj);
              }
            }
        }
        lista.close();
      }


int Imobiliaria::salvarDados()
{

    ofstream lista, imov;
    imov.open("numeroImov.txt", ios::trunc);
    lista.open("ListaImoveis.txt", ios::trunc);

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
    imov.close();

    for(int i=0; i<casas.size(); i++)
    {
        lista << casas[i].getTipo() << endl;
        lista << casas[i].getValor() << endl;
        lista << casas[i].getTitulo() << endl;
        lista << casas[i].getRua() << endl;
        lista << casas[i].getBairro() << endl;
        lista << casas[i].getNumero() << endl;
        lista << casas[i].getCidade() << endl;
        lista << casas[i].getCep() << endl;
        lista << casas[i].getPavimentos() << endl;
        lista << casas[i].getQuartos() << endl;
        lista << casas[i].getAreaC() << endl;
        lista << casas[i].getAreaT() << endl;
        lista << casas[i].getId() << endl;
    }

    for(int i=0; i<apt.size(); i++)
    {
        lista << apt[i].getTipo() << endl;
        lista << apt[i].getValor() << endl;
        lista << apt[i].getTitulo() << endl;
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
        lista << apt[i].getId() << endl;
    }

    for(int i=0; i<ter.size(); i++)
    {
        lista << ter[i].getValor() << endl;
        lista << ter[i].getTitulo() << endl;
        lista << ter[i].getRua() << endl;
        lista << ter[i].getBairro() << endl;
        lista << ter[i].getNumero() << endl;
        lista << ter[i].getCidade() << endl;
        lista << ter[i].getCep() << endl;
        lista << ter[i].getArea() << endl;
        lista << ter[i].getId() << endl;
    }

    lista.close();
    imov.close();
}


void Imobiliaria::listaTodos()
{
    lerNumero();
    int opt;
    cout << "IMÓVEIS DISPONÍVEIS" << endl;
    cout << "Escolha um tipo de imóvel" << endl;
    cout << "1 - CASAS\n 2 - APARTAMENTO\n 3 - TERRENO" << endl;
    cin >> opt;

    if(opt == 1){
        for(int i=0;i<n_casas;i++){
            cout << "Título: " << casas[i].getTitulo() << endl;
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
    }else if(opt == 2){
        for(int i=0;i<n_apt;i++){
            cout << "Título: " << apt[i].getTitulo() << endl;
            cout << "Valor: " << apt[i].getValor() << endl;
            cout << "Rua: " << apt[i].getRua() << endl;
            cout << "Numero: " << apt[i].getNumero() << endl;
            cout << "Bairro: " << apt[i].getBairro() << endl;
            cout << "Cidade: " << apt[i].getCidade() << endl;
            cout << "CEP: " << apt[i].getCep() << endl;
            cout << "Area: " << apt[i].getArea() << endl;
            cout << "Andar: " << apt[i].getAndar() << endl;
            cout << "Valor do condominio: " << apt[i].getCondominio() << endl;
            cout << "Quartos: " << apt[i].getQuartos() << endl;
            cout << "Vagas na garagem: " << apt[i].getGaragem() << endl;
            cout << "Posicao: " << apt[i].getPosicao() << endl;
          }
    }else if(opt == 3){
        for(int i=0;i<n_ter;i++){
            cout << "Título: " << ter[i].getTitulo() << endl;
            cout << "Valor: " << ter[i].getValor() << endl;
            cout << "Rua: " << ter[i].getRua() << endl;
            cout << "Numero: " << ter[i].getNumero() << endl;
            cout << "Bairro: " << ter[i].getBairro() << endl;
            cout << "Cidade: " << ter[i].getCidade() << endl;
            cout << "CEP: " << ter[i].getCep() << endl;
            cout << "Area: " << ter[i].getArea() << endl;
        }
}}
