#ifndef IMOVEIS_H
#define IMOVEIS_H

#include "Endereco.h"

#include <iostream>

class Imoveis
{
    protected:
        double valor;
        Endereco endereco;
        bool tipoOferta;
    
    public:
        Imoveis();
        double getValor();
        bool getTipo();
        Endereco getEndereco();

        void setValor();
        void setTipo();
        void setEndereco();
};


#endif
