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
        void setarEndereco(std::string r, int n, std::string b, std::string ci, std::string ce);
        void print();
        std::string getRua();
        std::string getBairro();
        std::string getCep();
        std::string getCidade();
        int getNumero();

};

#endif
