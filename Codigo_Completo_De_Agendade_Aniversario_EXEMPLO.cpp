#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
          AGENDA DE ANIVERSÁRIOS

          Código escrito por Wagner Gaspar
          Junho de 2021
*/

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam){

    if(quant < tam){
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;
        return 1;
    }
    else{
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        return 0;
    }
}

void *alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        Contato *novo = malloc(sizeof(Contato));
        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
}

void salvar(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "w");
    int i;

    if(file){
        fprintf(file, "%d\n", quant);
        for(i = 0; i < quant; i++){
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
}

int ler_arquivo(Contato **c, char arq[]){
    FILE *file = fopen(arq, "r");
    int quant = 0, i;
    Contato *novo = malloc(sizeof(Contato));

    if(file){
        fscanf(file, "%d\n", &quant);
        for(i = 0; i < quant; i++){
            //fgets(novo->nome, 50, file);
            fscanf(file, "%50[^\n]", novo->nome);
            fscanf(file, "%d %d %d\n", &novo->dia, &novo->mes, &novo->ano);
            c[i] = novo;
            novo = malloc(sizeof(Contato));
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
    return quant;
}

int main(){

    Contato *agenda[50];
    char arquivo[] = {"agenda.txt"};
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            alterar_contato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:
            salvar(agenda, quant, arquivo);
            break;
        case 5:
            quant = ler_arquivo(agenda, arquivo);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
