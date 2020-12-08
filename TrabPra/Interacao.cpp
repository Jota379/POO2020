#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include<cstdlib>
#include<ctime>
#include "Mundo_Territorio.h"
#include "Continentes.h"
#include "Ilha.h"

using namespace std;

void mostra_menu() {
    cout << "1. Conquistar / Passar" << endl;
    cout << "2. Recolha de Produtos ou ouro" << endl;
    cout << "3. Compra de unidades militares e de tecnologia" << endl;
    cout << "4. Ocorrência de um evento" << endl;
    cout << "5. Lista" << endl;
    cout << "0. Sair" << endl;
    return;
}

vector<Mundo_Territorios*> conquistar_passar(vector<Mundo_Territorios*> jogo,int& sorte,int& força_militar){
    system("cls");
    int esc;
    ostringstream oss;
    string terrPretendido;
    bool turno_terminado=false;
    srand(time(NULL));
    

    while (!turno_terminado) {
        bool existe = false; // verifica se o territorio existe
        cout << "FORCA MILITAR:" << força_militar << "\tULTIMA SORTE: " << sorte << endl;
        cout << "1: Listar" << endl;
        cout << "2: Conquistar" << endl;
        cout << "3: Passar Turno" << endl;
        cin >> esc;
        switch (esc) {
        case 1:
            cout << "NOME\tRESISTENCIA\tPRODUTOS\tOURO\tPONTOSDEVITORIA\tCONQUISTADO" << endl;
            for (unsigned int i = 0; i < jogo.size(); i++) // listar todos os territórios
                oss << jogo[i]->getAsString();
            cout << oss.str();
            break;
        case 2:
            cout << "Escreva o nome do territorio Pretendido ->";
            cin >> terrPretendido;
            for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios
                if (terrPretendido == jogo[i]->getNometerritorio()) {
                    sorte = rand() % 6 + 1;
                    cout << "Fator sorte: " << sorte << endl; // gerar valor aleatório entre 1 e 6 inclusive
                    existe = true;
                    if (jogo[i]->getConquista() == false) {
                        sorte = rand() % 6 + 1;
                        cout << "Fator sorte: " << sorte << endl; // gerar valor aleatório entre 1 e 6 inclusive
                    }
                    if (jogo[i]->getConquista() == true) {
                        cout << "Territorio já conquistado" << endl;
                        break;
                    }
                    else if ((sorte+força_militar)>=jogo[i]->getResistencia())
                            {
                        jogo[i]->setConquista();
                        cout << "Territorio " << jogo[i]->getNometerritorio() << " Conquistado" << endl;
                        turno_terminado = true;
                        
                            }
                            else
                            {
                                cout << "Falhou a Conquista do Territorio " << jogo[i]->getNometerritorio() << endl;
                                if(força_militar>0)
                                    força_militar--;
                                turno_terminado = true;
                             }
                }
            }
            if (!existe)
                {
                cout << "Territorio Não Exite" << endl;
                }
            
            break;
        case 3:

            turno_terminado = true;
            break;
        }
    }
    return jogo;
}

void escrita_menus(vector<Mundo_Territorios*> jogo) {
    system("cls");

    int escolha;
    int turno = 1, ano = 1;
    ostringstream oss;

    srand(time(NULL));
    int força_militar = rand() % 4;
    int sorte = 0;

    while(1) {

        if(turno%6==0){
            ano++;
        }
        cout << "ANO: " << ano << endl;
        cout << "TURNO: " << turno << endl;
        cout << "FORÇA MILITAR: " << força_militar << endl;
        cout << "ULTIMA SORTE: " << sorte << endl;

        mostra_menu();
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "O jogador pode escolher uma das seguintes opções:" << endl;
            jogo = conquistar_passar(jogo,sorte,força_militar);
            turno++;
            break;
        case 2:
            cout << "Recolhe os produtos dos territorios conquistados" << endl;
            break;
        case 3:
            cout << "Aumentar as forças militares" << endl;
            break;
        case 4:
            cout << "Ah um evento" << endl;
            break;
        case 5:
            for (unsigned int i = 0; i < jogo.size(); i++) // listar todos 
                oss << jogo[i]->getAsString();
            cout << oss.str();
            break;
        case 0:
            exit(0);
        }
    }
}

 void comeca_jogo(vector<Mundo_Territorios*> jogo) {
    cout << "Entrou no jogo" << endl;
    escrita_menus(jogo);
}

vector<Mundo_Territorios*> carregar(string nomefich,int& idPlanicie,int&idMontanha,int&idFortaleza,int&idMina,int&idDuna,int&idCastelo,int&idRefugioPirata,int&idPescaria) {
    int i, f, maxr = 1;

    string cmd;

    ifstream myFile(nomefich);

    vector<Mundo_Territorios*> jogo;

    string str, copia, nome_territorio, resistencia, produtos, ouro, pontos_vitoria, tipoTerritorio, rep, lixo;
    
    if (!myFile.is_open()) {
        cout << "Ficheiro nao existe, nada foi carregado" << endl;
        return jogo;
    }


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
                    if (copia == "lista")
                    {
                        cout << "executei o Lista \n";
                        for (unsigned int i = 0; i < jogo.size(); i++)
                            oss << jogo[i]->getAsString();
                        cout << oss.str();
                    }
                    else
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

    cout << "Lista de comandos:\n\tcarrega <nome_ficheiro>\n\tcria <Tipo_de_Territorio> <numero_de_vezes>\n\tlista\n\tavanca\n\tsair\n\n";

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
                if (copia == "cria")
                {
                    bufi >> tipoTerritorio;

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

                    if (copia == "lista")
                    {
                        cout << "executei o Lista \n";
                        for (unsigned int i = 0; i < jogo.size(); i++)
                            oss << jogo[i]->getAsString();
                        cout << oss.str();

                    }
                    else
                        if (copia == "avanca") {
                            jogo.push_back(new Territorio_Inicial());
                            comeca_jogo(jogo);
                        }
                        else

                            if (copia == "sair")
                            {
                                return 0;
                            }
                                else
                                    cout << "\tO comando nao existe" << endl;
                                    while (bufi >> lixo)
                                    {
                                    }
                                
        }
    }
    return 0;
}


int main() {
    comandline();
}
