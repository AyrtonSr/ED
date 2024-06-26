//
// Created by lukas on 11/10/2023.
//

#include <iostream>
#include <string.h>
#include <windows.h>

#define MAX_PALAVRA 50
#define MAX_DESCRICAO 500

using namespace std;

typedef struct ListaPalavras {
    char palavra[MAX_PALAVRA];
    char descricao[MAX_DESCRICAO];
    int qtdPesquisas;
    ListaPalavras *proxPalavra;
} ListaPalavras;

typedef struct ListaLetras{
    char letra;
    int qtdPalavras;
    ListaPalavras *inicioPalavras, *fimPalavras;
    ListaLetras *proxLetra;
    ListaLetras *antLetra;
} ListaLetras;

void gotoxy(int x , int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void quadro (){

    gotoxy(0,0); printf("%c", 201);
    for (int i=1;i<=44;i++){
        gotoxy(i,0); printf("%c", 205);
    }
    gotoxy(45,0); printf("%c", 187);
    for (int c=1; c<=11; c++){
        gotoxy(0,c); printf("%c", 186);
    }
    for (int j=1; j<=11; j++){
        gotoxy(45,j); printf("%c", 186);
    }
    gotoxy(0,12); printf("%c", 200);
    for (int i=1;i<=44;i++){
        gotoxy(i,12); printf("%c", 205);
    }
    gotoxy(45,12); printf("%c", 188);
}

bool validPalavra(char *palavra){ // Verifica se o caracter está entre 'A' e 'Z' ou 'a' e 'z'
    int i = 0;

    while(palavra[i] != '\0'){

        if((palavra[i] < 65 || palavra[i] > 122) || (palavra[i] > 90 && palavra[i] < 97)){
            return false;
        } else {
            i++;
        }
    }

    return true;
}

ListaLetras *buscarLetra(ListaLetras *inicio, ListaLetras *fim, char letra){

    if(inicio == NULL){
        return NULL;
    } else if(inicio->letra == letra){
        return inicio;
    } else if(fim->letra == letra){
        return fim;
    } else {
        ListaLetras *aux = inicio;

        while(aux != NULL){
            if(aux->letra == letra){
                return aux;
            }
            aux = aux->proxLetra;
        }
    }

    return NULL;
}

ListaPalavras *buscarPalavra(ListaLetras *letra, char *palavra){

    if(letra == NULL){
        return NULL;
    }
    if(letra->inicioPalavras == NULL){
        return NULL;
    } else if(strcmp(letra->inicioPalavras->palavra, palavra) == 0){
        return letra->inicioPalavras;
    } else if(strcmp(letra->fimPalavras->palavra, palavra) == 0){
        return letra->fimPalavras;
    } else {
        ListaPalavras *aux = letra->inicioPalavras;

        while(aux != NULL){
            if(strcmp(aux->palavra, palavra) == 0){
                return aux;
            } else {
                aux = aux->proxPalavra;
            }
        }
    }

    return NULL;
}

ListaPalavras *buscarPalavraAnterior(ListaLetras *letra, char *palavra){

    if(letra->inicioPalavras == NULL){ // lista vazia
        return NULL;
    } else if(strcmp(letra->inicioPalavras->palavra, palavra) == 0){ // palavra no começo da lista
        return NULL;
    } else {
        ListaPalavras *aux = letra->inicioPalavras;

        while (aux != NULL) {
            if(aux->proxPalavra == NULL){ // se a proxima palavra nao existe
                return NULL;
            } else if(strcmp(aux->proxPalavra->palavra, palavra) == 0){ // se proxima palavra é igual à passada como parâmetro
                return aux;
            } else {
                aux = aux->proxPalavra;
            }
        }
    }

    return NULL;
}

void inserirLetra(ListaLetras **inicio, ListaLetras **fim, char letra){
    ListaLetras *novaLetra = new ListaLetras();

    novaLetra->letra = toupper(letra);
    novaLetra->qtdPalavras = 0;
    novaLetra->inicioPalavras = NULL;
    novaLetra->fimPalavras = NULL;

    if((*inicio) == NULL){ // Lista Vazia
        (*inicio) = novaLetra;
        (*fim) = novaLetra;
        novaLetra->antLetra = NULL;
        novaLetra->proxLetra = NULL;
    } else {
        (*fim)->proxLetra = novaLetra;
        (*fim)->proxLetra->antLetra = (*fim);
        (*fim) = (*fim)->proxLetra;
        novaLetra->proxLetra = NULL;
    }
}

void inserirPalavra(ListaLetras **inicio, ListaLetras **fim, char *palavra, char *descricao){

    if(validPalavra(palavra)){
        ListaLetras *letra;
        ListaPalavras *novaPalavra = new ListaPalavras();

        palavra = strupr(palavra);
        descricao[0] = toupper(descricao[0]);

        if(buscarLetra(*inicio, *fim, palavra[0]) == NULL){
            inserirLetra(inicio, fim, palavra[0]);
        }

        letra = buscarLetra(*inicio, *fim, palavra[0]);

        novaPalavra->qtdPesquisas = 0;
        strcpy(novaPalavra->palavra, palavra);
        strcpy(novaPalavra->descricao, descricao);

        if(letra->inicioPalavras == NULL){
            letra->inicioPalavras = novaPalavra;
            letra->fimPalavras = novaPalavra;
            novaPalavra->proxPalavra = NULL;
        } else {
            letra->fimPalavras->proxPalavra = novaPalavra;
            letra->fimPalavras = letra->fimPalavras->proxPalavra;
            novaPalavra->proxPalavra = NULL;
        }

        letra->qtdPalavras++;

    } else {
        // inserirErro();
    }
}

void exibirLetras(ListaLetras *inicio, ListaLetras *fim){
    ListaLetras *aux = inicio;

    if(inicio == NULL){
        cout << "Nenhuma letra esta disponivel!\n\n";
    } else {
        while(aux != NULL){
            cout << aux->letra << " " << aux->qtdPalavras << "; ";
            aux = aux->proxLetra;
        }
    }
}

void exibirPalavras(ListaLetras *inicio, ListaLetras *fim){
    char letra;

    ListaLetras *letraE;

    system("cls");

    if(inicio == NULL){
        cout << "Nenhuma palavra foi cadastrada ainda!\n\n";
    } else {
        cout << "Letras disponiveis para consulta\n\n";
        exibirLetras(inicio, fim);
        cout << "\n\n";

        cout << "Informe a letra que deseja consultar: ";
        cin >> letra;
        letra = toupper(letra);

        letraE = buscarLetra(inicio, fim, letra);

        if(letraE == NULL){
            cout << "\nOpcao nao identificada\n\n";
        } else {
            ListaPalavras *aux = letraE->inicioPalavras;

            cout << "Palavras cadastradas:\n\n";
            while(aux != NULL){
                cout << aux->palavra << ": " << aux->descricao << endl;
                aux = aux->proxPalavra;
            }
            cout << "\n\n";
        }
    }
    system("pause");
    system("cls");
}

void deletarLetra(ListaLetras **inicio, ListaLetras **fim, ListaLetras *letra){
    if((*inicio) == letra){
        (*inicio) = letra->proxLetra;
        (*inicio)->antLetra = NULL;
        delete(letra);
    } else if((*fim) == letra){
        (*fim) = letra->antLetra;
        (*fim)->proxLetra = NULL;
        delete(letra);
    } else {
        letra->antLetra->proxLetra = letra->proxLetra;
        letra->proxLetra->antLetra = letra->antLetra;
        delete(letra);
    }
}

void deletarPalavra(ListaLetras **inicio, ListaLetras **fim, char *palavra){
    if(validPalavra(palavra)){

        palavra = strupr(palavra);

        ListaLetras *letra = buscarLetra(*inicio, *fim, palavra[0]);

        if(letra != NULL){
            ListaPalavras *pAtual = buscarPalavra(letra, palavra);
            ListaPalavras *pAnterior = buscarPalavraAnterior(letra, palavra);

            if(pAtual != NULL){
                if(letra->inicioPalavras == pAtual){
                    letra->inicioPalavras = pAtual->proxPalavra;
                } else if(letra->fimPalavras == pAtual) {
                    pAnterior->proxPalavra = NULL;
                } else {
                    pAnterior->proxPalavra = pAtual->proxPalavra;
                }

                delete(pAtual);
                letra->qtdPalavras--;
            } else {
                // palavra nao encontrada
                // inserirErro();
            }

            if(letra->qtdPalavras == 0){
                deletarLetra(inicio, fim, letra);
            }
        } else {
            // letra nao encontrada
            // inserirErro();
        }

    } else {
        // inserirErro();
    }
}

void atualizarPalavra(ListaLetras **inicio,
                      ListaLetras **fim,
                      ListaPalavras *palavra,
                      char *novaPalavra,
                      char *novaDescricao){

    novaPalavra = strupr(novaPalavra);
    novaDescricao[0] = toupper(novaDescricao[0]);

    if(validPalavra(novaPalavra)){ // nova palavra é válida
        if(palavra->palavra[0] == novaPalavra[0]){
            strcpy(palavra->palavra, novaPalavra);
            strcpy(palavra->descricao, novaDescricao);
        } else {
            deletarPalavra(inicio, fim, palavra->palavra);
            inserirPalavra(inicio, fim, novaPalavra, novaDescricao);
        }
    } else {
        // inserirErro();
    }

}

int main(){
    ListaLetras *inicio= NULL;
    ListaLetras *fim = NULL;
    int menu = 1;
    char palavra[MAX_PALAVRA], descricao[MAX_DESCRICAO], opcao;

    while(menu != 0){
        quadro();
        gotoxy(1,2); cout << "               MENU PRINCIPAL             \n\n\n";
        gotoxy(3,3); printf("%c", 218);
        for (int i=4;i<=41;i++){
            gotoxy(i,3); printf("%c", 196);
        }
        gotoxy(5,4);cout << "[1] - Adicionar uma palavra           " << endl;
        gotoxy(5,5);cout << "[2] - Exibir as palavras existentes   " << endl;
        gotoxy(5,6);cout << "[3] - Deletar uma palavra             " << endl;
        gotoxy(5,7);cout << "[4] - Atualizar uma palavra           " << endl;
        gotoxy(5,8);cout << "[0] - Sair do programa                " << endl;

        gotoxy(42,3); printf("%c", 191);
        for (int j=4; j<=8;j++){
            gotoxy(3,j); printf("%c", 179);
        }
        for (int c=4; c<=8;c++){
            gotoxy(42,c); printf("%c", 179);
        }
        gotoxy(3,9); printf("%c", 192);
        gotoxy(42,9); printf("%c", 217);
        for (int k=4;k<=41;k++){
            gotoxy(k,9); printf("%c", 196);
        }
        gotoxy(4,10);cout << "Selecione uma opcao: ";
        cin >> menu;
        cin.ignore();

        switch (menu) {
            case 1:
                system("cls");

                gotoxy(1,2); cout << "               MENU ADICIONAR             \n\n\n";
                for (int i=4;i<=41;i++){
                    gotoxy(i,3); printf("%c", 196);
                }
                gotoxy(5,4); printf("%c", 254);
                gotoxy(7,4);cout << "Informe a palavra(MAX 50 caracteres): " << endl;
                gotoxy(44,4);cin.getline(palavra, MAX_PALAVRA);
                gotoxy(5,5); printf("%c", 254);
                gotoxy(7,5);cout << "Informe a descricao(MAX 500 caracteres):" << endl;
                gotoxy(48,5);cin.getline(descricao, MAX_DESCRICAO);
                inserirPalavra(&inicio, &fim, palavra, descricao);
                system("cls");

                break;
            case 2:
                exibirPalavras(inicio, fim);

                break;
            case 3:
                system("cls");

                cout << "Informe a palavra: ";
                cin.getline(palavra, MAX_PALAVRA);

                deletarPalavra(&inicio, &fim, palavra);

                break;
            case 4:
                system("cls");

                cout << "Informe a palavra que deseja atualizar: ";
                cin.getline(palavra, MAX_PALAVRA);

                if(validPalavra(palavra)){
                    ListaPalavras *palavraEncontrada = buscarPalavra(buscarLetra(inicio, fim, palavra[0]), strupr(palavra));

                    if(palavraEncontrada != NULL) {
                        char novaPalavra[MAX_PALAVRA];

                        cout << "Palavra atual: " << palavraEncontrada->palavra << endl;
                        cout << "Nova palavra: ";
                        cin.getline(novaPalavra, MAX_PALAVRA);

                        cout << "\nDescricao atual: " << palavraEncontrada->descricao << "\n\n";
                        cout << "Deseja atualizar a descricao de " << novaPalavra << "? [S/N]" << endl;
                        cout << "Digite a opcao: ";
                        cin >> opcao;
                        cin.ignore();

                        if(opcao == 'S' || opcao == 's'){
                            cout << "\nInforme a nova descricao: ";
                            cin.getline(descricao, MAX_DESCRICAO);
                            atualizarPalavra(&inicio, &fim, palavraEncontrada, novaPalavra, descricao);
                        } else if(opcao == 'N' || opcao == 'n'){
                            atualizarPalavra(&inicio, &fim, palavraEncontrada, novaPalavra, palavraEncontrada->descricao);
                        } else {
                            cout << "\nOpcao nao identificada" << endl;
                        }
                    } else {
                        cout << "\nPalavra nao encontrada" << endl;
                    }
                } else {
                    cout << "\nPalavra Invalida" << endl;
                    // inserirErro();
                }

                system("pause");
                system("cls");

                break;
            case 0:
                system("cls");
                cout << "Ate a proxima!";
                break;
            default:
                system("cls");
                cout << "Opcao invalida, tente novamente\n\n";
                break;
        }
    }

    system("pause");
}
