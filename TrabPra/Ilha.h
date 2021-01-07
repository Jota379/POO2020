#pragma once
#include <iostream>
#include <string>
#include "Mundo_Territorio.h"

using namespace std;

class Ilha : public Mundo_Territorios { //classe do tipo Ilha

public:
    int setConquista(int forca, int sorte, bool tec) override;
};

class Refugio_Pirata : public Ilha { // Define um tipo de Ilha

public:
    static int idRefugio_Pirata;
    Refugio_Pirata(string nome = "RefugioPirata", int resistencia = 9, int produtos = 0, int ouro = 1, int pontos_vitoria = 2);
    ~Refugio_Pirata();
    int setConquista(int forca, int sorte, bool tec);
};

class Pescaria : public Ilha { // Define um tipo de Ilha   
public:
    static int idPescaria;
    Pescaria(string nome = "Pescaria", int resistencia = 9, int produtos = 2, int ouro = 0, int pontos_vitoria = 2);
    ~Pescaria();
    int setConquista(int forca, int sorte, bool tec);
};

