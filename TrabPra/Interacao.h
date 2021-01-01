#pragma once
#include <iostream>
#include <string>
#include "Mundo_Territorio.h"
using namespace std;


class Interacao {
private:
	vector<Mundo_Territorios*> jogo;
	int força_militar;
	int turno = 1, ano = 1;
	int ouroTotal = 0;
	int ProdutosTotal = 0;

public:
	int comandline();
	void mostra_menu()const;
	void escrita_menus();
	void conquistar_passar();
	void obter_força_militar();
	void obter_tecnologias();
	void comeca_jogo();
	void carregar(string nomefich);
	Interacao();

};