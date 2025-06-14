#include "banco.h"
#include <stdio.h>

void transferirValor(Banco *banco) {
    int id_origem, id_destino;
    double quantia;

    printf("Digite o ID do usuário de origem: ");
    scanf("%d", &id_origem);
    printf("Digite o ID do usuário de destino: ");
    scanf("%d", &id_destino);
    printf("Digite a quantia a transferir: ");
    scanf("%lf", &quantia);

    if (quantia <= 0) {
        printf("Erro: Quantia deve ser positiva.\n");
        return;
    }

    Usuario *origem = buscaUsuarioPorId(banco, id_origem);
    Usuario *destino = buscaUsuarioPorId(banco, id_destino);

    if (!origem) {
        printf("Erro: Usuário de origem %d não encontrado.\n", id_origem);
        return;
    }
    if (!destino) {
        printf("Erro: Usuário de destino %d não encontrado.\n", id_destino);
        return;
    }
    if (origem->saldo < quantia) {
        printf("Erro: Saldo insuficiente no usuário de origem.\n");
        return;
    }

    origem->saldo -= quantia;
    destino->saldo += quantia;

    printf("Transferência realizada com sucesso.\n");
    salvaArquivo(banco); // Save after modification
}