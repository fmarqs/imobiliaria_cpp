#include "Imobiliaria.h"
#include <fstream>
#include <cctype>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

Imobiliaria::Imobiliaria()
{
    n_houses = 0;
    n_apt = 0;
    n_ground = 0;
}

void Imobiliaria::set_houses(int h)
{
    n_houses = n_houses + h;
}

void Imobiliaria::set_apt(int a)
{
    n_apt = n_apt + a;
}

void Imobiliaria::set_ground(int g)
{
    n_ground = n_ground + g;
}

void Imobiliaria::cadastro_houses(Casa obj)
{
    houses.push_back(obj);
    set_houses(1);

}

void Imobiliaria::cadastro_apt(Apartamento obj)
{
    apt.push_back(obj);
    set_apt(1);
}

void Imobiliaria::cadastro_ground(Terreno obj)
{
    ground.push_back(obj);
    set_ground(1);
}

int Imobiliaria::Saved_Archives()
{
    ofstream file, amount;
    file.open("list.txt", ios::trunc);
    amount.open("amount.txt", ios::trunc);
    if(!file.is_open() || !amount.is_open()){
        cout << "Archive not found" << endl;
        file.close();
        amount.close();
        return 0;
    }

    amount << n_houses << endl;
    amount << n_apt << endl;
    amount << n_ground << endl;
    amount.close();



    for(int i=0;i<n_houses;i++){
        file << houses[i].get_id() << endl;
        file << houses[i].get_title() << endl;
        file << houses[i].get_type() << endl;
        file << houses[i].get_value() << endl;
        file << houses[i].return_adress();
        file << houses[i].get_floors() << endl;
        file << houses[i].get_rooms() << endl;
        file << houses[i].get_areaC() << endl;
        file << houses[i].get_areaT() << endl;
    }

    for(int i=0;i<n_apt;i++){
        file << apt[i].get_id() << endl;
        file << apt[i].get_title() << endl;
        file << apt[i].get_type() << endl;
        file << apt[i].get_value() << endl;
        file << apt[i].return_adress();
        file << apt[i].get_floor() << endl;
        file << apt[i].get_rooms() << endl;
        file << apt[i].get_vanc() << endl;
        file << apt[i].get_position() << endl;
        file << apt[i].get_value_cond() << endl;
        file << apt[i].get_area() << endl;
    }

    for(int i=0;i<n_ground;i++){
        file << ground[i].get_id() << endl;
        file << ground[i].get_title() << endl;
        file << ground[i].get_type() << endl;
        file << ground[i].get_value() << endl;
        file << ground[i].return_adress();
        file << ground[i].get_area() << endl;
    }
    file.close();
}

int Imobiliaria::Read_Archives()
{
    ifstream file, imov;
    file.open("list.txt");
    imov.open("amount.txt");
    if(!file.is_open() || !imov.is_open()){
        cout << "Impossivel abrir" << endl;
        file.close();
        imov.close();
        return 0;
    }

    imov >> n_houses;
    imov >> n_apt;
    imov >> n_ground;
    imov.close();

    int id;
    string titulo, rua, bairro, cidade, cep, numero,tipo;
    double val;

    while(1){
        file >> id;
        file.ignore();
        if(file.eof() || file.fail() || !file.good())
            break;
        getline(file,titulo);
        getline(file,tipo);
        file >> val;
        file.ignore();
        getline(file, rua);
        getline(file,bairro);
        getline(file,cidade);
        getline(file,cep);
        getline(file,numero);
        if(id == 1){
                int pav,q;
                double areac, areat;
                file >> pav;
                file >> q;
                file >> areac;
                file >> areat;
                Casa obj = Casa();
                obj.set_Casa(titulo,tipo,val,rua,bairro,cidade,cep,numero,pav,q,areac,areat);
                houses.push_back(obj);
        }else if(id == 2){
                int andar, q, vagas;
                string pos;
                double cond,area;
                file >> andar;
                file >> q;
                file >> vagas;
                file.ignore();
                getline(file,pos);
                file >> cond;
                file >> area;
                Apartamento obj =  Apartamento();
                obj.set_Apt(titulo,tipo,val,rua,bairro,cidade,cep,numero,andar,q,vagas,pos,cond,area);
                apt.push_back(obj);
        }else if(id == 3){
                double ar;
                file >> ar;
                Terreno obj = Terreno();
                obj.set_ter(titulo,tipo,val,rua,bairro,cidade,cep,numero,ar);
                ground.push_back(obj);

        }}

    file.close();

}

void Imobiliaria::imoveis_disp()
{
    cout << endl;
     for(int i=0;i<n_houses;i++){
            cout << "-------- CASA [" << i << "] ---------------" << endl;
            cout << "Titulo: " << houses[i].get_title() << endl;
            cout << "Valor: " << houses[i].get_value() << endl;
            cout << houses[i].print_adress_sep() << endl;
        }
    
        for(int i=0;i<n_apt;i++){
            cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
            cout << "Titulo: " << apt[i].get_title() << endl;
            cout << "Valor: " << apt[i].get_value() << endl;
            cout << apt[i].print_adress_sep() << endl;
        }
        for(int i=0;i<n_ground;i++){
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress_sep() << endl;
        }
}

void Imobiliaria::imoveis_especial()
{
    int op;
    cout << "1 - LISTAR CASAS\n2 - LISTAR APARTAMENTOS\n3 - LISTAR TERRENOS";
    cin >> op;

    if(op == 1)
    {
        for(int i=0; i<n_houses; i++)
        {
        cout << "-------- CASA [" << i << "] ---------------" << endl;
        cout << "Titulo: " << houses[i].get_title() << endl;
        cout << "Disponivel para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Area construida: " << houses[i].get_areaC() << endl;
        cout << "Area total: " << houses[i].get_areaT() << endl << endl;

        }
    }else if(op == 2)
    {
        for(int i=0; i<n_apt; i++)
        {
        cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
        cout << "Titulo: " << apt[i].get_title() << endl;   
        cout << "Disponivel para: " << apt[i].get_type() << endl;
        cout << "Valor: " << apt[i].get_value() << endl;
        cout << apt[i].print_adress() << endl;
        cout << "Andar: " << apt[i].get_floor() << endl;
        cout << "Quartos: " << apt[i].get_rooms() << endl;
        cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
        cout << "Posicao: " << apt[i].get_position() << endl;
        cout << "Valor do condominio: " << apt[i].get_value_cond() << endl;
        cout << "Area total: " << apt[i].get_area() << endl << endl;
        }   
    }else if(op == 3)
    {
        for(int i=0; i<n_ground; i++)
        {
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Disponivel para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Area do terreno: " << ground[i].get_area() << endl << endl;
        }
    }
}

void Imobiliaria::imoveis_categoria()
{   
    cout << "1 - LISTAR POR ALUGUEL" << endl;
    cout << "2 - LISTAR POR VENDA" << endl;
    int opt;
    cin >> opt;

    if(opt == 2)
    {
    for(int i=0; i<n_houses; i++)
    {
        if(boost::iequals(houses[i].get_type(), "VENDA"))
        {
        cout << "-------- CASA [" << i << "] ---------------" << endl;
        cout << "Titulo: " << houses[i].get_title() << endl;
        cout << "Disponivel para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Area construida: " << houses[i].get_areaC() << endl;
        cout << "Area total: " << houses[i].get_areaT() << endl << endl;
        }
    }
    for(int i=0; i<n_apt; i++)
    {
        if(boost::iequals(apt[i].get_type(), "VENDA"))
        {
        cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
        cout << "Titulo: " << apt[i].get_title() << endl;   
        cout << "Disponivel para: " << apt[i].get_type() << endl;
        cout << "Valor: " << apt[i].get_value() << endl;
        cout << apt[i].print_adress() << endl;
        cout << "Andar: " << apt[i].get_floor() << endl;
        cout << "Quartos: " << apt[i].get_rooms() << endl;
        cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
        cout << "Posicao: " << apt[i].get_position() << endl;
        cout << "Valor do condominio: " << apt[i].get_value_cond() << endl;
        cout << "Area total: " << apt[i].get_area() << endl << endl;
        }
    }
    for(int i=0; i<n_ground; i++)
    {
        if(boost::iequals(ground[i].get_type(), "VENDA"))
        {
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Disponivel para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Area do terreno: " << ground[i].get_area() << endl << endl;
        }
    }
    }
    else if(opt == 1)
    {
        for(int i=0; i<n_houses; i++)
        {
            if(boost::iequals(houses[i].get_type(), "ALUGUEL"))
            {
        cout << "-------- CASA [" << i << "] ---------------" << endl;
        cout << "Titulo: " << houses[i].get_title() << endl;
        cout << "Disponivel para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Area construida: " << houses[i].get_areaC() << endl;
        cout << "Area total: " << houses[i].get_areaT() << endl << endl;
            }
        }

        for(int i=0; i<n_apt; i++)
        {
            if(boost::iequals(apt[i].get_type(), "ALUGUEL"))
            {
                
            cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
            cout << "Titulo: " << apt[i].get_title() << endl;   
            cout << "Disponivel para: " << apt[i].get_type() << endl;
            cout << "Valor: " << apt[i].get_value() << endl;
            cout << apt[i].print_adress() << endl;
            cout << "Andar: " << apt[i].get_floor() << endl;
            cout << "Quartos: " << apt[i].get_rooms() << endl;
            cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
            cout << "Posicao: " << apt[i].get_position() << endl;
            cout << "Valor do condominio: " << apt[i].get_value_cond() << endl;
            cout << "Area total: " << apt[i].get_area() << endl << endl;
        
            }
        }

        for(int i=0; i<n_ground; i++)
        {
            if(boost::iequals(ground[i].get_type(), "ALUGUEL"))
        {
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Disponivel para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Area do terreno: " << ground[i].get_area() << endl << endl;
        }
        }

    }
}

void Imobiliaria::buscar_bairro()
{
    string ba;
    cout << "Digite o nome do bairro: " << endl;
    getline(cin, ba);

    for(int i=0; i<n_houses; i++)
    {
        if(boost::iequals(houses[i].return_bairro(), ba))
        {
          cout << "-------- CASA [" << i << "] ---------------" << endl;
        cout << "Titulo: " << houses[i].get_title() << endl;
        cout << "Disponivel para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Area construida: " << houses[i].get_areaC() << endl;
        cout << "Area total: " << houses[i].get_areaT() << endl << endl;  
        }
    }

    for(int i=0; i<n_apt; i++)
    {
        if(boost::iequals(apt[i].return_bairro(), ba))
        {
             cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
            cout << "Titulo: " << apt[i].get_title() << endl;   
            cout << "Disponivel para: " << apt[i].get_type() << endl;
            cout << "Valor: " << apt[i].get_value() << endl;
            cout << apt[i].print_adress() << endl;
            cout << "Andar: " << apt[i].get_floor() << endl;
            cout << "Quartos: " << apt[i].get_rooms() << endl;
            cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
            cout << "Posicao: " << apt[i].get_position() << endl;
            cout << "Valor do condominio: " << apt[i].get_value_cond() << endl;
            cout << "Area total: " << apt[i].get_area() << endl << endl;
        }   
    }

    for(int i=0; i<n_ground; i++)
    {
        if(boost::iequals(ground[i].return_bairro(), ba))
        {
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Disponivel para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Area do terreno: " << ground[i].get_area() << endl << endl;
        }
    }
    

}

void Imobiliaria::buscar_cidade()
{
    string ci;
    cout << "Digite a cidade: " << endl;
    getline(cin, ci);

    for(int i=0; i<n_houses; i++)
    {
        if(boost::iequals(houses[i].return_cidade(), ci)) 
        {  
        cout << "-------- CASA [" << i << "] ---------------" << endl;
        cout << "Titulo: " << houses[i].get_title() << endl;
        cout << "Disponivel para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Area construida: " << houses[i].get_areaC() << endl;
        cout << "Area total: " << houses[i].get_areaT() << endl << endl;        
        }
    }

    for(int i=0; i<n_apt; i++)
    {
        if(boost::iequals(apt[i].return_cidade(), ci))
        {
        cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
            cout << "Titulo: " << apt[i].get_title() << endl;   
            cout << "Disponivel para: " << apt[i].get_type() << endl;
            cout << "Valor: " << apt[i].get_value() << endl;
            cout << apt[i].print_adress() << endl;
            cout << "Andar: " << apt[i].get_floor() << endl;
            cout << "Quartos: " << apt[i].get_rooms() << endl;
            cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
            cout << "Posicao: " << apt[i].get_position() << endl;
            cout << "Valor do condominio: " << apt[i].get_value_cond() << endl;
            cout << "Area total: " << apt[i].get_area() << endl << endl;
        }
    }

    for(int i=0; i<n_ground; i++)
    {
        if(boost::iequals(ground[i].return_cidade(), ci))
        {
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Disponivel para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Area do terreno: " << ground[i].get_area() << endl << endl;
        }
    }
}

void Imobiliaria::buscar_titulo()
{
    string tit;
    cout << "Digite o titulo: " << endl;
    getline(cin, tit);

    for(int i=0; i<n_houses; i++)
    {
        if(boost::iequals(houses[i].get_title(), tit))
        {
            cout << "-------- CASA [" << i << "] ---------------" << endl;
        cout << "Titulo: " << houses[i].get_title() << endl;
        cout << "Disponivel para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Area construida: " << houses[i].get_areaC() << endl;
        cout << "Area total: " << houses[i].get_areaT() << endl << endl;
        }
    }

    for(int i=0; i<n_apt; i++)
    {
        if(boost::iequals(apt[i].get_title(), tit))
        {
        cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
            cout << "Titulo: " << apt[i].get_title() << endl;   
            cout << "Disponivel para: " << apt[i].get_type() << endl;
            cout << "Valor: " << apt[i].get_value() << endl;
            cout << apt[i].print_adress() << endl;
            cout << "Andar: " << apt[i].get_floor() << endl;
            cout << "Quartos: " << apt[i].get_rooms() << endl;
            cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
            cout << "Posicao: " << apt[i].get_position() << endl;
            cout << "Valor do condominio: " << apt[i].get_value_cond() << endl;
            cout << "Area total: " << apt[i].get_area() << endl << endl;
        }   
    }

    for(int i=0; i<n_ground; i++)
    {
        if(boost::iequals(ground[i].get_title(), tit))
        {
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Disponivel para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Area do terreno: " << ground[i].get_area() << endl << endl;
        }
    }
}

void Imobiliaria::buscar_valor()
{
    double val;
    cout << "Digite o valor: " << endl; //ler abaixo
    cin >> val;

    for(int i=0; i<n_houses; i++)
    {
        if(val > houses[i].get_value())
        {
         cout << "-------- CASA [" << i << "] ---------------" << endl;
        cout << "Titulo: " << houses[i].get_title() << endl;
        cout << "Disponivel para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Area construida: " << houses[i].get_areaC() << endl;
        cout << "Area total: " << houses[i].get_areaT() << endl << endl;   
        }
    }

    for(int i=0; i<n_apt; i++)
    {
        if(val > apt[i].get_value())
        {
            cout << "------- APARTAMENTO [" << i << "] -------------" << endl;
            cout << "Titulo: " << apt[i].get_title() << endl;   
            cout << "Disponivel para: " << apt[i].get_type() << endl;
            cout << "Valor: " << apt[i].get_value() << endl;
            cout << apt[i].print_adress() << endl;
            cout << "Andar: " << apt[i].get_floor() << endl;
            cout << "Quartos: " << apt[i].get_rooms() << endl;
            cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
            cout << "Posicao: " << apt[i].get_position() << endl;
            cout << "Valor do condominio: " << apt[i].get_value_cond() << endl;
            cout << "Area total: " << apt[i].get_area() << endl << endl;
        }
    }

    for(int i=0; i<n_ground; i++)
    {
        if(val > ground[i].get_value())
        {
            cout << " ------ TERRENO [" << i << "] -------" << endl;
            cout << "Titulo: " << ground[i].get_title() << endl;
            cout << "Disponivel para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Area do terreno: " << ground[i].get_area() << endl << endl;
        }
    }
}

void Imobiliaria::remover_imov()
{
    int o,op;
    cout << "Que tipo de imóvel desejas remover?" << endl;
    cout << "[1] CASA | [2] APT | [3] TERRENO" << endl;
    cin >> o;

    if(o==1){
        if(n_houses == 0){
            cout << "Não há casas" << endl << endl;
            remover_imov();
        }
        for(int i=0;i<n_houses;i++){
        cout << "Título: " << houses[i].get_title() << endl;
        cout << "Disponível para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Área construída: " << houses[i].get_areaC() << endl;
        cout << "Área total: " << houses[i].get_areaT() << endl << endl;

        cout << "Deseja remover essa casa?" << endl;
        cout << "[1] SIM | [QUALQUER NUMERO] NÃO" << endl;
        cin >> op;
        if(op==1){
            houses[i].set_remov(1);
            n_houses = n_houses - 1;
            cout << "Excluido com sucesso" << endl;
            break;

        }
    }

    }else if(o==2){
        if(n_apt == 0){
            cout << "Não há apartamentos" << endl << endl;
            remover_imov();
        }
        for(int i=0;i<n_apt;i++){
        cout << "Título: " << apt[i].get_title() << endl;
        cout << "Disponível para: " << apt[i].get_type() << endl;
        cout << "Valor: " << apt[i].get_value() << endl;
        cout << apt[i].print_adress() << endl;
        cout << "Andar: " << apt[i].get_floor() << endl;
        cout << "Quartos: " << apt[i].get_rooms()<< endl;
        cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
        cout << "Posição: " << apt[i].get_position() << endl;
        cout << "Valor do condomínio: " << apt[i].get_value_cond() << endl;
        cout << "Área total: " << apt[i].get_area() << endl << endl;

        cout << "Deseja remover essa casa?" << endl;
        cout << "[1] SIM | [QUALQUER NUMERO] NÃO" << endl;
        cin >> op;
        if(op==1){
            apt[i].set_remov(1);
            n_apt = n_apt - 1;
            cout << "Excluido com sucesso" << endl;
            break;
        }}
    }else if(o==3){
        if(n_ground == 0){
            cout << "Não há terrenos" << endl << endl;
            remover_imov();
        }
        for(int i=0;i<n_ground;i++){
        cout << "Título: " << ground[i].get_title() << endl;
        cout << "Disponível para: " << ground[i].get_type() << endl;
        cout << "Valor: " << ground[i].get_value() << endl;
        cout << ground[i].print_adress() << endl;
        cout << "Área do terreno: " << ground[i].get_area() << endl << endl;

        cout << "Deseja remover essa casa?" << endl;
        cout << "[1] SIM | [QUALQUER NUMERO] NÃO" << endl;
        cin >> op;
        if(op==1){
            ground[i].set_remov(1);
            n_ground = n_ground - 1;
            cout << "Excluido com sucesso" << endl;
            break;
        }

        }

}}

void Imobiliaria::editar_houses(){
    int op, o;
    for(int i=0; i<n_houses; i++){
        cout << "Título: " << houses[i].get_title() << endl;
        cout << "Disponível para: " << houses[i].get_type() << endl;
        cout << "Valor: " << houses[i].get_value() << endl;
        cout << houses[i].print_adress() << endl;
        cout << "Pavimentos: " << houses[i].get_floors() << endl;
        cout << "Quartos: " << houses[i].get_rooms() << endl;
        cout << "Área construída: " << houses[i].get_areaC() << endl;
        cout << "Área total: " << houses[i].get_areaT() << endl << endl;

        cout << "Deseja editar essa casa?" << endl;
        cout << "[1] SIM | [QUALQUER TECLA] NÃO" << endl;
        cin >> op;


        if(op==1){
            cout << "O que voce deseja editar?"<<endl;
            cout << "[1]-Titulo"<<endl;
            cout << "[2]-Tipo"<<endl;
            cout << "[3]-Valor"<<endl;
            cout << "[4]-Endereco"<<endl;
            cout << "[5]-Pavimentos"<<endl;
            cout << "[6]-Quartos"<<endl;
            cout << "[7]-Area construida"<<endl;
            cout << "[8]-Area total"<<endl;

            cin >> o;

            switch(o){
                case 1:
                    cin.ignore();
                    houses[i].set_title();
                    break;


                case 2:
                    houses[i].set_type();
                    break;


                case 3:
                    houses[i].set_value();
                    break;

                case 4:
                    cin.ignore();
                    houses[i].set_adress();
                    break;

                case 5:
                    int fl;
                    cout << "Novo numero de pavimentos: ";
                    cin >> fl;
                    houses[i].set_floors(fl);
                    break;

                case 6:
                    int ro;
                    cout << "Novo numero de quartos: ";
                    cin >> ro;
                    houses[i].set_rooms(ro);
                    break;

                case 7:
                    double ac;
                    cout << "Area construida: ";
                    cin >> ac;
                    houses[i].set_areaC(ac);
                    break;

                case 8:
                    double aT;
                    cout << "Area do terreno: ";
                    cin >> aT;
                    houses[i].set_areaT(aT);
                    break;

            }

            cout << "Título: " << houses[i].get_title() << endl;
            cout << "Disponível para: " << houses[i].get_type() << endl;
            cout << "Valor: " << houses[i].get_value() << endl;
            cout << houses[i].print_adress() << endl;
            cout << "Pavimentos: " << houses[i].get_floors() << endl;
            cout << "Quartos: " << houses[i].get_rooms() << endl;
            cout << "Área construída: " << houses[i].get_areaC() << endl;
            cout << "Área total: " << houses[i].get_areaT() << endl << endl;

            cout << "Editado com sucesso" << endl;
            //system("pause");
            //system("cls");
            break;

        }

       // system("cls");
    }
}

void Imobiliaria::editar_apt(){
        int op, o;

    for(int i=0; i<n_apt; i++){
        cout << "Título: " << apt[i].get_title() << endl;
        cout << "Disponível para: " << apt[i].get_type() << endl;
        cout << "Valor: " << apt[i].get_value() << endl;
        cout << apt[i].print_adress() << endl;
        cout << "Andar: " << apt[i].get_floor() << endl;
        cout << "Quartos: " << apt[i].get_rooms()<< endl;
        cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
        cout << "Posição: " << apt[i].get_position() << endl;
        cout << "Valor do condomínio: " << apt[i].get_value_cond() << endl;
        cout << "Área total: " << apt[i].get_area() << endl << endl;

        cout << "Deseja editar esse apartamento?" << endl;
        cout << "[1] SIM | [QUALQUER TECLA] NÃO" << endl;
        cin >> op;

        if(op==1){
            cout << "O que voce deseja editar?"<<endl;
            cout << "[1]-Titulo"<<endl;
            cout << "[2]-Tipo"<<endl;
            cout << "[3]-Valor"<<endl;
            cout << "[4]-Endereco"<<endl;
            cout << "[5]-Andar"<<endl;
            cout << "[6]-Quartos"<<endl;
            cout << "[7]-Vagas na garagem"<<endl;
            cout << "[8]-Posição"<<endl;
            cout << "[9]-Valor do condominio"<<endl;
            cout << "[10]-Area total"<<endl;

            cin >> o;

            switch(o){
                case 1:
                    cin.ignore();
                    apt[i].set_title();
                    break;


                case 2:
                    apt[i].set_type();
                    break;


                case 3:
                    apt[i].set_value();
                    break;

                case 4:
                    cin.ignore();
                    apt[i].set_adress();
                    break;

                case 5:
                    int f;
                    cout << "Andar: ";
                    cin >> f;
                    apt[i].set_floor(f);
                    break;

                case 6:
                    int ro;
                    cout << "Quartos: "; 
                    cin >> ro;
                    apt[i].set_rooms(ro);
                    break;

                case 7:
                    int v;
                    cout << "Vagas na garagem: ";
                    cin >> v;
                    apt[i].set_vanc(v);
                    break;

                case 8:{
                    cin.ignore();
                    string po;
                    cout << "Posicao: ";
                    getline(cin, po);
                    apt[i].set_position(po);
                    break;
                }
                case 9:
                    double val;
                    cout << "Valor do condominio: "; 
                    cin >> val;
                    apt[i].set_value_cond(val);
                    break;

                case 10:
                    double ar;
                    cout << "Area: ";
                    cin >> ar;
                    apt[i].set_area(ar);
                    break;

            }

            cout << "Título: " << apt[i].get_title() << endl;
            cout << "Disponível para: " << apt[i].get_type() << endl;
            cout << "Valor: " << apt[i].get_value() << endl;
            cout << apt[i].print_adress() << endl;
            cout << "Andar: " << apt[i].get_floor() << endl;
            cout << "Quartos: " << apt[i].get_rooms()<< endl;
            cout << "Vagas na garagem: " << apt[i].get_vanc() << endl;
            cout << "Posição: " << apt[i].get_position() << endl;
            cout << "Valor do condomínio: " << apt[i].get_value_cond() << endl;
            cout << "Área total: " << apt[i].get_area() << endl << endl;

            cout << "Editado com sucesso" << endl;
            //system("pause");
            //system("cls");
            break;

        }

        //system("cls");
    }

}

void Imobiliaria::editar_ground()
{
     int op, o;

    for(int i=0; i<n_ground; i++){
        cout << "Título: " << ground[i].get_title() << endl;
        cout << "Disponível para: " << ground[i].get_type() << endl;
        cout << "Valor: " << ground[i].get_value() << endl;
        cout << ground[i].print_adress() << endl;
        cout << "Área do terreno: " << ground[i].get_area() << endl << endl;

        cout << "Deseja editar esse terreno?" << endl;
        cout << "[1] SIM | [QUALQUER TECLA] NÃO" << endl;
        cin >> op;

        if(op==1){
            cout << "O que voce deseja editar?"<<endl;
            cout << "[1]-Titulo"<<endl;
            cout << "[2]-Tipo"<<endl;
            cout << "[3]-Valor"<<endl;
            cout << "[4]-Endereco"<<endl;
            cout << "[5]-Area"<<endl;

            cin >> o;

            switch(o){
                case 1:
                    cin.ignore();
                    ground[i].set_title();
                    break;


                case 2:
                    ground[i].set_type();
                    break;


                case 3:
                    ground[i].set_value();
                    break;

                case 4:
                    cin.ignore();
                    ground[i].set_adress();
                    break;

                case 5:
                    double ar;
                    cout << "Nova area: ";
                    cin >>ar;
                    ground[i].set_ground2(ar);
                    break;



            }

            cout << "Título: " << ground[i].get_title() << endl;
            cout << "Disponível para: " << ground[i].get_type() << endl;
            cout << "Valor: " << ground[i].get_value() << endl;
            cout << ground[i].print_adress() << endl;
            cout << "Área do terreno: " << ground[i].get_area() << endl << endl;


            cout << "Editado com sucesso" << endl;
            //system("pause");
            //system("cls");
            break;

        }

        //system("cls");
    }

}