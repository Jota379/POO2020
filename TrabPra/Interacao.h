#pragma once
#include <iostream>
#include <string>
#include "Mundo_Territorio.h"
#include "Tecnologias.h"
using namespace std;


class Interacao {
private:
	vector<Mundo_Territorios*> jogo;
	int força_militar;
	int força_militar_max = 3;
	int turno = 1, ano = 1;
	int ouroTotal = 0;
	int produtosTotal = 0;
	int sorte = 0;
	int sorteAdversaria = 0;
	int produtosMax = 3;
	int ouroMax = 3;
	bool conquistaIlhas = false;
	bool fazerTrocas = false;
	int resistenciaBonus = 0;
	int nTerrConq = 1;
	int idEventoPretendido = 4;
	vector<Tecnologias*> tecs;
	vector<int> ultimoTerr;
	const vector<string> eventos {"Sem Evento","Recurso Abandonado","Invasao","Alianca Diplomatica" };


public:
	int comandline();
	void FaseCP();
	void FaseRP();
	void FaseCUMT();
	void FaseFE();
	void escrita_menus();
	//void conquistar();
	void ListarTudo();
	void ListarTerr(string nomeaux);
	void ListarConquistados();
	void comeca_jogo();
	void carregar(string nomefich);
	void mostra_comandos_CP();
	void mostra_comandos_RP();
	void mostra_comandos_CUMT();
	void mostra_comandos_FE();
	void status();
	void iniciaTecs();
	void listaTecs();
	void aplicaEvento();
	void recolheTudo();
	int buscaConq();
	int buscaConqPont();
	Interacao();
	~Interacao();
	
	

};