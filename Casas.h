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
        void setPavimentos();
        void setQuartos();
        void setAreaT();
        void setAreaC();

        int getPavimentos();
        int getQuartos();
        double getAreaT();
        double getAreaC();
        void lerCasas(int tipo, double val, std::string tit, std::string r, int num, std::string b, 
        std::string ci, std::string ce, int pav, int q, double areac, double areat);


};


#endif
