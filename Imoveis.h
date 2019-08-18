#ifndef IMOVEIS_H
#define IMOVEIS_H

#include "Endereco.h"

#include <iostream>

class Imoveis: public Endereco
{
    protected:
        double valor;
        int tipoOferta;
        int id;
        std::string titulo;

    public:
        Imoveis();
        double getValor();
        int getTipo();
        int getId();
        std::string getTitulo();

        void setTitulo();
        void setValor();
        void setTipo();
};


#endif
