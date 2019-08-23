#ifndef IMOVEL_H
#define IMOVEL_H
#include "Endereco.h"

class Imovel
{
    protected:
        std::string type; // 0 VENDA  |   1 ALUGUEL;
        int id; // 1 CASA   |   2 APT   | 3 TERRENO;
        double value;
        Endereco adress;
        std::string title;
        int remov;

    public:
        Imovel();
        void set_value();
        void set_type();
        std::string return_adress();
        void set_adress();
        std::string get_type();
        double get_value();
        int get_id();
        void set_title();
        std::string get_title();
        std::string print_adress();
        std::string print_adress_sep();
        std::string print_especial_adress();
        void set_especial_adress();
        std::string return_especial_adress();
        std::string return_bairro();
        std::string return_cidade();
        void set_remov(int h);
        int get_remov();
};

#endif // IMOVEL_H
