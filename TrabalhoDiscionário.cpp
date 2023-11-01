void exibirMensagem (char *frase){
    int tamanho = strlen(frase);

    for (int i=4; i<=tamanho+9;i++){
        gotoxy(i,3);printf("%c", 196);
    }
    gotoxy(7,5);cout<<frase<< endl;
    gotoxy(3,3); printf("%c", 218);
    for (int j = 4; j<=6; j++){
        gotoxy(3,j); printf("%c", 179);
    }
    gotoxy(3,7); printf("%c", 192);
    for (int c=4; c<=tamanho+9;c++){
        gotoxy(c,7);printf("%c", 196);
    }
    gotoxy(tamanho+10,3);printf("%c", 191);
    gotoxy(tamanho+10,7);printf("%c", 217);
    for (int d = 4; d<=6; d++){
        gotoxy(tamanho+10,d); printf("%c", 179);
    }

    gotoxy(2,9);system("pause");
}
