#ifndef IMOBILIARIA_H
#define IMOBILIARIA_H

#include "Casas.h"
#include "Apartamento.h"
#include "Terreno.h"
#include "Imoveis.h"
#include <iostream>
#include <vector>

class Imobiliaria
{
    protected:
        std::vector<Casas> casas;
        std::vector<Apartamento> apt;
        std::vector<Terreno> ter;
        int n_casas;
        int n_apt;
        int n_ter;

    public:
        Imobiliaria();
        void setCasas(int c);
        void setApt(int a);
        void setTer(int t);
        void cadastroCasa(Casas obj);
        void cadastroApartamento(Apartamento obj);
        void cadastroTerreno(Terreno obj);
        void printCasas();
        void printApartamento();
        void printTerreno();
        int lerDados();
        int salvarDados();

};


#endif
