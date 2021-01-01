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
