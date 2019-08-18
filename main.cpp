#include "Casas.h"
#include "Apartamento.h"
#include "Terreno.h"
#include "Imoveis.h"
#include "Imobiliaria.h"
#include <iostream>
#include <string>

void menuPrincipal();
void menuCadastrarCasa();
void menuCadastrarApt();
void menuCadastrarTer();
void menuCadastro();
void menuBuscar();

using namespace std;


void menuCadastrarCasa()
{
    Imobiliaria i = Imobiliaria(); 
    Casas c = Casas();
    
    i.cadastroCasa(c);
    i.salvarDados();


}

void menuCadastrarApt()
{
    Imobiliaria p = Imobiliaria();
    Apartamento a = Apartamento();

    p.cadastroApartamento(a);
    p.salvarDados();
}

void menuCadastrarTer()
{
    Imobiliaria n = Imobiliaria();
    Terreno t = Terreno();

    n.cadastroTerreno(t);
    n.salvarDados();
    menuCadastro();
}

void menuPrincipal()
{
    int op;
    cout << "MENU PRINCIPAL " << endl;
    cout << "1 - CADASTRAR " << endl;
    cout << "2 - EDITAR " << endl;
    cout << "3 - REMOVER " << endl;
    cout << "4 - BUSCAR " << endl;
    cout << "0 - SAIR DO PROGRAMA " << endl;
    cin >> op;
    cin.ignore();

    if(op == 1)
        menuCadastro();
    /*else if(op == 2)
        menuEditar();
    */
    else if(op == 4)
        menuBuscar();
}

void menuCadastro()
{
    int op;

        cout << "\nMENU CADASTRO " << endl;
        cout << "1 - CASA " << endl;
        cout << "2 - APARTAMENTO " << endl;
        cout << "3 - TERRENO " << endl;
        cout << "4 - MENU PRINCIPAL " << endl;
        cin >> op;
        cin.ignore();
        if(op == 1)
            menuCadastrarCasa();
        else if(op == 2)
            menuCadastrarApt();
        else if(op == 3)
            menuCadastrarTer();
        else if(op == 4)
            menuPrincipal();

    
}

void menuBuscar()
{
    int op;
    cout << "MENU BUSCAR" << endl;
    cout << "1 - BUSCAR TODOS " << endl;
    cout << "2 - BUSCAR POR TIPO " << endl;
    cout << "3 - BUSCAR POR CATEGORIA " << endl;
    cin >> op;
    cin.ignore(); 
    if(op == 1)
    {
        Imobiliaria i;
        i.listaTodos();
    }

}

int main()
{
    
    menuPrincipal();
    
}
