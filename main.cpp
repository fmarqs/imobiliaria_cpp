#include "Imobiliaria.h"
#include <iostream>

using namespace std;

int main()
{
    Imobiliaria *r = new Imobiliaria();
    r->Read_Archives();

    int op;
    cout << "1 - CADASTRAR CASA" << endl;
    cout << "2 - CADASTRAR APARTAMENTO" << endl;
    cout << "3 - CADASTRAR TERRENO" << endl;
    cout << "4 - LISTAR TODOS" << endl;
    cout << "5 - LISTAR POR TIPO" << endl;
    cout << "6 - LISTAR POR CATEGORIA" << endl;
    cout << "7 - BUSCAR POR BAIRRO " << endl;
    cout << "8 - BUSCAR POR CIDADE " << endl;
    cout << "9 - BUSCAR POR TITULO " << endl;
    cout << "10 - BUSCAR POR CERTA QUANTIA " << endl;
    cout << "11 - REMOVER IMOVEL" << endl;
    cout << "12 - EDITAR CASA" << endl; 
    cout << "13 - EDITAR APARTAMENTO" << endl;
    cout << "14 - EDITAR TERRENO" << endl;


    cin >> op;
    cin.ignore();
    
    if(op == 1)
    {
        Casa *obj = new Casa();
        obj->set_adress();
        obj->set_title();
        obj->set_type();
        obj->set_value();
        obj->set_houses();
        r->cadastro_houses(*obj);
    }
    else if(op == 2)
    {
        Apartamento *obj1 = new Apartamento();
        obj1->set_adress();
        obj1->set_title();
        obj1->set_type();
        obj1->set_value();
        obj1->set_apartment();
        r->cadastro_apt(*obj1);
    }
    else if(op == 3)
    {
        Terreno *obj = new Terreno();
        obj->set_adress();
        obj->set_title();
        obj->set_type();
        obj->set_value();
        obj->set_ground();
        r->cadastro_ground(*obj);
    }
    else if(op == 4)
    {
        r->imoveis_disp();
    }
    else if(op == 5)
    {
        r->imoveis_especial();
    }
    else if(op == 6)
    {
        r->imoveis_categoria();
    }
    else if(op == 7)
    {
        r->buscar_bairro();
    }
    else if(op == 8)
    {
        r->buscar_cidade();
    }
    else if(op == 9)
    {
        r->buscar_titulo();
    }
    else if(op == 10)
    {
        r->buscar_valor();
    }
    else if(op == 11)
    {
        r->remover_imov();
    }
    else if(op == 12)
    {

        r->editar_houses();
    }
    else if(op == 13)
    {
        r->editar_apt();
    }
    else if(op == 14)
    {
        r->editar_ground();
    }

    r->Saved_Archives();

    return 0;
}