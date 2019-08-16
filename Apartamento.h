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
        double getArea();
        double getCondominio();
        int getQuartos();
        int getAndar();
        int getGaragem();
        std::string getPosicao();
        void print();

        void setArea();
        void setCondominio();
        void setQuartos();
        void setAndar();
        void setGaragem();
        void setPosicao();
};

#endif
