#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include<windows.h>

#define MAX_PALAVRA 30
#define MAX_DESCRICAO 30

using namespace std;

void gotoxy(int x , int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void quadro (){

    gotoxy(0,0); printf("%c", 201);
    for (int i=1;i<=44;i++){
        gotoxy(i,0); printf("%c", 178);
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

void regua(){
    for (int i=0; i<=30; i++){
        gotoxy(i , 0); cout<<i;
    }
    for (int j=0; j<=30; j++){
        gotoxy(0 , j); cout<<j;
    }
}

void limparLinha(int linha, int largura) {
    gotoxy(1, linha);
    for (int i = 0; i < largura; i++) {
        cout << " ";
    }
    gotoxy(1, linha);
}

void inserirDados(char *destino, int maxCaracteres, int linha) {
    limparLinha(linha, maxCaracteres + 1); // +1 para limpar qualquer caractere anterior
    gotoxy(1, linha);
    cin.getline(destino, maxCaracteres);
}

int main (){

    char palavra[MAX_PALAVRA], descricao[MAX_DESCRICAO], opcao;

    quadro();
    //system("cls");
    gotoxy(1, 2);
    std::cout << "               MENU ADICIONAR             \n\n\n";
    gotoxy(1, 3);
    std::cout << "  ****************************************" << std::endl;
    gotoxy(1, 4);
    std::cout << "  Informe a palavra:                      " << std::endl;
    inserirDados(palavra, MAX_PALAVRA, 4);
    gotoxy(1, 5);
    std::cout << "  Informe a descricao:                    " << std::endl;
    inserirDados(descricao, MAX_DESCRICAO, 5);
    gotoxy(1, 6);
    std::cout << "  *                                      *" << std::endl;
    gotoxy(1, 7);
    std::cout << "  *                                      *" << std::endl;
    gotoxy(1, 8);
    std::cout << "  *                                      *" << std::endl;
    gotoxy(1, 9);
    std::cout << "  ****************************************" << std::endl;



return 0;
}
