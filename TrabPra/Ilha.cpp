#include <iostream>
#include <string>
#include "Ilha.h"

using namespace std;

Refugio_Pirata::Refugio_Pirata(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Refugio_Pirata::~Refugio_Pirata() {
    cout << "A destruir " << getNometerritorio() << endl;
}

Pescaria::Pescaria(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Pescaria::~Pescaria() {
    cout << "A destruir " << getNometerritorio() << endl;
}