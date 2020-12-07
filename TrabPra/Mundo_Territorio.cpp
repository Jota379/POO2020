#include "Mundo_Territorio.h"

#include <iostream>
#include "Mundo_Territorio.h"

using namespace std;





//string Mundo_Territorios::setNomeTerritorio(){};


Mundo_Territorios::Mundo_Territorios()
{
}

void Mundo_Territorios::setNomeTerritorio(string nome_territorio)
{
    this->nome_territorio=nome_territorio;
}

void Mundo_Territorios::setConquista()
{
    conquistado = true;
}

string Mundo_Territorios::getNometerritorio() const
{
    ostringstream os;

    os << "Territorio : " << nome_territorio << endl;

    return nome_territorio;
}

Territorio_Inicial::Territorio_Inicial(string nome, int resistencia, int produtos, int ouro, int pontos_vitoria, bool conquistado) {
    this->resistencia = resistencia;
    this->produtos = produtos;
    this->ouro = ouro;
    this->pontos_vitoria = pontos_vitoria;
    this->nome_territorio = nome;
    this->conquistado = conquistado;
}


int Mundo_Territorios::getResistencia() const { return resistencia; }
int Mundo_Territorios::getProdutos() const { return produtos; }
int Mundo_Territorios::getOuro() const { return ouro; }
int Mundo_Territorios::getPontosVitoria() const { return pontos_vitoria; }
bool Mundo_Territorios::getConquista() const { return conquistado; }
string Mundo_Territorios::getConquistaString() const { return conquistado ? "true" : "false"; }

string Mundo_Territorios::getAsString() const {
    ostringstream oss;

    oss << nome_territorio << "\t" << resistencia << "\t" << produtos << "\t" << ouro << "\t" << pontos_vitoria << "\t" << getConquistaString() << endl;
    return oss.str();
}

Mundo_Territorios::~Mundo_Territorios()
{
}
