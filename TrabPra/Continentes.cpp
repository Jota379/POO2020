#include <iostream>
#include <string>
#include "Continentes.h"

using namespace std;

int Planicie::idPlanicie = 0;

Planicie::Planicie(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idPlanicie++;
    ostringstream passanome;
    passanome << "Planicie" << idPlanicie;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Planicie::~Planicie() {
    cout << "Destrui " << getNometerritorio() << endl;
}

int Planicie::recolheOuro(int ano, int turno)
{
    return 1;
}

int Planicie::recolheProd(int ano, int turno)
{
    if(ano == 1)
        return 1;
    if(ano == 2)
        return 2;
    return 0;
}

int Montanha::idMontanha = 0;

Montanha::Montanha(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idMontanha++;
    ostringstream passanome;
    passanome << "Montanha" << idMontanha;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Montanha::~Montanha() {
    cout << "Destrui " << getNometerritorio() << endl;
}

int Montanha::setConquista(int forca, int sorte, bool tec, int nterr)
{
    if ((forca + sorte) >= resistencia)
    {
        turnoConqDecre = 2;
        conquistado = true;
        return 0;
    } 
    return 1;
}

void Montanha::setConquistaADM(bool estado)
{
    turnoConqDecre = 2;
    conquistado = estado;
}

int Montanha::recolheOuro(int ano, int turno)
{   
    turnoConqDecre--;
    return 0;
}

int Montanha::recolheProd(int ano, int turno)
{   
    if (turnoConqDecre < 0)
        return 1;
    return 0;
}

int Fortaleza::idFortaleza = 0;

Fortaleza::Fortaleza(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idFortaleza++;
    ostringstream passanome;
    passanome << "Fortaleza" << idFortaleza;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Fortaleza::~Fortaleza() {
    cout << "Destrui " << getNometerritorio() << endl;
}

int Fortaleza::recolheOuro(int ano, int turno)
{
    return 0;
}

int Fortaleza::recolheProd(int ano, int turno)
{
    return 0;
}

int Mina::idMina = 0;

Mina::Mina(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idMina++;
    ostringstream passanome;
    passanome << "Mina" << idMina;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Mina::~Mina() {
    cout << "Destrui " << getNometerritorio() << endl;
}

int Mina::recolheOuro(int ano, int turno)
{
    if (turno > 6)
        turno = turno - 6;
    if (turno < 4)
        return 1;
    else if (turno < 7)
        return 2;
    return 0;
}

int Mina::recolheProd(int ano, int turno)
{
    return 0;
}

int Duna::idDuna = 0;

Duna::Duna(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idDuna++;
    ostringstream passanome;
    passanome << "Duna" << idDuna;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Duna::~Duna() {
    cout << "Destrui " << getNometerritorio() << endl;
}

int Duna::recolheOuro(int ano, int turno)
{
    
    return 0;
}

int Duna::recolheProd(int ano, int turno)
{
    return 1;
}

int Castelo::idCastelo = 0;

Castelo::Castelo(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idCastelo++;
    ostringstream passanome;
    passanome << "Castelo" << idCastelo;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Castelo::~Castelo() {
    cout << "Destrui " << getNometerritorio() << endl;
}

int Castelo::recolheOuro(int ano, int turno)
{
    return 1;
}

int Castelo::recolheProd(int ano, int turno)
{
    if (turno > 6)
        turno = turno - 6;
    if (turno < 3)
        return 3;
    return 0;
}
