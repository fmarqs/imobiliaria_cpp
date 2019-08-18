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
        void setArea();
        void setCondominio();
        void setQuartos();
        void setAndar();
        void setGaragem();
        void setPosicao();

        double getArea();
        double getCondominio();
        int getQuartos();
        int getAndar();
        int getGaragem();
        std::string getPosicao();
        void lerApt(int tipo, double val, std::string tit, std::string r, int num, std::string b, std::string ci,
        std::string ce, double ar, double cond, int qua, int an, int gar, std::string pos);
};

#endif
