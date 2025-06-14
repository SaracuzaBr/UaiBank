#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaBanco(Banco *banco) {
    banco->usuarios = NULL;
    banco->tamanho = 0;
    banco->capacidade = 0;
    banco->proximo_id = 1;
}

void liberaBanco(Banco *banco) {
    free(banco->usuarios);
    banco->usuarios = NULL;
    banco->tamanho = 0;
    banco->capacidade = 0;
}

void salvaArquivo(Banco *banco) {
    FILE *fp = fopen(ARQUIVO, "w");
    if (!fp) {
        perror("Erro ao abrir arquivo para salvar.");
        return;
    }
    for (int i = 0; i < banco->tamanho; i++) {
        fprintf(fp, "%s, %d, %.2lf\n",
                banco->usuarios[i].nome,
                banco->usuarios[i].idade,
                banco->usuarios[i].saldo);
    }
    fclose(fp);
}

void carregaArquivo(Banco *banco) {
    FILE *fp = fopen(ARQUIVO, "r");
    if (!fp) return; // File may not exist on first run, which is fine

    char linha[256];
    while (fgets(linha, sizeof(linha), fp)) {
        if (banco->tamanho == banco->capacidade) {
            banco->capacidade = (banco->capacidade == 0) ? 2 : banco->capacidade * 2;
            banco->usuarios = realloc(banco->usuarios, banco->capacidade * sizeof(Usuario));
        }
        Usuario *u = &banco->usuarios[banco->tamanho];
        if (sscanf(linha, " %99[^,], %d, %lf", u->nome, &u->idade, &u->saldo) == 3) {
            u->id = banco->proximo_id++;
            banco->tamanho++;
        }
    }
    fclose(fp);
}

Usuario* buscaUsuarioPorId(Banco *banco, int id) {
    for (int i = 0; i < banco->tamanho; i++) {
        if (banco->usuarios[i].id == id) {
            return &banco->usuarios[i];
        }
    }
    return NULL;
}