#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
        Aula 212: Como ler linhas de texto com a função fgets?

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
        scanf("%c");
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

void ler(char f[]) {
    FILE *file = fopen(f, "r");
    char texto[500];

    if(file){
        printf("\n\tTexto lido do arquivo\n");
        while(!feof(file)){
            if(fgets(texto, 499, file))
                printf("\n--> %s", texto);
        }
        fclose(file);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);
    ler(nome);

    return 0;
}
