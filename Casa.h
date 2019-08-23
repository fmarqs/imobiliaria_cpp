#ifndef CASA_H
#define CASA_H
#include "Imovel.h"

class Casa : public Imovel
{
    protected:
        int floors;
        int rooms;
        double area_const;
        double area_ter;

    public:
        Casa();
        void set_Casa(std::string t, std::string tipo, double val, std::string r, std::string b, std::string c, std::string ce, std::string num
        ,int pav, int q, double ar, double a);
        void set_houses();
        void set_floors(int f);
        void set_rooms(int r);
        void set_areaC(double ar);
        void set_areaT(double a);
        int get_floors();
        int get_rooms();
        double get_areaC();
        double get_areaT();

};

#endif // CASA_H
