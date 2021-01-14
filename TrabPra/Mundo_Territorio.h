#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


class Mundo_Territorios { //classe gen�rico que cont�m todos os territ�rios que n�o foram conquistados
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

    //fun��es set 
    void setNomeTerritorio(string nome_territorio);
    virtual int setConquista(int forca,int sorte,bool tec);
    void setConquistaADM(bool estado);

    //fun��es get
    string getNometerritorio() const;
    int getResistencia() const;
    int getProdutos() const;
    int getOuro() const;
    int getPontosVitoria() const;
    bool getConquista() const;
    string getAsString() const;
    string getConquistaString() const;
    ~Mundo_Territorios();

};

class Territorio_Inicial : public Mundo_Territorios { // Define um tipo de territ�rio
public:
    Territorio_Inicial(string nome = "TerritorioInicial", int resistencia = 9, int produtos = 1, int ouro = 1, int pontos_vitoria = 0, bool conquistado = true); //construtor com parametros

    ~Territorio_Inicial() { // destrutor
    };



};


