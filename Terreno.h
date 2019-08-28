#ifndef TERRENO_H
#define TERRENO_H
#include "Apartamento.h"

class Terreno : public Imovel
{
    protected:
        double area;

    public:
        Terreno();
        void set_ter(std::string t, std::string tipo,double val, std::string r, std::string b, std::string c, std::string ce, std::string num
        , double ar);
        void set_ground();
        double get_area();
        void set_ground2(double ar);
};

#endif // TERRENO_H
