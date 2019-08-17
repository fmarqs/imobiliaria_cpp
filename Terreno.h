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

};


#endif
