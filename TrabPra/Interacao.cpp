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
        << "\tmaisouro;" << endl
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

/*void Interacao::conquistar(){
    system("cls");
    int esc;
    ostringstream oss;
    string terrPretendido;
    srand((unsigned int)time(NULL));
    bool existe = false; // verifica se o territorio existe
    bool sucesso;


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
                    sucesso = jogo[i]->setConquista(força_militar,sorte,tecs[1]->getComprada());
                    if (sucesso) {
                        cout << "Territorio " << jogo[i]->getNometerritorio() << " Conquistado" << endl;
                        ultimoTerr = jogo[i]->getNometerritorio();
                    }
                    else{

                    }
                    
                }
                else if (jogo[i]->getConquista() == true) {
                    cout << "Territorio já conquistado" << endl;
                    break;
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
}*/

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

    string copia, str, cmd,nomeTerritorio,nomePesquisa,tipoDebug,nomeTipoDebug;
    bool verificaEscConqPass = false;
    int sucesso;
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
                                sucesso = jogo[i]->setConquista(força_militar, sorte, conquistaIlhas,nTerrConq);
                                if (sucesso == 0){ 
                                        cout << "Territorio " << jogo[i]->getNometerritorio() << " Conquistado" << endl;
                                        verificaEscConqPass = true;
                                        ultimoTerr.push_back(i);
                                    }
                                else if (sucesso == 1){ 
                                    cout << "Falhou a Conquista do Territorio " << jogo[i]->getNometerritorio() << endl;
                                    if(força_militar>0)
                                    força_militar--;
                                    verificaEscConqPass = true;
                                }
                                else if (sucesso == 2){
                                    cout << "Não tem a tecnologia " << tecs[1]->getNome() << " para conquistar uma ilha !" <<endl;
                                }
                                else if (sucesso == 3){
                                    cout << "Não tem 5 ou mais territorios" << endl;
                                }
                            }
                            else if (jogo[i]->getConquista() == true) {
                                cout << "Territorio já conquistado" << endl;
                            }
                        }
                    }
                    if (!existe)
                        {
                        cout << "Territorio Não Exite" << endl;
                        }
                    

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
                tipoDebug = "";
                bufi >> tipoDebug;
                if (tipoDebug == "terr") {
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    bool existeDebug = false;
                    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios
                        if (nomeTerritorio == jogo[i]->getNometerritorio()) {
                            existeDebug = true;
                            if (jogo[i]->getConquista() == false)
                            {
                                jogo[i]->setConquistaADM(true);
                                cout << "O territorio" << jogo[i]->getNometerritorio() << "foi adquirido." << endl;
                            }
                            else if (jogo[i]->getConquista() == true) {
                                cout << "Territorio já conquistado" << endl;
                            }
                        }
                        if (!existeDebug)
                            cout << "Territorio não existe" << endl;
                    }
                }
            }

            if(tipoDebug == "tecs")
            {
                nomeTipoDebug = "";
                bufi >> nomeTipoDebug;
               if (nomeTipoDebug == "drone")
               {
                    if (tecs[0]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[0]->getNome() << endl;
                        tecs[0 ]->setComprada();
                        força_militar_max = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
               }

               if (nomeTipoDebug == "missil")
               {
                    if (tecs[1]->getComprada() == false)
                    {
                        cout << "O jogador comprou a tecnologia " << tecs[1]->getNome() << endl;
                        tecs[1]->setComprada();
                        conquistaIlhas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                  
               }

               if (nomeTipoDebug == "defesa")
               {
                    if (tecs[2]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[2]->getNome() << endl;
                        tecs[2]->setComprada();
                        resistenciaBonus = 1;

                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "bolsa")
               {
                    if (tecs[3]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[3]->getNome() << endl;
                        tecs[3]->setComprada();
                        fazerTrocas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "banco")
               {
                    if(tecs[4]->getComprada() == false){
                        cout << "O jogador comprou a tecnologia " << tecs[4]->getNome() << endl;
                        tecs[4]->setComprada();
                        ouroMax = 5;
                        produtosMax = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    } 
               }
            }

            if (copia == "modifica")
            {
                tipoDebug = "";
                bufi >> tipoDebug;
                if(tipoDebug == "ouro"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    ouroTotal += stoi(nomeTipoDebug);
                    if (ouroTotal > ouroMax)
                        ouroTotal = ouroMax;
                    cout << "Tem " << ouroTotal << "unidades de ouro no total" << endl;
                }
                if(tipoDebug == "prod"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    produtosTotal += stoi(nomeTipoDebug);
                    if (produtosTotal > produtosMax)
                        produtosTotal = produtosMax;
                    cout << "Tem " << produtosTotal << "unidades de produtos no total" << endl;
                }
            }
            if (copia == "fevento")
            {
                tipoDebug = "";
                bufi >> tipoDebug;

                if (tipoDebug == "Sem") {
                    idEventoPretendido = 0;
                }
                if (tipoDebug == "Recurso") {
                    idEventoPretendido = 1;
                }
                if (tipoDebug == "Invasao") {
                    idEventoPretendido = 2;
                }
                if (tipoDebug == "Alianca") {
                    idEventoPretendido = 3;

                }



            }

        }
    }
}

void Interacao::FaseRP(){
    string copia, str, cmd, nomePesquisa,nomeTipoDebug,tipoDebug,nomeTerritorio;
    bool verificaTrocas = false;
    mostra_comandos_RP();

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
            if (copia == "maisprod")
            {
                if (fazerTrocas) {
                    if (!verificaTrocas)
                    {
                        if (ouroTotal >= 2 && produtosTotal < produtosMax) {
                            cout << "O jogador trocou 2 uni. de ouro por 1 uni. de prod" << endl;
                            produtosTotal++;
                            ouroTotal -= 2;
                            verificaTrocas = true;
                        }
                        else
                            if (produtosMax == produtosTotal)
                                cout << "Já tem a quantidade maxima de produtos" << endl;
                            else
                                cout << "O jogador não tem ouro suficiente para fazer a troca !" << endl;
                    }
                    else
                        cout << "Ja fez a opcao possivel neste turno !" << endl;
                }
                else
                    cout << "Não tem a tecnologia" << tecs[3]->getNome() << endl;
            }
            if (copia == "maisouro")
            {
                if (fazerTrocas) {
                if (!verificaTrocas){
                    if (produtosTotal >= 2 && ouroTotal < ouroMax) {
                        cout << "O jogador trocou 2 uni. de produtos por 1 uni. de ouro" << endl;
                        ouroTotal++;
                        produtosTotal -= 2;
                        verificaTrocas = true;
                    }
                    else
                        if (ouroMax == ouroTotal)
                            cout << "Já tem a quantidade maxima de produtos" << endl;
                        else
                            cout << "O jogador não tem ouro suficiente para fazer a troca !" << endl;
                }
                else
                {
                    cout << "Ja fez a operacao neste turno !" << endl;
                }
                }
                else
                    cout << "Não tem a tecnologia" << tecs[3]->getNome() << endl;
            }
            if (copia == "lista") {
                nomePesquisa = "";
                if (!(bufi >> nomePesquisa)) {
                    ListarTudo();
                }
                else if (nomePesquisa == "meus") {
                    ListarConquistados();
                }
                else if (nomePesquisa != "") {
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
                tipoDebug = "";
                bufi >> tipoDebug;
                if (tipoDebug == "terr") {
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    bool existeDebug = false;
                    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios
                        if (nomeTerritorio == jogo[i]->getNometerritorio()) {
                            existeDebug = true;
                            if (jogo[i]->getConquista() == false)
                            {
                                jogo[i]->setConquistaADM(true);
                                cout << "O territorio" << jogo[i]->getNometerritorio() << "foi adquirido." << endl;
                            }
                            else if (jogo[i]->getConquista() == true) {
                                cout << "Territorio já conquistado" << endl;
                            }
                        }
                        if (!existeDebug)
                            cout << "Territorio não existe" << endl;
                    }
                }
            }

            if(tipoDebug == "tecs")
            {
                nomeTipoDebug = "";
                bufi >> nomeTipoDebug;
               if (nomeTipoDebug == "drone")
               {
                    if (tecs[0]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[0]->getNome() << endl;
                        tecs[0 ]->setComprada();
                        força_militar_max = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
               }

               if (nomeTipoDebug == "missil")
               {
                    if (tecs[1]->getComprada() == false)
                    {
                        cout << "O jogador comprou a tecnologia " << tecs[1]->getNome() << endl;
                        tecs[1]->setComprada();
                        conquistaIlhas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                  
               }

               if (nomeTipoDebug == "defesa")
               {
                    if (tecs[2]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[2]->getNome() << endl;
                        tecs[2]->setComprada();
                        resistenciaBonus = 1;

                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "bolsa")
               {
                    if (tecs[3]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[3]->getNome() << endl;
                        tecs[3]->setComprada();
                        fazerTrocas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "banco")
               {
                    if(tecs[4]->getComprada() == false){
                        cout << "O jogador comprou a tecnologia " << tecs[4]->getNome() << endl;
                        tecs[4]->setComprada();
                        ouroMax = 5;
                        produtosMax = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    } 
               }
            }

            if (copia == "modifica")
            {
                tipoDebug = "";
                bufi >> tipoDebug;
                if(tipoDebug == "ouro"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    ouroTotal += stoi(nomeTipoDebug);
                    if (ouroTotal > ouroMax)
                        ouroTotal = ouroMax;
                    cout << "Tem " << ouroTotal << "unidades de ouro no total" << endl;
                }
                if(tipoDebug == "prod"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    produtosTotal += stoi(nomeTipoDebug);
                    if (produtosTotal > produtosMax)
                        produtosTotal = produtosMax;
                    cout << "Tem " << produtosTotal << "unidades de produtos no total" << endl;
                }
            }
            if (copia == "fevento")
            {
                tipoDebug = "";
                bufi >> tipoDebug;

                if (tipoDebug == "Sem") {
                    idEventoPretendido = 0;
                }
                if (tipoDebug == "Recurso") {
                    idEventoPretendido = 1;
                }
                if (tipoDebug == "Invasao") {
                    idEventoPretendido = 2;
                }
                if (tipoDebug == "Alianca") {
                    idEventoPretendido = 3;

                }



            }

        }
    }
}

void Interacao::FaseCUMT(){
    string copia, str, cmd, nomePesquisa, tipo, nomeTipoDebug, tipoDebug, nomeTerritorio;
    bool verificaCompras = false;
    mostra_comandos_CUMT();
    cout << "=====Loja=====" << endl;
    listaTecs();

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
            if (copia == "adquire")
            {
               bufi >> tipo;
               if (tipo == "drone")
               {
                   if (!verificaCompras) {
                       if (ouroTotal >= tecs[0]->getPreco() && tecs[0]->getComprada() == false) {
                           cout << "O jogador comprou a tecnologia " << tecs[0]->getNome() << endl;
                           tecs[0 ]->setComprada();
                           força_militar_max = 5;
                           ouroTotal -= tecs[0]->getPreco();
                           verificaCompras = true;
                       }
                       else {
                           if (ouroTotal < tecs[0]->getPreco()) {
                               cout << "Não tem dinheiro suficiente" << endl;
                           }
                           else {
                               cout << "Ja comprou o artigo" << endl;
                           }
                       }
                   }
                   else{
                        cout << "Ja fez a sua compra neste turno" << endl;
                    }
               }
               if (tipo == "missil")
               {
                   if (!verificaCompras) {
                       if (ouroTotal >= tecs[1]->getPreco() && tecs[1]->getComprada() == false)
                       {
                           cout << "O jogador comprou a tecnologia " << tecs[1]->getNome() << endl;
                           tecs[1]->setComprada();
                           conquistaIlhas = true;
                           ouroTotal -= tecs[1]->getPreco();
                           verificaCompras = true;
                       }
                       else {
                           if (ouroTotal < tecs[1]->getPreco()) {
                               cout << "Nao tem dinheiro suficiente" << endl;
                           }
                           else {
                               cout << "Ja comprou o artigo" << endl;
                           }
                       }
                   }
                   else{
                        cout << "Ja fez a sua compra neste turno" << endl;
                    }
                  
               }
               if (tipo == "defesa")
               {
                    if (!verificaCompras) {
                       if (ouroTotal >= tecs[2]->getPreco() && tecs[2]->getComprada() == false) {
                           cout << "O jogador comprou a tecnologia " << tecs[2]->getNome() << endl;
                           tecs[2]->setComprada();
                           resistenciaBonus = 1;
                           ouroTotal -= tecs[2]->getPreco();
                           verificaCompras = true;
                       }
                       else {
                           if (ouroTotal < tecs[2]->getPreco()) {
                               cout << "Não tem dinheiro suficiente" << endl;
                           }
                           else {
                               cout << "Ja comprou o artigo" << endl;
                           }
                       }
                   }
                    else{
                        cout << "Ja fez a sua compra neste turno" << endl;
                    }
               }
               if (tipo == "bolsa")
               {
                    if (!verificaCompras) {
                       if (ouroTotal >= tecs[3]->getPreco() && tecs[3]->getComprada() == false) {
                           cout << "O jogador comprou a tecnologia " << tecs[3]->getNome() << endl;
                           tecs[3]->setComprada();
                           fazerTrocas = true;
                           ouroTotal -= tecs[3]->getPreco();
                           verificaCompras = true;
                       }
                       else {
                           if (ouroTotal < tecs[0]->getPreco()) {
                               cout << "Não tem dinheiro suficiente" << endl;
                           }
                           else {
                               cout << "Ja comprou o artigo" << endl;
                           }
                       }
                   }
                   else{
                        cout << "Ja fez a sua compra neste turno" << endl;
                    }
               }
               if (tipo == "banco")
               {
                   if (!verificaCompras) {
                       if (ouroTotal >= tecs[4]->getPreco() && tecs[4]->getComprada() == false)
                       {
                           cout << "O jogador comprou a tecnologia " << tecs[4]->getNome() << endl;
                           tecs[4]->setComprada();
                           ouroMax = 5;
                           produtosMax = 5;
                           ouroTotal -= tecs[4]->getPreco();
                           verificaCompras = true;

                       }
                       else {
                           if (ouroTotal < tecs[4]->getPreco()) {
                               cout << "Nao tem dinheiro suficiente" << endl;
                           }
                           else {
                               cout << "Ja comprou o artigo" << endl;
                           }
                       }
                   }
                   else{
                        cout << "Ja fez a sua compra neste turno" << endl;
                   }
               }
            }
            if (copia == "maismilitar")
            {
                if (!verificaCompras)
                {
                    if (ouroTotal >= 1 && produtosTotal >= 1 && força_militar < força_militar_max) {
                        cout << "O jogador obteve mais 1 uni. de forca militar." << endl;
                        força_militar++;
                        ouroTotal--;
                        produtosTotal--;
                        verificaCompras = true;
                    }
                    else {
                        if (força_militar == força_militar_max)
                            cout << "Já tem a quantidade maxima de forca militar" << endl;
                        else
                            cout << "O jogador não recursos suficiente para fazer a compra !" << endl;
                    }
                }
                else
                {
                    cout << "Ja fez a operacao neste turno!" << endl;
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
                else if (nomePesquisa != "") {
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
                tipoDebug = "";
                bufi >> tipoDebug;
                if (tipoDebug == "terr") {
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    bool existeDebug = false;
                    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios
                        if (nomeTerritorio == jogo[i]->getNometerritorio()) {
                            existeDebug = true;
                            if (jogo[i]->getConquista() == false)
                            {
                                jogo[i]->setConquistaADM(true);
                                cout << "O territorio" << jogo[i]->getNometerritorio() << "foi adquirido." << endl;
                            }
                            else if (jogo[i]->getConquista() == true) {
                                cout << "Territorio já conquistado" << endl;
                            }
                        }
                        if (!existeDebug)
                            cout << "Territorio não existe" << endl;
                    }
                }
            }

            if(tipoDebug == "tecs")
            {
                nomeTipoDebug = "";
                bufi >> nomeTipoDebug;
               if (nomeTipoDebug == "drone")
               {
                    if (tecs[0]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[0]->getNome() << endl;
                        tecs[0 ]->setComprada();
                        força_militar_max = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
               }

               if (nomeTipoDebug == "missil")
               {
                    if (tecs[1]->getComprada() == false)
                    {
                        cout << "O jogador comprou a tecnologia " << tecs[1]->getNome() << endl;
                        tecs[1]->setComprada();
                        conquistaIlhas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                  
               }

               if (nomeTipoDebug == "defesa")
               {
                    if (tecs[2]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[2]->getNome() << endl;
                        tecs[2]->setComprada();
                        resistenciaBonus = 1;

                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "bolsa")
               {
                    if (tecs[3]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[3]->getNome() << endl;
                        tecs[3]->setComprada();
                        fazerTrocas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "banco")
               {
                    if(tecs[4]->getComprada() == false){
                        cout << "O jogador comprou a tecnologia " << tecs[4]->getNome() << endl;
                        tecs[4]->setComprada();
                        ouroMax = 5;
                        produtosMax = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    } 
               }
            }

            if (copia == "modifica")
            {
                tipoDebug = "";
                bufi >> tipoDebug;
                if(tipoDebug == "ouro"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    ouroTotal += stoi(nomeTipoDebug);
                    if (ouroTotal > ouroMax)
                        ouroTotal = ouroMax;
                    cout << "Tem " << ouroTotal << "unidades de ouro no total" << endl;
                }
                if(tipoDebug == "prod"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    produtosTotal += stoi(nomeTipoDebug);
                    if (produtosTotal > produtosMax)
                        produtosTotal = produtosMax;
                    cout << "Tem " << produtosTotal << "unidades de produtos no total" << endl;
                }
            }
            if (copia == "fevento")
            {
                tipoDebug = "";
                bufi >> tipoDebug;

                if (tipoDebug == "Sem") {
                    idEventoPretendido = 0;
                }
                if (tipoDebug == "Recurso") {
                    idEventoPretendido = 1;
                }
                if (tipoDebug == "Invasao") {
                    idEventoPretendido = 2;
                }
                if (tipoDebug == "Alianca") {
                    idEventoPretendido = 3;

                }



            }

        }
    }
}

void Interacao::FaseFE()
{
    string copia, str, cmd, nomePesquisa, tipo, nomeTipoDebug, tipoDebug, nomeTerritorio;

    aplicaEvento();
    mostra_comandos_FE();

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

                if (copia == "lista") {
                    nomePesquisa = "";
                    if (!(bufi >> nomePesquisa)) {
                        ListarTudo();
                    }
                    else if (nomePesquisa == "meus") {
                        ListarConquistados();
                    }
                    else if (nomePesquisa != "") {
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
                tipoDebug = "";
                bufi >> tipoDebug;
                if (tipoDebug == "terr") {
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    bool existeDebug = false;
                    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios
                        if (nomeTerritorio == jogo[i]->getNometerritorio()) {
                            existeDebug = true;
                            if (jogo[i]->getConquista() == false)
                            {
                                jogo[i]->setConquistaADM(true);
                                cout << "O territorio" << jogo[i]->getNometerritorio() << "foi adquirido." << endl;
                            }
                            else if (jogo[i]->getConquista() == true) {
                                cout << "Territorio já conquistado" << endl;
                            }
                        }
                        if (!existeDebug)
                            cout << "Territorio não existe" << endl;
                    }
                }
            }

            if(tipoDebug == "tecs")
            {
                nomeTipoDebug = "";
                bufi >> nomeTipoDebug;
               if (nomeTipoDebug == "drone")
               {
                    if (tecs[0]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[0]->getNome() << endl;
                        tecs[0 ]->setComprada();
                        força_militar_max = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
               }

               if (nomeTipoDebug == "missil")
               {
                    if (tecs[1]->getComprada() == false)
                    {
                        cout << "O jogador comprou a tecnologia " << tecs[1]->getNome() << endl;
                        tecs[1]->setComprada();
                        conquistaIlhas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                  
               }

               if (nomeTipoDebug == "defesa")
               {
                    if (tecs[2]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[2]->getNome() << endl;
                        tecs[2]->setComprada();
                        resistenciaBonus = 1;

                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "bolsa")
               {
                    if (tecs[3]->getComprada() == false) {
                        cout << "O jogador comprou a tecnologia " << tecs[3]->getNome() << endl;
                        tecs[3]->setComprada();
                        fazerTrocas = true;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    }
                   
               }

               if (nomeTipoDebug == "banco")
               {
                    if(tecs[4]->getComprada() == false){
                        cout << "O jogador comprou a tecnologia " << tecs[4]->getNome() << endl;
                        tecs[4]->setComprada();
                        ouroMax = 5;
                        produtosMax = 5;
                    }
                    else {
                        cout << "Ja comprou o artigo" << endl;
                    } 
               }
            }

            if (copia == "modifica")
            {
                tipoDebug = "";
                bufi >> tipoDebug;
                if(tipoDebug == "ouro"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    ouroTotal += stoi(nomeTipoDebug);
                    if (ouroTotal > ouroMax)
                        ouroTotal = ouroMax;
                    cout << "Tem " << ouroTotal << "unidades de ouro no total" << endl;
                }
                if(tipoDebug == "prod"){
                    nomeTipoDebug = "";
                    bufi >> nomeTipoDebug;
                    produtosTotal += stoi(nomeTipoDebug);
                    if (produtosTotal > produtosMax)
                        produtosTotal = produtosMax;
                    cout << "Tem " << produtosTotal << "unidades de produtos no total" << endl;
                }
            }
            if (copia == "fevento")
            {
                tipoDebug = "";
                bufi >> tipoDebug;

                if (tipoDebug == "Sem") {
                    idEventoPretendido = 0;
                }
                if (tipoDebug == "Recurso") {
                    idEventoPretendido = 1;
                }
                if (tipoDebug == "Invasao") {
                    idEventoPretendido = 2;
                }
                if (tipoDebug == "Alianca") {
                    idEventoPretendido = 3;
                }
            }

        }
    }
}

void Interacao::aplicaEvento(){
    

    int i; 
    if(idEventoPretendido == 4)
        i = rand() % 4;
    else{
        i = idEventoPretendido;
        idEventoPretendido = 4;
    }

    
    if (i == 0)
    {
        cout << "Não há evento" << endl;
        return;
    }
    else if (i==1) {
        cout << "Recurso Abandonado" << endl;
        if (ano == 1 && produtosTotal < produtosMax) {
            cout << "Foi encontrado 1 uni. de produtos" << endl;
            produtosTotal++;
        }
        else if (ano == 2 && ouroTotal < ouroMax) {
            cout << "Foi encontrado 1 uni. de ouro" << endl;
            ouroTotal++;
        }
        return;
    }
    else if (i==2) {

        cout << "UMA INVASÃO SOBRE " << jogo[ultimoTerr[ultimoTerr.size() - 1]]->getNometerritorio() << " ESTA A COMECAR" << endl;
        int forcaInvasao = 0;
        if (ano == 1) forcaInvasao = 2;
        if (ano == 2) forcaInvasao = 3;
        sorteAdversaria = rand() % 6 + 1;
        cout << "ForcaInv = " << forcaInvasao << " SorteInv = " << sorteAdversaria;
        cout << " Resistencia do teu territorio " << (jogo[ultimoTerr[ultimoTerr.size() - 1]]->getResistencia() + resistenciaBonus) << endl;
        if((forcaInvasao + sorteAdversaria) > (jogo[ultimoTerr[ultimoTerr.size()-1]]->getResistencia() + resistenciaBonus)){
            cout << "Força Invasora conquistou o Territorio" << jogo[ultimoTerr[ultimoTerr.size() - 1]]->getNometerritorio() << endl;
            jogo[ultimoTerr[ultimoTerr.size() - 1]]->setConquistaADM(false);
            if (jogo[ultimoTerr[ultimoTerr.size() - 1]]->getNometerritorio() == jogo[jogo.size() - 1]->getNometerritorio())
                ano = 4; // ano em que o jogador ganha o jogo
            ultimoTerr.pop_back();

        }
        else {
            cout << "A forca invasora falhou a conquista do territorio " << jogo[ultimoTerr[ultimoTerr.size() - 1]]->getNometerritorio() << endl;

        }

        return;
    }
    else if (i==3){
        cout << "Alianca Diplomatica" << endl;
        if (força_militar < força_militar_max) {
            cout << "O jogador fez uma alianca com um imperio desconhecido. A sua forca militar aumenta 1 uni." << endl;
            força_militar++;
        }
        else // caso a força militar tenha atingido o max nao incrementa a força mas considera-se que sim.
            cout << "O jogador fez uma alianca com um imperio desconhecido.Mas sua forca militar ja esta ao maximo" << endl;

    }
    return;
}

void Interacao::status(){
    cout << "ANO: " << ano << endl;
    cout << "TURNO: " << turno << endl;
    cout << "FORCA MILITAR: " << força_militar << endl;
    cout << "ULTIMA SORTE: " << sorte << endl;
    cout << "OURO: " << ouroTotal << endl;
    cout << "PRODUTOS: " << produtosTotal << endl;
}

void Interacao::iniciaTecs(){ // criação das tecnologias
    tecs.push_back(new Tecnologias("Drones militares", 3));
    tecs.push_back(new Tecnologias("Misseis teleguiados", 4));
    tecs.push_back(new Tecnologias("Defesas Territoriais", 4));
    tecs.push_back(new Tecnologias("Bolsa de valores", 2));
    tecs.push_back(new Tecnologias("Banco central", 3));
}

void Interacao::listaTecs(){
    ostringstream oss;
    for (unsigned int i = 0; i < tecs.size(); i++) // listar todos as Tecnologias
        oss << tecs[i]->getAsString();
    cout << oss.str();
}

int Interacao::buscaConq(){
    int nt=0;
    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios que foram conquistados
        if (jogo[i]->getConquista() == true)
            nt++;
    }
    return nt;

}
int Interacao::buscaConqPont(){
    int pontos=0;
    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios que foram conquistados
        if (jogo[i]->getConquista() == true)
            pontos+= jogo[i]->getPontosVitoria();
    }
    return pontos;

}

void Interacao::recolheTudo(){
    for (unsigned int i = 0; i < jogo.size(); i++) { // listar todos os territórios que foram conquistados
        if (jogo[i]->getConquista() == true) {
            ouroTotal += jogo[i]->recolheOuro(ano, turno);
            produtosTotal += jogo[i]->recolheProd(ano, turno);
        }
    }
    if (ouroTotal > ouroMax)
        ouroTotal = ouroMax;
    if (produtosTotal > produtosMax)
        produtosTotal = produtosMax;
}

void Interacao::escrita_menus() {
    system("cls");
    ultimoTerr.push_back(jogo.size()-1);
    srand((unsigned int)time(NULL));

    while(ano < 3 || buscaConq() < 1) {

        nTerrConq = buscaConq();
        status();
        FaseCP();
        status();
        FaseRP();
        status();
        FaseCUMT();
        status();
        FaseFE();
        recolheTudo();
        if(turno%6==0){
            ano++;
        }
        turno++;
    

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
    if (buscaConq() < 1)
        cout << "Fantastico conseguiste a unica maneira de perderes o jogo" << endl << "===========GAMEOVER==========" << endl;
    else{
        int pTerritorios, pImpSup=0, pTecs=0, pBonCien=0;
        pTerritorios = buscaConqPont();
        if (buscaConq() == jogo.size())
            pImpSup = 3;
        for (unsigned int i = 0; i < tecs.size(); i++) {
            if (tecs[i]->getComprada() == true)
                pTecs++;
        }
        if (pTecs == tecs.size())
            pBonCien = 1;
        cout << "Pontuacao:" << endl
            << "\t" << "Territorios: " << pTerritorios << endl
            << "\t" << "Imperador Supremo?" << pImpSup << endl
            << "\t" << "Tecnologias:" << pTecs << endl
            << "\t" << "Bonus Cientifico" << pBonCien << endl
            << "\t" << "Pontuacao Final:" << (pTerritorios+pImpSup+pTecs+pBonCien) << endl;
    }
}

void Interacao::comeca_jogo() {
    cout << "Entrou no jogo" << endl;
    iniciaTecs();
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
                            return;
                        }
                        else
                        {
                            cout << "\tO comando não existe,por favor verifique a integridade do ficheiro ou cite um ficheiro valido" << endl;
                            jogo.clear();
                            return;
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
