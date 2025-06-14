#include "buscar.h"
#include <stdio.h>

#include "banco.h"

static void imprimeUsuario(Usuario *u) {
    printf("ID: %d\nNome: %s\nIdade: %d\nSaldo: R$%.2lf\n", u->id, u->nome, u->idade, u->saldo);
}

void buscarUsuario(Banco *banco) {
    int id;
    printf("Digite o ID do usuário a buscar: ");
    scanf("%d", &id);

    Usuario *u = buscaUsuarioPorId(banco, id);

    if (u) {
        printf("\nUsuário encontrado:\n");
        imprimeUsuario(u);
    } else {
        printf("Erro: Usuário %d não encontrado.\n", id);
    }
}