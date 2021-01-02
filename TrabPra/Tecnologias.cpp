#include <iostream>
#include "Tecnologias.h"

using namespace std;

bool Tecnologias::getDronesMilitares() const {
	return drones_Militares;
}

bool Tecnologias::getMisseisTeleguiados() const {
	return missies_Teleguiados;
}

bool Tecnologias::getDefesasTerritoriais() const {
	return defesas_Territoriais;
}

bool Tecnologias::getBolsaValores() const {
	return bolsa_Valores;
}

bool Tecnologias::getBancoCentral() const {
	return banco_Central;
}


bool Tecnologias::setDronesMilitares(){
	drones_Militares = true;
	return drones_Militares;
}

bool Tecnologias::setMisseisTeleguiados(){
	missies_Teleguiados = true;
	return missies_Teleguiados;
}

bool Tecnologias::setDefesasTerritoriais(){
	defesas_Territoriais = true;
	return defesas_Territoriais;
}

bool Tecnologias::setBolsaValores(){
	bolsa_Valores = true;
	return bolsa_Valores;
}

bool Tecnologias::setBancoCentral(){
	banco_Central = true;
	return banco_Central;
}