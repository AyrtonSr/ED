#include<stdio.h>
#include<stdlib.h>

/*
        Aula 209: Como ler em arquivo texto com a função fgetc?

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

int main(){

    FILE *file;
    char letra;

    file = fopen("conto.txt","w+");

    if(file){
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        while(letra != '\n'){
            fputc(letra, file);
            scanf("%c", &letra);
        }

        rewind(file);

        printf("\n\tTexto lido do arquivo:\n");
        while(!feof(file)){
            letra = fgetc(file);
            printf("%c", letra);
        }

        fclose(file);
    }
    else
        printf("\n\t--> ERRO ao abrir arquivo!\n");

    return 0;
}
