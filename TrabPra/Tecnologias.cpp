#include <iostream>
#include "Tecnologias.h"

using namespace std;

Tecnologias::Tecnologias(string nome,int preco,string cmd){
	this->nome = nome;
	this->preco = preco;
	this->comando = cmd;
}

string Tecnologias::getCompradaString() const { return comprada ? "Ja tens" : "Nao tens"; }

string Tecnologias::getAsString() const {
	ostringstream oss;

	oss << nome << "\t" << preco << "\t" << getCompradaString() << "\t" << comando << endl;
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