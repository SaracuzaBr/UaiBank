cmake_minimum_required(VERSION 3.31)
project(UaiBank2 C)

set(CMAKE_C_STANDARD 11)

add_executable(UaiBank2 Funcoes/code/main.c
        Funcoes/code/inserirUsuario.c
        Funcoes/code/inserirUsuario.h
        Funcoes/code/banco.c
        Funcoes/code/banco.h
        Funcoes/code/buscar.c
        Funcoes/code/buscar.h
        Funcoes/code/transferir.c
        Funcoes/code/transferir.h
        Funcoes/code/remover.c
        Funcoes/code/remover.h
)
