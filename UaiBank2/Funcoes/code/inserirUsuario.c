#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define ARQUIVO "usuarios.txt"

#include "banco.h"

void inserirUsuario(Banco *banco) {
    if (banco->tamanho == banco->capacidade) {
        banco->capacidade = (banco->capacidade == 0) ? 2 : banco->capacidade * 2;
        banco->usuarios = realloc(banco->usuarios, banco->capacidade * sizeof(Usuario));
        if (!banco->usuarios) {
            printf("Erro de alocação de memória.\n");
            exit(1);
        }
    }
    Usuario *u = &banco->usuarios[banco->tamanho];
    u->id = banco->proximo_id++;

    printf("Digite o nome (max 100 chars): ");
    getchar(); // Clear input buffer before reading string
    fgets(u->nome, MAX_NOME, stdin);
    u->nome[strcspn(u->nome, "\n")] = 0; // Remove trailing newline

    printf("Digite a idade: ");
    scanf("%d", &u->idade);

    do {
        printf("Digite o saldo inicial (>=0): ");
        scanf("%lf", &u->saldo);
        if (u->saldo < 0) {
            printf("Saldo não pode ser negativo.\n");
        }
    } while (u->saldo < 0);

    banco->tamanho++;
    printf("Usuário inserido com id %d.\n", u->id);
    salvaArquivo(banco); // Save after modification
}

void inserirVariosUsuarios(Banco *banco) {
    int qtd;
    printf("Digite a quantidade de usuários a inserir: ");
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++) {
        printf("\n--- Inserindo Usuário %d de %d ---\n", i + 1, qtd);
        inserirUsuario(banco); // Reuse the single insert function
    }
}