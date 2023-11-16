#include<stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;


typedef struct FILA
{
  int nPacote;
  FILA *proxpacote;
} FILA;

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void enqueue(FILA **inicio, FILA **fim, int pacote){

    FILA *novoPacote = new FILA();

    if ((*inicio)==NULL){
        (*inicio)=novoPacote;
        (*fim)=novoPacote;
        novoPacote->nPacote = pacote;
        novoPacote->proxpacote = NULL;
    }else{
        (*fim)->proxpacote = novoPacote;
        (*fim) = (*fim)->proxpacote;
        novoPacote->nPacote = pacote;
        novoPacote->proxpacote=NULL;
    }
}

FILA *dequeue(FILA *&inicio){

    FILA *aux;
    aux=inicio;
    inicio= inicio->proxpacote;
    return aux;
}

void telaDeCarregamento(){
    system("COLOR 0e");

    int bar1 = 177, bar2 = 219;
    gotoxy(28,4);cout<<"Carregando...";
    for(int i=20;i<=45;i++){
    gotoxy(i,5);printf("%c", bar1);
    }
    for(int i=20;i<=45;i++){
    gotoxy(i,5);printf("%c", bar2);
    Sleep(150);
    }
}


int main (){
    FILA *inicio = NULL;
    FILA *fim = NULL;
    int tamanho = 0, pacotes = 50, qtdpacotes = 0, c=1;

    gotoxy(4,2);cout << "INFORME O TAMANHO DO ARQUIVO(EM KB): ";
    cin >> tamanho;
    if (tamanho%pacotes == 0){
        qtdpacotes = tamanho/pacotes;
    } else{
        qtdpacotes = (tamanho/pacotes)+1;
    }
    gotoxy(5,2);cout << "Quantidade de pacotes necessarios: "<<qtdpacotes<<endl;
    system("pause");

    while(c<=qtdpacotes){
        enqueue(&inicio, &fim, c);
        c++;
    }
    int y=7;
    system("cls");
    while(inicio!=NULL){
        FILA *aux;
        aux=dequeue(inicio);
        telaDeCarregamento();
        gotoxy(5,y);cout<< "Pacote "<<aux->nPacote<< " Carregado";
        y++;
        delete(aux);
    }


return 0;
}
