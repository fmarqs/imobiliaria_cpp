#ifndef ENDERECO_H
#define ENDERECO_H
#include <iostream>

class Endereco
{
    protected:
        std::string street;
        std::string district;
        std::string city;
        std::string code;
        std::string number;

    public:
        Endereco();
        void set_adress();
        void set_especial_adress();
        std::string get_adress();
        void set_endr(std::string r, std::string b, std::string c, std::string ce, std::string n);
        std::string retornando_adress();
        std::string return_disc();
        std::string retornando_especial_adress();
        std::string getBairro();
        std::string getCidade();
};

#endif // ENDERECO_H
