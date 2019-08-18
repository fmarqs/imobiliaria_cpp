#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imoveis.h"

class Apartamento: public Imoveis
{
    private:
        double area, condominio;
        int quartos, andar, garagem;
        std::string posicao;

    public:
        Apartamento();
        std::string toStringApt();
        void cadastraApt();
        void setApartamento(double ar, double cond, int qua, int an, int gar, std::string pos);

        double getArea();
        double getCondominio();
        int getQuartos();
        int getAndar();
        int getGaragem();
        std::string getPosicao();
        void lerApt(int tipo, double val, std::string r, int num, std::string b, std::string ci,
        std::string ce, double ar, double cond, int qua, int an, int gar, std::string pos);
};

#endif
