#include <stdio.h>
#include "menu.h"
#include "util.h"
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

// Exibe o menu principal e retorna a opção escolhida
int menuPrincipal() {
    int opcao;
    limparTela();
    printf("========================================\n");
    printf("   SISTEMA DE GERENCIAMENTO DE BIBLIOTECA\n");
    printf("========================================\n");
    printf("1. Gestao de Livros\n");
    printf("2. Gestao de Usuarios\n");
    printf("3. Gestao de Emprestimos\n");
    printf("4. Relatorios\n");
    printf("0. Sair\n");
    printf("----------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Menu de gestão de livros
void menuGestaoLivros(Livro livros[], int* totalLivros) {
    int opcao;
    do {
        limparTela();
        printf("--- Gestao de Livros ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Pesquisar Livro\n");
        printf("3. Listar todos os Livros\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarLivro(livros, totalLivros); break;
            case 2: pesquisarLivro(livros, *totalLivros); break;
            case 3: listarLivros(livros, *totalLivros); break;
            case 0: return;
            default: printf("Opcao invalida!\n");
        }
        pressioneEnterParaContinuar();
    } while (opcao != 0);
}

// Menu de gestão de usuários
void menuGestaoUsuarios(Usuario usuarios[], int* totalUsuarios) {
    int opcao;
    do {
        limparTela();
        printf("--- Gestao de Usuarios ---\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Pesquisar Usuario\n");
        printf("3. Listar todos os Usuarios\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarUsuario(usuarios, totalUsuarios); break;
            case 2: pesquisarUsuario(usuarios, *totalUsuarios); break;
            case 3: listarUsuarios(usuarios, *totalUsuarios); break;
            case 0: return;
            default: printf("Opcao invalida!\n");
        }
        pressioneEnterParaContinuar();
    } while (opcao != 0);
}

// Menu de gestão de empréstimos
void menuGestaoEmprestimos(Emprestimo emprestimos[], int* totalEmprestimos, Livro livros[], int totalLivros, Usuario usuarios[], int totalUsuarios) {
    int opcao;
    do {
        limparTela();
        printf("--- Gestao de Emprestimos ---\n");
        printf("1. Realizar Emprestimo\n");
        printf("2. Realizar Devolucao\n");
        printf("3. Renovar Emprestimo\n");
        printf("4. Listar Emprestimos Ativos\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: realizarEmprestimo(emprestimos, totalEmprestimos, livros, totalLivros, usuarios, totalUsuarios); break;
            case 2: realizarDevolucao(emprestimos, *totalEmprestimos, livros, totalLivros); break;
            case 3: renovarEmprestimo(emprestimos, *totalEmprestimos); break;
            case 4: listarEmprestimosAtivos(emprestimos, *totalEmprestimos, usuarios, totalUsuarios, livros, totalLivros); break;
            case 0: return;
            default: printf("Opcao invalida!\n");
        }
        pressioneEnterParaContinuar();
    } while (opcao != 0);
}

// Menu de relatórios
void menuRelatorios(const Emprestimo emprestimos[], int totalEmprestimos, const Usuario usuarios[], int totalUsuarios, const Livro livros[], int totalLivros) {
    int opcao;
    do {
        limparTela();
        printf("--- Menu de Relatorios ---\n");
        printf("1. Usuarios com Emprestimos em Atraso\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: relatorioUsuariosComAtraso(emprestimos, totalEmprestimos, usuarios, totalUsuarios); break;
            case 0: return;
            default: printf("Opcao invalida!\n");
        }
        pressioneEnterParaContinuar();
    } while(opcao != 0);
}