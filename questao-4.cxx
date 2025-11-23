#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 4

typedef struct {
    char nome[30];
    int idade;
    float nota;
} Aluno;

int total_alunos = 0;

void exibirMenu() {
    printf("Menu de gereciamento alunos\n");
    printf("1. Inserir novo aluno\n");
    printf("2. Remover Aluno\n");
    printf("3. Exibir Todos os Alunos\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

void inserirAluno(Aluno turma[]) {
    if (total_alunos >= MAX_ALUNOS) {
        printf("Capacidade maxima de %d alunos atingida.\n", MAX_ALUNOS);
        return;
    }

    int i = total_alunos;
    printf("Inserir novo aluno\n");
    printf("Nome: ");
    getchar();
    if (fgets(turma[i].nome, 50, stdin) != NULL) {
         turma[i].nome[strcspn(turma[i].nome, "\n")] = 0;
    }

    printf("Idade: ");
    scanf("%d", &turma[i].idade);

    printf("Nota: ");
    scanf("%f", &turma[i].nota);

    total_alunos++;
    printf(" Aluno '%s' inserido na posicao %d.\n", turma[i].nome, total_alunos);
}

void removerAluno(Aluno turma[]) {
    if (total_alunos == 0) {
        printf(" Não tem alunos para remover.\n");
        return;
    }

    int posicao, idx;
    printf("Remover aluno ---\n");
    printf("Digite a posicao do aluno a remover (1 a %d): ", total_alunos);
    scanf("%d", &posicao);

    idx = posicao - 1;

    if (idx < 0 || idx >= total_alunos) {
        printf("Posição invalida.\n");
        return;
    }

    printf("Removendo aluno: %s...\n", turma[idx].nome);

    for (int i = idx; i < total_alunos - 1; i++) {
        turma[i] = turma[i+1];
    }

    total_alunos--;
    printf("Aluno removido com sucesso.\n");
}

void exibirAlunos(Aluno turma[]) {
    if (total_alunos == 0) {
        printf(" Lista Vazia. Não tem alunos cadastrados.\n");
        return;
    }

    printf("Lista de Alunos (%d/%d) \n", total_alunos, MAX_ALUNOS);
    printf("Pos | Nome                  | Idade | Nota\n");
    
    for (int i = 0; i < total_alunos; i++) {
        printf("%3d | %-20s| %5d | %.2f\n", i + 1, turma[i].nome, turma[i].idade, turma[i].nota);
    }
}

int main() {
    Aluno turma[MAX_ALUNOS];
    int opcao;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            while(getchar() != '\n');
            opcao = 0;
            printf("Opcao invalida. Tente novamente.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                inserirAluno(turma);
                break;
            case 2:
                removerAluno(turma);
                break;
            case 3:
                exibirAlunos(turma);
                break;
            case 4:
                printf(" Encerrando o programa!\n");
                exit(0);
            default:
                printf("Opção invalida\n");
        }
    } while (opcao != 4);

    return 0;
}

