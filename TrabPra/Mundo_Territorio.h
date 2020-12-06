#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


class Mundo_Territorios { //classe genérico que contém todos os territórios que não foram conquistados
protected:
    string nome_territorio;
    int resistencia;
    int produtos;
    int ouro;
    int pontos_vitoria;
    bool conquistado = false;
    static int numberTerrGeral;
    // numero de cada territorio
    //vector<Mundo_Territorios> territorios; //vector que guarda todos os territorios
public:

    Mundo_Territorios();

    //funções set 
    void setNomeTerritorio(string nome_territorio);

    //funções get
    string getNometerritorio() const;
    int getResistencia() const;
    int getProdutos() const;
    int getOuro() const;
    int getPontosVitoria() const;
    bool getConquista() const;
    string getAsString() const;
    ~Mundo_Territorios();

};

class Territorio_Inicial : public Mundo_Territorios { // Define um tipo de território
public:
    Territorio_Inicial(string nome = "Territorio Inicial", int resistencia = 9, int produtos = 1, int ouro = 1, int pontos_vitoria = 0); //construtor com parametros

    ~Territorio_Inicial() { // destrutor
    };



};


