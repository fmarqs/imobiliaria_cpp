#ifndef TERRENO_H
#define TERRENO_H

#include "Imoveis.h"

class Terreno: public Imoveis
{
    private:
        double area, preco;

    public:
        Terreno();
        void cadastraTerreno();
        void setTerreno(double ar, double pre);
        double getArea();
        double getPreco();
        void lerTerreno(double val, std::string r, int num, std::string b, std::string ci,
        std::string ce, double ar);

};


#endif
