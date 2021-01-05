#include <iostream>
#include "Tecnologias.h"

using namespace std;

Tecnologias::Tecnologias(string nome,int preco){
	this->nome = nome;
	this->preco = preco;
}

string Tecnologias::getCompradaString() const { return comprada ? "Ja tens" : "Nao tens"; }

string Tecnologias::getAsString() const {
	ostringstream oss;

	oss << nome << "\t" << preco << "\t" << getCompradaString() << endl;
	return oss.str();
}

bool Tecnologias::getComprada() const {
	return comprada;
}

string Tecnologias::getNome() const {
	return nome;
}

int Tecnologias::getPreco() const {
	return preco;
}



void Tecnologias::setComprada(){
	comprada = true;
}