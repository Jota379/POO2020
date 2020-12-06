#pragma once
#include <iostream>
#include <string>
#include "Mundo_Territorio.h"
using namespace std;

class Continentes : public Mundo_Territorios {};


class Planicie : public Continentes
{
public:
    Planicie(string nome = "Planicie", int resistencia = 5, int produtos = 1, int ouro = 1, int pontos_vitoria = 1);
    ~Planicie();

};

class Montanha : public Continentes
{
public:
    Montanha(string nome = "Montanha", int resistencia = 6, int produtos = 1, int ouro = 0, int pontos_vitoria = 1);
    ~Montanha();

};

class Fortaleza : public Continentes
{
public:
    Fortaleza(string nome = "Fortaleza", int resistencia = 8, int produtos = 0, int ouro = 0, int pontos_vitoria = 1);
    ~Fortaleza();

};

class Mina : public Continentes
{
public:
    Mina(string nome = "Mina", int resistencia = 5, int produtos = 0, int ouro = 1, int pontos_vitoria = 1);
    ~Mina();
};

class Duna : public Continentes
{
private:
    static int idDuna;
public:
    Duna(string nome = "Duna", int resistencia = 4, int produtos = 1, int ouro = 0, int pontos_vitoria = 1);
    ~Duna();

};

class Castelo : public Continentes
{
public:
    Castelo(string nome = "Castelo", int resistencia = 7, int produtos = 3, int ouro = 1, int pontos_vitoria = 1);
    ~Castelo();
};

