#ifndef TERRENO_H
#define TERRENO_H

#include "Imoveis.h"

class Terreno: public Imoveis
{
    private:
        double area;

    public:
        Terreno();
        double getArea();

        void setArea();

};


#endif
