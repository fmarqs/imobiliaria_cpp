#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Casa.h"

class Apartamento : public Imovel
{
    protected:
        int floor;
        int vanc;
        int rooms;
        double area;
        double value_cond;
        std::string position;

    public:
        Apartamento();
        void set_Apt(std::string t, std::string tipo, double val, std::string r, std::string b, std::string c, std::string ce, std::string num
        ,int a, int q, int v, std::string pos,double cond, double ar);
        void set_apartment();
        void set_floor(int f);
        void set_vanc(int v);
        void set_rooms(int r);
        void set_area(double ar);
        void set_value_cond(double val);
        void set_position(std::string pos);
        int get_floor();
        int get_vanc();
        int get_rooms();
        double get_area();
        double get_value_cond();
        std::string get_position();
};

#endif // APARTAMENTO_H
