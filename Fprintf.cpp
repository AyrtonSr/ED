#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
        Aula 213: Como escrever em um arquivo texto com a função fprintf?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char nome[100];
    int opcao, idade;
    float altura;

    if(file) {
        do{
            printf("Digite nome, idade e altura: ");
            scanf("%99[^\n]%d%f", nome, &idade, &altura);
            fprintf(file, "%s %d %.2f\n", nome, idade, altura);
            printf("\nDigite 1 para inserir outro registro. ");
            scanf("%d", &opcao);
            scanf("%c");
        }while(opcao == 1);
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);

    return 0;
}
