#ifndef IMOVEIS_H
#define IMOVEIS_H

#include "Endereco.h"

#include <iostream>

class Imoveis: public Endereco
{
    protected:
        double valor;
        Endereco endereco;
        bool tipoOferta;
    
    public:
        Imoveis();
        double getValor();
        bool getTipo();
        std::string getEndereco();

        void setValor();
        void setTipo();
        void setEndereco();
};


#endif
