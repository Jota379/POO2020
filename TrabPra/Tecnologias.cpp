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
}

bool Tecnologias::setMisseisTeleguiados(){
	missies_Teleguiados = true;
}

bool Tecnologias::setDefesasTerritoriais(){
	defesas_Territoriais = true;
}

bool Tecnologias::setBolsaValores(){
	bolsa_Valores = true;
}

bool Tecnologias::setBancoCentral(){
	banco_Central = true;
}