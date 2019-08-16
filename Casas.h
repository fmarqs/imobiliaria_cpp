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
        int getPavimentos();
        int getQuartos();
        double getAreaTerreno();
        double getAreaConstruida();

        void setPavimentos();
        void setQuartos();
        void setAreaTerreno();
        void setAreaConstruida();

};


#endif