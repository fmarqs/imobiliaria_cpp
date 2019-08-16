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
        void cadastraEndereco();
        void setarEndereco(std::string r, int n, std::string b, std::string ce, std::string ci);

};

#endif