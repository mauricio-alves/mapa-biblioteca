#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "util.h"

// Busca um usuário pelo número de matrícula
int buscarUsuarioPorMatricula(const Usuario usuarios[], int totalUsuarios, int matricula) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

// Cadastra um novo usuário
void cadastrarUsuario(Usuario usuarios[], int* totalUsuarios) {
    if (*totalUsuarios >= MAX_USUARIOS) {
        printf("Limite maximo de usuarios cadastrados atingido!\n");
        return;
    }

    Usuario novoUsuario;
    printf("--- Cadastro de Novo Usuario ---\n");
    printf("Matricula: ");
    scanf("%d", &novoUsuario.matricula);

    if (buscarUsuarioPorMatricula(usuarios, *totalUsuarios, novoUsuario.matricula) != -1) {
        printf("Erro: Ja existe um usuario com esta matricula.\n");
        return;
    }

    printf("Nome Completo: ");
    scanf(" %[^\n]", novoUsuario.nomeCompleto);
    printf("Curso: ");
    scanf(" %[^\n]", novoUsuario.curso);
    printf("Telefone: ");
    scanf(" %[^\n]", novoUsuario.telefone);
    
    novoUsuario.dataCadastro = obterDataAtual();

    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("\nUsuario cadastrado com sucesso!\n");
}

// Pesquisa usuários por matrícula ou nome
void pesquisarUsuario(const Usuario usuarios[], int totalUsuarios) {
    int opcao;
    printf("--- Pesquisar Usuario ---\n");
    printf("1. Por Matricula\n");
    printf("2. Por Nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    int encontrados = 0;
    switch(opcao) {
        case 1: {
            int matricula;
            printf("Digite a matricula: ");
            scanf("%d", &matricula);
            int index = buscarUsuarioPorMatricula(usuarios, totalUsuarios, matricula);
            if (index != -1) {
                printf("\nUsuario Encontrado:\n");
                printf("Matricula: %d\nNome: %s\nCurso: %s\n",
                       usuarios[index].matricula, usuarios[index].nomeCompleto, usuarios[index].curso);
                encontrados++;
            }
            break;
        }
        case 2: {
            char nomeBusca[101];
            printf("Digite o nome (ou parte dele): ");
            scanf(" %[^\n]", nomeBusca);
            printf("\nResultados para \"%s\":\n", nomeBusca);
            for (int i = 0; i < totalUsuarios; i++) {
                if (strstr(usuarios[i].nomeCompleto, nomeBusca) != NULL) {
                    printf("Matricula: %d | Nome: %s\n",
                           usuarios[i].matricula, usuarios[i].nomeCompleto);
                    encontrados++;
                }
            }
            break;
        }
        default:
            printf("Opcao invalida!\n");
    }

    if (encontrados == 0) {
        printf("Nenhum usuario encontrado.\n");
    }
}

// Lista todos os usuários cadastrados
void listarUsuarios(const Usuario usuarios[], int totalUsuarios) {
    printf("--- Lista de Todos os Usuarios ---\n");
    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalUsuarios; i++) {
        printf("----------------------------------\n");
        printf("Matricula: %d\n", usuarios[i].matricula);
        printf("Nome: %s\n", usuarios[i].nomeCompleto);
        printf("Curso: %s\n", usuarios[i].curso);
    }
    printf("----------------------------------\n");
}