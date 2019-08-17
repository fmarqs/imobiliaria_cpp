#ifndef CASAS_H
#define CASAS_H

#include "Imoveis.h"

class Casas: public Imoveis
{
    private:
        int pavimentos, quartos;
        double areaTerreno, areaConstruida;

    public:
        Casas();
        std::string toStringCasas();
        void cadastraCasa();
        void setCasa(int pav, int q, double areac, double areat);
        int getPavimentos();
        int getQuartos();
        double getAreaT();
        double getAreaC();


};


#endif
