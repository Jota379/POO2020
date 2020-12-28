#pragma once
#include <iostream>
#include "Mundo_Territorio.h"

using namespace std;

class Tecnologias {
private:
	bool drones_Militares = false;
	bool missies_Teleguiados = false;
	bool defesas_Territoriais = false;
	bool bolsa_Valores = false;
	bool banco_Central = false;


public:
	//get
	bool getDronesMilitares()const;
	bool getMisseisTeleguiados()const;
	bool getDefesasTerritoriais()const;
	bool getBolsaValores()const;
	bool getBancoCentral()const;

	//set
	bool setDronesMilitares();
	bool setMisseisTeleguiados();
	bool setDefesasTerritoriais();
	bool setBolsaValores();
	bool setBancoCentral();
};