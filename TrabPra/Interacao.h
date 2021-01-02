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
	int sorte = 0;
	int sorteAdversaria = 0;

public:
	int comandline();
	void mostra_menu()const;
	void FaseCP();
	void FaseRP();
	void FaseCUMT();
	void FaseFE();
	void escrita_menus();
	void conquistar();
	void ListarTudo();
	void ListarTerr(string nomeaux);
	void ListarConquistados();
	void comeca_jogo();
	void carregar(string nomefich);
	void mostra_comandos_CP();
	void mostra_comandos_RP();
	void mostra_comandos_CUMT();
	void mostra_comandos_FE();
	Interacao();

};