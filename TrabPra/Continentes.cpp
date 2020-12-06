#include <iostream>
#include <string>
#include "Continentes.h"

using namespace std;

Planicie::Planicie(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Planicie::~Planicie() {
    cout << "Destrui " << getNometerritorio() << endl;
}

Montanha::Montanha(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Montanha::~Montanha() {
    cout << "Destrui " << getNometerritorio() << endl;
}

Fortaleza::Fortaleza(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Fortaleza::~Fortaleza() {
    cout << "Destrui " << getNometerritorio() << endl;
}

Mina::Mina(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Mina::~Mina() {
    cout << "Destrui " << getNometerritorio() << endl;
}

Duna::Duna(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;

}

Duna::~Duna() {
    cout << "Destrui " << getNometerritorio() << endl;
}

Castelo::Castelo(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
}

Castelo::~Castelo() {
    cout << "Destrui " << getNometerritorio() << endl;
}
