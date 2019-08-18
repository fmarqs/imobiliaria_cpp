#ifndef TERRENO_H
#define TERRENO_H

#include "Imoveis.h"

class Terreno: public Imoveis
{
    private:
        double area;

    public:
        Terreno();
        void setArea();

        double getArea();
        void lerTerreno(double val, std::string tit, std::string r, int num, std::string b, std::string ci,
        std::string ce, double ar);

};


#endif
