#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>

class Endereco
{
    
    protected:
        std::string rua, bairro, cep, cidade;
        int numero;

    public:
        Endereco();
        void setRua();
        void setNumero();
        void setBairro();
        void setCidade();
        void setCep();
        std::string getRua();
        std::string getBairro();
        std::string getCep();
        std::string getCidade();
        int getNumero();

};

#endif