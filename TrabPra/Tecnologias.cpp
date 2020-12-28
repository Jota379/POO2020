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
	return drones_Militares = true;
}

bool Tecnologias::setMisseisTeleguiados(){
	return missies_Teleguiados = true;
}

bool Tecnologias::setDefesasTerritoriais(){
	return defesas_Territoriais = true;
}

bool Tecnologias::setBolsaValores(){
	return bolsa_Valores = true;
}

bool Tecnologias::setBancoCentral(){
	return banco_Central = true;
}