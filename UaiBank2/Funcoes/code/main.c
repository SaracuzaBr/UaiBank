#include <stdlib.h>
#include <stdio.h>
#include "banco.h"

void menu() {
    printf("\n=== Menu Uaibank ===\n");
    printf("1 - Inserir um usuário\n");
    printf("2 - Inserir vários usuários\n");
    printf("3 - Buscar um usuário por ID\n");
    printf("4 - Transferir valor entre usuários\n");
    printf("5 - Remover um usuário por ID\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {

#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    Banco banco;
    inicializaBanco(&banco);
    carregaArquivo(&banco);

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: inserirUsuario(&banco); break;
            case 2: inserirVariosUsuarios(&banco); break;
            case 3: buscarUsuario(&banco); break;
            case 4: transferirValor(&banco); break;
            case 5: removerUsuario(&banco); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    liberaBanco(&banco);
    return 0;
}