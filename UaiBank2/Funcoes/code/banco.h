
#ifndef BANCO_H
#define BANCO_H

#define MAX_NOME 100
#define ARQUIVO "usuarios.txt"


typedef struct {
    int id;
    char nome[MAX_NOME];
    int idade;
    double saldo;
} Usuario;

typedef struct {
    Usuario *usuarios;
    int tamanho;
    int capacidade;
    int proximo_id;
} Banco;

void inicializaBanco(Banco *banco);
void liberaBanco(Banco *banco);
void salvaArquivo(Banco *banco);
void carregaArquivo(Banco *banco);
Usuario* buscaUsuarioPorId(Banco *banco, int id);

void inserirUsuario(Banco *banco);
void inserirVariosUsuarios(Banco *banco);
void buscarUsuario(Banco *banco);
void transferirValor(Banco *banco);
void removerUsuario(Banco *banco);

#endif