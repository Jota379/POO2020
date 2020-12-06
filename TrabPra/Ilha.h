#pragma once
#include <iostream>
#include <string>
#include "Mundo_Territorio.h"

using namespace std;

class Ilha : public Mundo_Territorios { //classe do tipo Ilha

};

class Refugio_Pirata : public Ilha { // Define um tipo de Ilha

public:
    Refugio_Pirata(string nome = "RefugioPirata", int resistencia = 9, int produtos = 0, int ouro = 1, int pontos_vitoria = 2);
    ~Refugio_Pirata();
};

class Pescaria : public Ilha { // Define um tipo de Ilha   
public:
    Pescaria(string nome = "Pescaria", int resistencia = 9, int produtos = 2, int ouro = 0, int pontos_vitoria = 2);
    ~Pescaria();

};

