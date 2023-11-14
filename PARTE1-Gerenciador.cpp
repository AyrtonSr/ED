//Gerenciador
#include <iostream>
#include <stdio.h>
#include <cstring>

#define ARMAZENAMENTO "armazenamento.txt"
#define AUXILIAR "auxiliar.txt"

using namespace std;

int main (){
    FILE *arq;
    char conteudo[400],conteudoF[400], conteudo2[400], conteudoF2[400];

    arq = fopen(ARMAZENAMENTO,"w");
    cout << "\nEscreva o conteudo do arquivo\n";
    gets(conteudo);
    fprintf(arq, "%s", conteudo);
    fclose(arq);

    arq = fopen(AUXILIAR,"w");
    cout << "\nEscreva o conteudo do arquivo\n";
    gets(conteudo2);
    fprintf(arq, "%s", conteudo2);
    fclose(arq);

    system ("pause");
    system ("cls");

    arq = fopen(ARMAZENAMENTO, "r");
    printf("Conteudo do arquivo armazenamento: ");
    fgets (conteudoF,400,arq);
    printf(conteudoF, "\n");
    fclose(arq);

    arq = fopen(AUXILIAR, "r");
    printf("\nConteudo do arquivo Auxiliar: ");
    fgets(conteudoF2,400,arq);
    printf(conteudoF2, "\n");
    fclose(arq);
return 0;
}

