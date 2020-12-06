#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Mundo_Territorio.h"
#include "Continentes.h"
#include "Ilha.h"

using namespace std;

vector<Mundo_Territorios*> carregar(string nomefich,int& idPlanicie,int&idMontanha,int&idFortaleza,int&idMina,int&idDuna,int&idCastelo,int&idRefugioPirata,int&idPescaria) {
    int i, f, maxr = 1;

    string cmd;

    ifstream myFile(nomefich);


    vector<Mundo_Territorios*> jogo;

    string str, copia, nome_territorio, resistencia, produtos, ouro, pontos_vitoria, tipoTerritorio, rep, lixo;

    cout << "Lista de comandos:\n\tcarrega <nome_ficheiro>\n\tcria <Tipo_de_Territorio> <numero_de_vezes>\n\tlista\n\tsair\n\n";

    while (getline(myFile, cmd))
    {
        cout << cmd << endl;
        istringstream bufi(cmd);
        ostringstream oss;
        ostringstream Aindex;
        string nome;

        while (bufi >> str)
        {
            copia = str;
                if (copia == "cria")
                {
                    bufi >> tipoTerritorio;
                    /*
                    if (tipoTerritorio == "territorio")
                    {
                       if (bufi >> rep) {
                            try
                            {
                                    maxr = stoi(rep, nullptr, 10);

                                    while (maxr >= 1) {
                                        push//criat();

                                        cout << "executei o cria territorio \n";
                                        maxr--;
                                    }
                                    maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    */
                    if (tipoTerritorio == "RefugioPirata")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "RefugioPirata" << idRefugioPirata;
                                    nome = passanome.str();
                                    idRefugioPirata++;
                                    jogo.push_back(new Refugio_Pirata(nome));
                                    cout << "executei o cria ilha \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Pescaria")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Pescaria" << idPescaria;
                                    nome = passanome.str();
                                    idPescaria++;
                                    jogo.push_back(new Pescaria(nome));
                                    cout << "executei o cria ilha \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Planicie")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Planicie" << idPlanicie;
                                    nome = passanome.str();
                                    idPlanicie++;
                                    jogo.push_back(new Planicie(nome));
                                    cout << "executei o cria planicie \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Castelo")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Castelo" << idCastelo;
                                    nome = passanome.str();
                                    idCastelo++;
                                    jogo.push_back(new Castelo(nome));
                                    cout << "executei o cria castelo \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Fortaleza")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Fortaleza" << idFortaleza;
                                    nome = passanome.str();
                                    idFortaleza++;
                                    jogo.push_back(new Fortaleza(nome));
                                    cout << "executei o cria fortaleza \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Duna")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Duna" << idDuna;
                                    nome = passanome.str();
                                    idDuna++;
                                    jogo.push_back(new Duna(nome));
                                    cout << "executei o cria duna \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Mina")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Mina" << idMina;
                                    nome = passanome.str();
                                    idMina++;
                                    jogo.push_back(new Mina(nome));
                                    cout << "executei o cria mina \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Montanha")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Montanha" << idMontanha;
                                    nome = passanome.str();
                                    idMontanha++;
                                    jogo.push_back(new Montanha(nome));
                                    cout << "executei o cria montanha \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                }
                else
                    // <NomeFicheiro> vai buscar os carros ao ficheiro("capacidadeInicial capacidadeMaxima marca modelo")
                    if (copia == "lista")
                    {
                        cout << "executei o Lista \n";
                        for (unsigned int i = 0; i < jogo.size(); i++)
                            oss << jogo[i]->getAsString();
                        cout << oss.str();
                        //lista();
                    }
                    else
                        //|comando para entrar no modo 2| cmdCamp(bufi,str);
                        if (copia == "sair")
                        {
                            return jogo;
                        }
                        else
                        {
                            cout << "\tO comando não existe,por favor verifique a integridade do ficheiro ou cite um ficheiro valido" << endl;
                            exit(1);
                            while (bufi >> lixo)
                            {
                            }
                        }
        }
    }
    return jogo;
}


int comandline() {
    int i, f, maxr = 1;

    string cmd;

    vector<Mundo_Territorios*> jogo;

    string str, copia, nome_territorio, resistencia, produtos, ouro, pontos_vitoria, nomefich, tipoTerritorio, rep, lixo;

    cout << "Lista de comandos:\n\tcarrega <nome_ficheiro>\n\tcria <Tipo_de_Territorio> <numero_de_vezes>\n\tlista\n\tsair\n\n";

    for (;;)
    {

        cout << "comando> ";
        fflush(stdout);
        getline(cin, cmd);

        istringstream bufi(cmd);
        ostringstream oss;
        ostringstream Aindex;
        static int idPlanicie = 1, idMontanha = 1, idFortaleza = 1, idMina = 1, idDuna = 1, idCastelo = 1, idRefugioPirata = 1, idPescaria = 1;
        string nome;

        while (bufi >> str)
        {
            copia = str;
            if (copia == "carrega")
            {
                bufi >> nomefich;
                cout << "executei o carrega " << nomefich << endl;
                jogo = carregar(nomefich,idPlanicie, idMontanha, idFortaleza, idMina, idDuna, idCastelo, idRefugioPirata, idPescaria);
            }
            else
                // <NomeFicheiro> vai buscar pilotos ao ficheiro ("tipo nome")
                if (copia == "cria")
                {
                    bufi >> tipoTerritorio;
                    /*
                    if (tipoTerritorio == "territorio")
                    {
                       if (bufi >> rep) {
                            try
                            {
                                    maxr = stoi(rep, nullptr, 10);

                                    while (maxr >= 1) {
                                        push//criat();

                                        cout << "executei o cria territorio \n";
                                        maxr--;
                                    }
                                    maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    */
                    if (tipoTerritorio == "RefugioPirata")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "RefugioPirata" << idRefugioPirata;
                                    nome = passanome.str();
                                    idRefugioPirata++;
                                    jogo.push_back(new Refugio_Pirata(nome));
                                    cout << "executei o cria ilha \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Pescaria")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Pescaria" << idPescaria;
                                    nome = passanome.str();
                                    idPescaria++;
                                    jogo.push_back(new Pescaria(nome));
                                    cout << "executei o cria ilha \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Planicie")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Planicie" << idPlanicie;
                                    nome = passanome.str();
                                    idPlanicie++;
                                    jogo.push_back(new Planicie(nome));
                                    cout << "executei o cria planicie \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Castelo")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Castelo" << idCastelo;
                                    nome = passanome.str();
                                    idCastelo++;
                                    jogo.push_back(new Castelo(nome));
                                    cout << "executei o cria castelo \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Fortaleza")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Fortaleza" << idFortaleza;
                                    nome = passanome.str();
                                    idFortaleza++;
                                    jogo.push_back(new Fortaleza(nome));
                                    cout << "executei o cria fortaleza \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Duna")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Duna" << idDuna;
                                    nome = passanome.str();
                                    idDuna++;
                                    jogo.push_back(new Duna(nome));
                                    cout << "executei o cria duna \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Mina")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Mina" << idMina;
                                    nome = passanome.str();
                                    idMina++;
                                    jogo.push_back(new Mina(nome));
                                    cout << "executei o cria mina \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                    if (tipoTerritorio == "Montanha")
                    {
                        if (bufi >> rep) {
                            try
                            {
                                maxr = stoi(rep, nullptr, 10);

                                while (maxr >= 1) {
                                    ostringstream passanome;
                                    passanome << "Montanha" << idMontanha;
                                    nome = passanome.str();
                                    idMontanha++;
                                    jogo.push_back(new Montanha(nome));
                                    cout << "executei o cria montanha \n";
                                    maxr--;
                                }
                                maxr = 1;
                            }
                            catch (const invalid_argument)
                            {
                                cout << "utilise um inteiro \n";
                                maxr = 1;
                            }
                        }
                    }
                }
                else
                    // <NomeFicheiro> vai buscar os carros ao ficheiro("capacidadeInicial capacidadeMaxima marca modelo")
                    if (copia == "lista")
                    {
                        cout << "executei o Lista \n";
                        for (unsigned int i = 0; i < jogo.size(); i++)
                            oss << jogo[i]->getAsString();
                        cout << oss.str();
                        //lista();
                    }
                    else
                        //|comando para entrar no modo 2| cmdCamp(bufi,str);
                        if (copia == "sair")
                        {
                            return 0;
                        }
                        else
                        {
                            cout << "\tO comando não existe" << endl;
                            while (bufi >> lixo)
                            {
                            }
                        }
        }
    }
    return 0;
}


int main() {
    comandline();
}