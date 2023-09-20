#include <iostream>
#include <string.h>
#include <stdio.h>

#define LIMITVET 50
#define LIMITALUNO 10

using namespace std;

typedef struct Nota
{
    int nota1;
    int nota2;
    int nota3;
    int nota4;
} nota;

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Disciplina
{
    int codigo;  // Primary Key
    char nome[LIMITVET];
    int ch;// Carga horaria
} Disciplina;

typedef struct Aluno
{
    int matricula; // Primary Key
    char nome[LIMITVET];
    Data dataNascimento;
} Aluno;

typedef struct Turma
{
    Disciplina disCodigo;        // Primary Key
    Aluno alunoMatricula;
    int ano;
    Nota notas;
    int media;
    char situacao[LIMITVET];
    int faltas;
} Turma;

// ################################# INICIO DAS FUN합ES ALUNO ###########################################

void menuAluno(Aluno *listaAlunos, int *qntAlunos);
void cadastrarAluno(Aluno *listaAlunos, int *qntAlunos);
void exibirAluno (Aluno listaAlunos);
void exibirListaAluno(Aluno *listaAlunos, int qntAlunos);
void excluirAluno(Aluno *listaAlunos, int *qntAlunos);
void atualizarAluno();

void atualizarAluno(){


}

int buscarPosicaoAluno(Aluno *listaAlunos, int qntAlunos, int matricula){
    for (int i = 0; i < qntAlunos; i++) {
        if (listaAlunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

void excluirAluno(Aluno *listaAlunos, int *qntAlunos){
    int matricula;

    system("cls");
    fflush(stdin);

    cout << "Digite a matricula do cliente que deseja excluir: ";
    cin >> matricula;

    int posicao = buscarPosicaoAluno(listaAlunos, *qntAlunos, matricula);
    if (posicao != -1) {
        for (int i = posicao; i < *qntAlunos - 1; i++) {
            listaAlunos[i] = listaAlunos[i + 1];
        }
        (*qntAlunos)--;
        system("cls");
    } else {
        cout << "\nAluno nao encontrado!\n\n";
    }
}

void exibirAluno(Aluno listaAluno){
    cout << "------------------------------------------------------------------------------------------\n";
    cout << "Matricula: " << listaAluno.matricula << endl;
    cout << "Nome: " << listaAluno.nome << endl;
    cout << "Data de nascimento: ";
    cout << listaAluno.dataNascimento.dia << "/"<< listaAluno.dataNascimento.mes<<"/"<<listaAluno.dataNascimento.ano;
    cout << "\n------------------------------------------------------------------------------------------\n";

}

void exibirListaAluno(Aluno *listaAlunos, int qntAlunos){
    for (int i = 1; i < qntAlunos; i++){
        exibirAluno(listaAlunos[i]);
    }
}

void cadastrarAluno(Aluno *listaAluno, int *qntAlunos){

    int sair=0;

    system("cls");
    while (sair != 1){
    if (*qntAlunos<LIMITALUNO){
            cout << "Informe o nome do ALuno: \n";
            cin.ignore();
            cin.getline(listaAluno[*qntAlunos].nome, 50);
            cout << "Nome cadastrado\n";
            cout << "Digite o dia do nascimento: ";
            cin >> listaAluno[*qntAlunos].dataNascimento.dia;
            cout << "\nDigite o mes do nascimento: ";
            cin >> listaAluno[*qntAlunos].dataNascimento.mes;
            cout << "\nDigite o ano do nascimento: ";
            cin >> listaAluno[*qntAlunos].dataNascimento.ano;
            cout << "Data cadastrada\n";
            cout << "Gerando Matricula\n";
            listaAluno[*qntAlunos].matricula = *qntAlunos + 100;
            cout << "...\n";
            cout << "Matricula gerada\n";
            cout << "Obrigado\n";
            (*qntAlunos)++;
            sair = 1;


    } else {
        cout << "\nNumero maximo de Alunos Cadastrados\n";
        sair = 1;
    }

}

}

void menuAluno(Aluno *listaAlunos, int *qntAlunos){

    int opcaomenu;
    int posicao = 0;
    system("cls");
    while (opcaomenu != 4) {
        fflush(stdin);
        cout << "Bem vindo ao Menu Aluno \n";
        cout << "Selecione alguma das opcoes a seguir: \n";
        cout << "1 - Cadastrar Aluno \n";
        cout << "2 - Editar Aluno \n";
        cout << "3 - Excluir Atendimento \n";
        cout << "4 - Voltar ao Menu principal \n";
        cin >> opcaomenu;

        switch (opcaomenu) {
            case 1:
                cadastrarAluno(listaAlunos, qntAlunos);
                break;
            case 2:
                break;
            case 3:
                excluirAluno(listaAlunos, qntAlunos);
                break;
            case 4:
                system("cls");
                cout << "\n\nAte a proxima!\n\n";
                break;
            default:
                system("cls");
                cout << "Opcao Invalida\n\n";
                break;
        }
}
}

// ################################# FIM DAS FUN합ES ALUNO ###########################################

// ################################# INICIO DAS FUN합ES Disciplina ###########################################
void menuDisciplina(Disciplina *listaDisciplina, int *qntDisciplina);
void cadastrarDisciplina(Disciplina *listaDisciplina, int *qntDisciplina);

void cadastrarDisciplina(Disciplina *listaDisciplina, int *qntDisciplina){
    int sair=0;

    system("cls");
    while (sair != 1){
    if (*qntDisciplina<LIMITALUNO){
            cout << "Informe o nome da Disciplina: \n";
            cin.ignore();
            cin.getline(listaDisciplina[*qntDisciplina].nome, 50);
            cout << "Nome cadastrado\n";
            cout << "Digite a Carga horaria 'valor numerico': ";
            cin >> listaDisciplina[*qntDisciplina].ch;
            cout << "Carga Horaria cadastrada\n";
            cout << "Gerando Matricula\n";
            listaDisciplina[*qntDisciplina].codigo = *qntDisciplina + 10;
            cout << "...\n";
            cout << "Codigo gerada\n";
            cout << "Obrigado\n";
            (*qntDisciplina)++;
            sair = 1;
    } else {
        cout << "\nNumero maximo de Disciplinas Cadastradas\n";
        sair = 1;
    }

}

}

void menuDisciplina(Disciplina *listaDisciplina, int *qntDisciplina){
    int opcaomenu;
        int posicao = 0;
        system("cls");
        while (opcaomenu != 4) {
            fflush(stdin);
            cout << "Bem vindo ao Menu Disciplina \n";
            cout << "Selecione alguma das opcoes a seguir: \n";
            cout << "1 - Cadastrar Disciplina \n";
            cout << "2 - Editar Disciplina \n";
            cout << "3 - Excluir Disciplina \n";
            cout << "4 - Voltar ao Menu principal \n";
            cin >> opcaomenu;

            switch (opcaomenu) {
                case 1:
                    cadastrarDisciplina(listaDisciplina, qntDisciplina);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    system("cls");
                    cout << "\n\nAte a proxima!\n\n";
                    break;
                default:
                    system("cls");
                    cout << "Opcao Invalida\n\n";
                    break;
            }
    }

}
// ################################# FIM DAS FUN합ES Disciplina ###########################################

// ################################# INICIO DAS FUN합ES Turma ###########################################
void menuTurma(Turma *listaTurma, int *qntTurma);
void cadastrarTurma(Turma *listaTurma, int *qntTutma);

void cadastrarTurma(Turma *listaTurma, int *qntTutma){

}

void menuTurma(Turma *listaTurma, int *qntTurma){
    int opcaomenu;
        int posicao = 0;
        system("cls");
        while (opcaomenu != 4) {
            fflush(stdin);
            cout << "Bem vindo ao Menu Turma \n";
            cout << "Selecione alguma das opcoes a seguir: \n";
            cout << "1 - Cadastrar Turma \n";
            cout << "2 - Editar Turma \n";
            cout << "3 - Excluir Turma \n";
            cout << "4 - Voltar ao Menu principal \n";
            cin >> opcaomenu;

            switch (opcaomenu) {
                case 1:
                    cadastrarTurma(listaTurma, qntTurma);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    system("cls");
                    cout << "\n\nAte a proxima!\n\n";
                    break;
                default:
                    system("cls");
                    cout << "Opcao Invalida\n\n";
                    break;
            }
    }

}
// ################################# FIM DAS FUN합ES Turma ###########################################


int main (){

int opcao, qntAlunos = 1, qntDisciplina = 1, qntTurma = 1;
Aluno listaAlunos[LIMITVET];
Disciplina listaDisciplina[LIMITVET];
Turma listaTurma [LIMITVET];

    while (opcao != 5)
    {
        fflush(stdin);
        cout << "1 - Menu de Disciplina" << endl;
        cout << "2 - Menu de Aluno" << endl;
        cout << "3 - Menu de Turma" << endl;
        cout << "4 - Relatorio" << endl;
        cout << "5 - Sair" << endl;

        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            menuDisciplina(listaDisciplina, &qntDisciplina);
            break;
        case 2:
            menuAluno(listaAlunos, &qntAlunos);
            break;
        case 3:
            menuTurma(listaTurma, &qntTurma);
            break;
        case 4:
            system("cls");
            exibirListaAluno(listaAlunos, qntAlunos);
            break;
        case 5:
            cout << "\n\nAte a proxima!\n\n";
            break;
        default:
            system("cls");
            cout << "Opcao invalida, tente novamente!\n\n";
        }
    }


}
