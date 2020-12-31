#pragma once
#include <iostream>
#include <string>
#include "Mundo_Territorio.h"
using namespace std;


class Interacao {
private:


public:
	int comandline();
	void mostra_menu()const;
	void escrita_menus(vector<Mundo_Territorios*> jogo);

};