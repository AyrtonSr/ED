#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
        Aula 211: Como escrever linhas de texto com a função fputs?

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
    char texto[500];

    if(file) {
        printf("Digite uma frase ou 1 caracter para finalizar:\n");
        scanf("%499[^\n]", texto);
        scanf("%c"); // limpa o ENTER que ficou no buffer do teclado
        while(strlen(texto) > 1){
            fputs(texto, file);
            fputc('\n', file);
            scanf("%499[^\n]", texto);
            scanf("%c");
        }
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);

    return 0;
}
