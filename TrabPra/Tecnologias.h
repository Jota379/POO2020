#pragma once
#include <iostream>
#include "Mundo_Territorio.h"

using namespace std;

class Tecnologias {
private:
	//bool drones_Militares = false;
	//bool missies_Teleguiados = false;
	//bool defesas_Territoriais = false;
	//bool bolsa_Valores = false;
	//bool banco_Central = false;
	string nome,comando;
	int preco;
	bool comprada = false;


public:

	Tecnologias(string nome, int preco,string cmd);
	//get
	bool getComprada()const;
	string getNome()const;
	int getPreco()const;
	string getAsString()const;
	string getCompradaString() const;

	//set
	void setComprada();
};