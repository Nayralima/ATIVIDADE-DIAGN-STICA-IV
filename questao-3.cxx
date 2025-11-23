#include <stdio.h>

struct Aluno {
    char nome[30];
    int idade;
    float nota;
};

int main() {
    struct Aluno alunos[5];
    int indice;

    for (int i = 0; i < 5; i++) {
        printf("Cadastro do aluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    printf("Atualizar nota\n");
    printf("Escolha o índice do aluno (0 a 4): ");
    scanf("%d", &indice);

    if (indice < 0 || indice > 4) {
        printf("Inválido!\n");
        return 0;
    }

    printf("Digite a nova nota para %s: ", alunos[indice].nome);
    scanf("%f", &alunos[indice].nota);

    printf("Dados atualizados: \n");
    printf("Aluno %d:\n", indice);
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Idade: %d\n", alunos[indice].idade);
    printf("Nota: %.2f\n", alunos[indice].nota);

    return 0;
}