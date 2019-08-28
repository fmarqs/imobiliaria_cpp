#ifndef IMOBILIARIA_H
#define IMOBILIARIA_H
#include "Terreno.h"
#include <vector>

class Imobiliaria:public Imovel
{
    protected:
        std::vector<Casa> houses = std::vector<Casa>();
        std::vector<Apartamento> apt;
        std::vector<Terreno> ground;
        int n_houses;
        int n_apt;
        int n_ground;

    public:
        Imobiliaria();
        void cadastro_houses(Casa obj);
        void cadastro_apt(Apartamento obj);
        void cadastro_ground(Terreno obj);
        int Saved_Archives();
        int Read_Archives();
        void set_houses(int h);
        void set_apt(int a);
        void set_ground(int g);
        void print_houses();
        void print_apt();
        void print_grounds();
        void imoveis_disp();
        void imoveis_especial();
        void imoveis_categoria();
        void buscar_bairro();
        void buscar_cidade();
        void buscar_titulo();
        void buscar_valor();
        void remover_imov();
        void editar_houses();
        void editar_apt();
        void editar_ground();
};

#endif // IMOBILIARIA_H
