#include "remover.h"
#include "banco.h"
#include <stdio.h>

void removerUsuario(Banco *banco) {
    int id;
    printf("Digite o ID do usuário a remover: ");
    scanf("%d", &id);

    int pos = -1;
    for (int i = 0; i < banco->tamanho; i++) {
        if (banco->usuarios[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Erro: Usuário %d não encontrado.\n", id);
        return;
    }

    for (int i = pos; i < banco->tamanho - 1; i++) {
        banco->usuarios[i] = banco->usuarios[i + 1];
    }
    banco->tamanho--;

    printf("Usuário %d removido com sucesso.\n", id);
    salvaArquivo(banco); // Save after modification
}