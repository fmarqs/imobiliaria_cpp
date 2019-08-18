#ifndef IMOVEIS_H
#define IMOVEIS_H

#include "Endereco.h"

#include <iostream>

class Imoveis: public Endereco
{
    protected:
        double valor;
        Endereco endereco;
        int tipoOferta;

    public:
        Imoveis();
        double getValor();
        int getTipo();

        void setValor();
        void setTipo();
        void setEndereco();
};


#endif
