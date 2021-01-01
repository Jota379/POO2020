#include <iostream>
#include <string>
#include "Ilha.h"

using namespace std;

int Refugio_Pirata::idRefugio_Pirata = 0;

Refugio_Pirata::Refugio_Pirata(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idRefugio_Pirata++;
    ostringstream passanome;
    passanome << "RefugioPirata" << idRefugio_Pirata;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Refugio_Pirata::~Refugio_Pirata() {
    cout << "A destruir " << getNometerritorio() << endl;
}

int Pescaria::idPescaria = 0;

Pescaria::Pescaria(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    idPescaria++;
    ostringstream passanome;
    passanome << "Pescaria" << idPescaria;
    nome = passanome.str();
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Pescaria::~Pescaria() {
    cout << "A destruir " << getNometerritorio() << endl;
}