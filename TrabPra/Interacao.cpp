#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Interacao.h"
#include "Mundo_Territorio.h"
#include "Continentes.h"
#include "Ilha.h"

using namespace std;

Interacao::Interacao(){
    força_militar = rand() % 4;
}

void Interacao::mostra_menu()const{
    cout << "1. Conquistar / Passar" << endl;
    cout << "2. Recolha de Produtos ou ouro" << endl;
    cout << "3. Compra de unidades militares e de tecnologia" << endl;
    cout << "4. Ocorrência de um evento" << endl;
    cout << "5. Lista" << endl;
    cout << "0. Sair" << endl;
    return;
}


void Interacao::mostra_comandos_CP(){

    cout << "=====Fase Conquistar/Passar====="
        << "Comandos:" << endl
        << "\tconquista <nomeTerritorio> ;" << endl
        << "\tpassa ; usa este comando para não conquistar nenhum territorio" << endl
        << "\tlista < | nometerritorio | meus> ; caso não meta nome de territorio lista tudo, caso utilize o 'meus' lista os territorios conquistados" << endl
        << "\tavanca ; passa à proxima fase" << endl
        << "\tgrava <nome>" << endl
        << "\tativa <nome>" << endl
        << "\tapaga <nome>" << endl
        << "======CHEATS/DEBUG=====" << endl
        << "\ttoma <qual> <nome>" << endl
        << "\tmodifica <ouro | prod> N" << endl
        << "\tfevento <nome-evento>" << endl;
}

void Interacao::mostra_comandos_RP(){
    cout << "=====Fase Recolha de Produtos e Ouro=====" << endl
        << "Comandos:" << endl
        << "\tmaisprod ;" << endl
        << "\tmais ouro;" << endl
        << "\tlista < | nometerritorio | meus> ; caso não meta nome de territorio lista tudo, caso utilize o 'meus' lista os territorios conquistados" << endl
        << "\tavanca ; passa à proxima fase" << endl
        << "\tgrava <nome>" << endl
        << "\tativa <nome>" << endl
        << "\tapaga <nome>" << endl
        << "======CHEATS/DEBUG=====" << endl
        << "\ttoma <qual> <nome>" << endl
        << "\tmodifica <ouro | prod> N" << endl
        << "\tfevento <nome-evento>" << endl;
}

void Interacao::mostra_comandos_CUMT(){
    cout << "=====Fase Forca Militar | Tecnologias====="
        << "Comandos:" << endl
        << "\tadquire <tipo>;" << endl
        << "\tmaismilitar;" << endl
        << "\tlista < | nometerritorio | meus> ; caso não meta nome de territorio lista tudo, caso utilize o 'meus' lista os territorios conquistados" << endl
        << "\tavanca ; passa à proxima fase" << endl
        << "\tgrava <nome>" << endl
        << "\tativa <nome>" << endl
        << "\tapaga <nome>" << endl
        << "======CHEATS/DEBUG=====" << endl
        << "\ttoma <qual> <nome>" << endl
        << "\tmodifica <ouro | prod> N" << endl
        << "\tfevento <nome-evento>" << endl;
}

void Interacao::mostra_comandos_FE() {

    cout << "=====Fase Eventos====="
        << "Comandos:" << endl
        << "\tlista < | nometerritorio | meus> ; caso nao meta nome de territorio lista tudo, caso utilize o 'meus' lista os territorios conquistados" << endl
        << "\tavanca ; passa à proxima fase" << endl
        << "\tgrava <nome>" << endl
        << "\tativa <nome>" << endl
        << "\tapaga <nome>" << endl
        << "======CHEATS/DEBUG=====" << endl
        << "\ttoma <qual> <nome>" << endl
        << "\tmodifica <ouro | prod> N" << endl
        << "\tfevento <nome-evento>" << endl;
}

void Interacao::conquistar(){
    system("cls");
    int esc;
    ostringstream oss;
    string terrPretendido;
    srand((unsigned int)time(NULL));
    bool existe = false; // verifica se o territorio existe


    cout << "FORCA MILITAR:" << força_militar << "\tULTIMA SORTE: " << sorte << endl;
    cout << "1: Listar" << endl;
    cout << "2: Conquistar" << endl;
    cout << "3: Passar Turno" << endl;
    cin >> esc;
    switch (esc) {
    case 1:
        cout << "NOME\tRESISTENCIA\tPRODUTOS\tOURO\tPONTOS VITORIA\tCONQUISTADO" << endl;
        for (unsigned int i = 0; i < jogo.size(); i++) // listar todos os territórios
            oss << jogo[i]->getAsString();
        cout << oss.str();
        break;
    case 2:
        cout << "Escreva o nome do territorio Pretendido ->";
        cin >> terrPretendido;
        for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios
            if (terrPretendido == jogo[i]->getNometerritorio()) {
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
                        
                }
                else
                {
                    cout << "Falhou a Conquista do Territorio " << jogo[i]->getNometerritorio() << endl;
                    if(força_militar>0)
                        força_militar--;
                }
            }
        }
        if (!existe)
            {
            cout << "Territorio Não Exite" << endl;
            }
            
        break;
    case 3:
        break;
    }
}

void Interacao::ListarTudo() {
    ostringstream oss;
    for (unsigned int i = 0; i < jogo.size(); i++) // listar todos os territórios
        oss << jogo[i]->getAsString();
    cout << oss.str();

}

void Interacao::ListarTerr(string nomeaux) {
    ostringstream oss;
    for (unsigned int i = 0; i < jogo.size(); i++) {// listar todos os territórios com um certo nome
        if(nomeaux == jogo[i]->getNometerritorio())
            oss << jogo[i]->getAsString();
    }
    cout << oss.str();
}

void Interacao::ListarConquistados() {
    ostringstream oss;
    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios que foram conquistados
        if (jogo[i]->getConquista() == true)
            oss << jogo[i]->getAsString();
    }
    cout << oss.str();
}


void Interacao::FaseCP(){

    string copia, str, cmd,nomeTerritorio,nomePesquisa;
    bool verificaEscConqPass = false;
    mostra_comandos_CP();
    for (;;)
    {

        cout << "> ";
        fflush(stdout);
        getline(cin, cmd);

        istringstream bufi(cmd);
        ostringstream oss;

        while (bufi >> str)
        {
            copia = str;
            if (copia == "conquista") {
                bool existe = false; // verifica se o territorio existe
                if (!verificaEscConqPass){
                    bufi >> nomeTerritorio;
                    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios
                        if (nomeTerritorio == jogo[i]->getNometerritorio()) {
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
                        
                            }
                            else
                            {
                                cout << "Falhou a Conquista do Territorio " << jogo[i]->getNometerritorio() << endl;
                                if(força_militar>0)
                                    força_militar--;
                            }
                        }
                    }
                    if (!existe)
                        {
                        cout << "Territorio Não Exite" << endl;
                        }
                    verificaEscConqPass = true;

                }
                else if(verificaEscConqPass){
                    cout << "\n Ja efetuou a sua acao neste turno, utilize o comando 'avanca' para passar o turno" << endl;
                }
            }
            if (copia == "passa") {
                if (!verificaEscConqPass) {
                    cout << "\nDecidiu não conquistar nada neste turno" << endl;
                    verificaEscConqPass = true;
                }
                else if(verificaEscConqPass){
                    cout << "\n Ja efetuou a sua acao neste turno, utilize o comando 'avanca' para passar o turno" << endl;
                }
            }
            if (copia == "lista") {
                nomePesquisa = "";
                if (!(bufi >> nomePesquisa)) {
                    ListarTudo();
                }
                else if (nomePesquisa == "meus") {
                    ListarConquistados();
                }
                else if (nomePesquisa != ""){
                    ListarTerr(nomePesquisa);
                }
            }
            if (copia == "avanca")
            {
                return;
            }
            if (copia == "grava")
            {

            }
            if (copia == "ativa")
            {

            }
            if (copia == "apaga")
            {

            }
            if (copia == "toma")
            {

            }
            if (copia == "modifica")
            {

            }
            if (copia == "fevento")
            {

            }

        }
    }
}

void Interacao::FaseRP(){

}

void Interacao::FaseCUMT(){

}

void Interacao::FaseFE(){

}


void Interacao::escrita_menus() {
    system("cls");

    srand((unsigned int)time(NULL));

    while(1) {
        bool verificaTrocas = false;
        bool verificaCompras = false;
        if(turno%6==0){
            ano++;
        }
        cout << "ANO: " << ano << endl;
        cout << "TURNO: " << turno << endl;
        cout << "FORCA MILITAR: " << força_militar << endl;
        cout << "ULTIMA SORTE: " << sorte << endl;

        FaseCP();
    

        //comandos do turno de conquista passar
        //cin >> escolha;

        //switch (escolha)
        //{
        //case 1:
        //    cout << "O jogador pode escolher uma das seguintes opções:" << endl;
        //    conquistar_passar();
        //    turno++;
        //    break;
        //case 2:
        //    cout << "Recolhe os produtos dos territorios conquistados" << endl;
        //    break;
        //case 3:
        //    cout << "Aumentar as forças militares" << endl;
        //    // chamar funçao que permite escolher entre obter tecnologias ou aumentar força militar
            
        //    break;
        //case 4:
        //    cout << "Ah um evento" << endl;
        //    //chamar funçao que atribui aleatóriamente um evento(Recurso abandonado/ invasao) e termina o turno
        //    break;
        //case 5:
        //    cout << "NOME\tRESISTENCIA\tPRODUTOS\tOURO\tPONTOS VITORIA\tCONQUISTADO" << endl;
        //    for (unsigned int i = 0; i < jogo.size(); i++) // listar todos 
        //        oss << jogo[i]->getAsString();
        //    cout << oss.str();
        //    break;
        //case 0:
        //    exit(0);
        //}
    }
}

void Interacao::comeca_jogo() {
    cout << "Entrou no jogo" << endl;
    escrita_menus();
}

void Interacao::carregar(string nomefich) {
    int maxr = 1;

    string cmd;

    ifstream myFile(nomefich);

    string str, copia, tipoTerritorio, rep, lixo;
    
    if (!myFile.is_open()) {
        cout << "Ficheiro nao existe, nada foi carregado" << endl;
        return;
    }


    while (getline(myFile, cmd))
    {
        cout << cmd << endl;
        istringstream bufi(cmd);
        ostringstream oss;
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
                                    jogo.push_back(new Refugio_Pirata());
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
                                    
                                    jogo.push_back(new Pescaria());
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
                                    jogo.push_back(new Planicie());
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
                                   
                                    jogo.push_back(new Castelo());
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

                                    jogo.push_back(new Fortaleza());
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
                                    
                                    jogo.push_back(new Duna());
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
                                    
                                    jogo.push_back(new Mina());
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
                                    
                                    jogo.push_back(new Montanha());
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
                        cout << "NOME\tRESISTENCIA\tPRODUTOS\tOURO\tPONTOS VITORIA\tCONQUISTADO" << endl;
                        for (unsigned int i = 0; i < jogo.size(); i++)
                            oss << jogo[i]->getAsString();
                        cout << oss.str();
                    }
                    else
                        if (copia == "sair")
                        {
                            exit(0);
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
    return;
}

int Interacao::comandline() {
    int maxr = 1;

    string cmd, str, copia, nomefich, tipoTerritorio, rep, lixo;

    cout << "Lista de comandos:\n\tcarrega <nome_ficheiro>\n\tcria <Tipo_de_Territorio> <numero_de_vezes>\n\tlista\n\tavanca\n\tsair\n\n";

    for (;;)
    {

        cout << "<comando> ";
        fflush(stdout);
        getline(cin, cmd);

        istringstream bufi(cmd);
        ostringstream oss;

        while (bufi >> str)
        {
            copia = str;
            if (copia == "carrega")
            {
                bufi >> nomefich;
                cout << "executei o carrega " << nomefich << endl;
                carregar(nomefich);
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
                                    jogo.push_back(new Refugio_Pirata());
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
                                    jogo.push_back(new Pescaria());
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
                                    jogo.push_back(new Planicie());
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
                                    jogo.push_back(new Castelo());
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
                                    jogo.push_back(new Fortaleza());
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
                                    jogo.push_back(new Duna());
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
                                    jogo.push_back(new Mina());
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
                                    jogo.push_back(new Montanha());
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
                        cout << "NOME\tRESISTENCIA\tPRODUTOS\tOURO\tPONTOS VITORIA\tCONQUISTADO" << endl;
                        for (unsigned int i = 0; i < jogo.size(); i++)
                            oss << jogo[i]->getAsString();
                        cout << oss.str();

                    }
                    else
                        if (copia == "avanca") {
                            jogo.push_back(new Territorio_Inicial());
                            comeca_jogo();
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
