#pragma once
#include <iostream>
#include <string>
#include "Mundo_Territorio.h"
using namespace std;

class Continentes : public Mundo_Territorios {};


class Planicie : public Continentes
{
public:
    static int idPlanicie;
    Planicie(string nome = "Planicie", int resistencia = 5, int produtos = 1, int ouro = 1, int pontos_vitoria = 1);
    ~Planicie();
    int recolheOuro(int ano, int turno)override;
    int recolheProd(int ano, int turno)override;

};

class Montanha : public Continentes
{
public:
    static int idMontanha;
    int turnoConqDecre = 2;
    Montanha(string nome = "Montanha", int resistencia = 6, int produtos = 1, int ouro = 0, int pontos_vitoria = 1);
    ~Montanha();
    int setConquista(int forca,int sorte,bool tec,int nterr)override;
    void setConquistaADM(bool estado)override;
    int recolheOuro(int ano, int turno)override;
    int recolheProd(int ano, int turno)override;

};

class Fortaleza : public Continentes
{
public:
    static int idFortaleza;
    Fortaleza(string nome = "Fortaleza", int resistencia = 8, int produtos = 0, int ouro = 0, int pontos_vitoria = 1);
    ~Fortaleza();
    int recolheOuro(int ano, int turno)override;
    int recolheProd(int ano, int turno)override;

};

class Mina : public Continentes
{
public:
    static int idMina;
    Mina(string nome = "Mina", int resistencia = 5, int produtos = 0, int ouro = 1, int pontos_vitoria = 1);
    ~Mina();
    int recolheOuro(int ano, int turno)override;
    int recolheProd(int ano, int turno)override;
};

class Duna : public Continentes
{
public:
    static int idDuna;
    Duna(string nome = "Duna", int resistencia = 4, int produtos = 1, int ouro = 0, int pontos_vitoria = 1);
    ~Duna();
    int recolheOuro(int ano, int turno)override;
    int recolheProd(int ano, int turno)override;

};

class Castelo : public Continentes
{
public:
    static int idCastelo;
    Castelo(string nome = "Castelo", int resistencia = 7, int produtos = 3, int ouro = 1, int pontos_vitoria = 1);
    ~Castelo();
    int recolheOuro(int ano, int turno)override;
    int recolheProd(int ano, int turno)override;
};

