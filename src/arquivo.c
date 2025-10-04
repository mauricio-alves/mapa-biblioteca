#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arquivo.h"

// carrega dados de livros, usuários e empréstimos
void carregarLivros(Livro livros[], int* totalLivros) {
    FILE* arquivo = fopen("data/livros.txt", "r");
    if (arquivo == NULL) return;

    *totalLivros = 0;
    while (*totalLivros < MAX_LIVROS &&
           fscanf(arquivo, "%d;%100[^;];%80[^;];%60[^;];%d;%d;%d\n",
                  &livros[*totalLivros].codigo,
                  livros[*totalLivros].titulo,
                  livros[*totalLivros].autor,
                  livros[*totalLivros].editora,
                  &livros[*totalLivros].anoPublicacao,
                  &livros[*totalLivros].numExemplares,
                  &livros[*totalLivros].exemplaresDisponiveis,
                  livros[*totalLivros].status) == 8) {
        (*totalLivros)++;
    }
    fclose(arquivo);
}

// salva dados de livros, usuários e empréstimos
void salvarLivros(const Livro livros[], int totalLivros) {
    FILE* arquivo = fopen("data/livros.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir data/livros.txt para escrita");
        return;
    }
    for (int i = 0; i < totalLivros; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%d;%d;%d\n",
                livros[i].codigo,
                livros[i].titulo,
                livros[i].autor,
                livros[i].editora,
                livros[i].anoPublicacao,
                livros[i].numExemplares,
                livros[i].exemplaresDisponiveis,
                livros[i].status);
    }
    fclose(arquivo);
}

// carrega dados de usuários
void carregarUsuarios(Usuario usuarios[], int* totalUsuarios) {
    FILE* arquivo = fopen("data/usuarios.txt", "r");
    if (arquivo == NULL) return;

    *totalUsuarios = 0;
    while (*totalUsuarios < MAX_USUARIOS &&
           fscanf(arquivo, "%d;%100[^;];%50[^;];%15[^;];%d/%d/%d\n",
                  &usuarios[*totalUsuarios].matricula,
                  usuarios[*totalUsuarios].nomeCompleto,
                  usuarios[*totalUsuarios].curso,
                  usuarios[*totalUsuarios].telefone,
                  &usuarios[*totalUsuarios].dataCadastro.dia,
                  &usuarios[*totalUsuarios].dataCadastro.mes,
                  &usuarios[*totalUsuarios].dataCadastro.ano) == 7) {
        (*totalUsuarios)++;
    }
    fclose(arquivo);
}

// salva dados de usuários
void salvarUsuarios(const Usuario usuarios[], int totalUsuarios) {
    FILE* arquivo = fopen("data/usuarios.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir data/usuarios.txt para escrita");
        return;
    }
    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%d/%d/%d\n",
                usuarios[i].matricula,
                usuarios[i].nomeCompleto,
                usuarios[i].curso,
                usuarios[i].telefone,
                usuarios[i].dataCadastro.dia,
                usuarios[i].dataCadastro.mes,
                usuarios[i].dataCadastro.ano);
    }
    fclose(arquivo);
}

// carrega dados de empréstimos
void carregarEmprestimos(Emprestimo emprestimos[], int* totalEmprestimos) {
    FILE* arquivo = fopen("data/emprestimos.txt", "r");
    if (arquivo == NULL) return;

    *totalEmprestimos = 0;
    while (*totalEmprestimos < MAX_EMPRESTIMOS &&
           fscanf(arquivo, "%d;%d;%d;%d/%d/%d;%d/%d/%d;%19[^\n]\n",
                  &emprestimos[*totalEmprestimos].codigo,
                  &emprestimos[*totalEmprestimos].matriculaUsuario,
                  &emprestimos[*totalEmprestimos].codigoLivro,
                  &emprestimos[*totalEmprestimos].dataEmprestimo.dia,
                  &emprestimos[*totalEmprestimos].dataEmprestimo.mes,
                  &emprestimos[*totalEmprestimos].dataEmprestimo.ano,
                  &emprestimos[*totalEmprestimos].dataDevolucao.dia,
                  &emprestimos[*totalEmprestimos].dataDevolucao.mes,
                  &emprestimos[*totalEmprestimos].dataDevolucao.ano,
                  emprestimos[*totalEmprestimos].status) == 10) {
        (*totalEmprestimos)++;
    }
    fclose(arquivo);
}

// salva dados de empréstimos
void salvarEmprestimos(const Emprestimo emprestimos[], int totalEmprestimos) {
    FILE* arquivo = fopen("data/emprestimos.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir data/emprestimos.txt para escrita");
        return;
    }
    for (int i = 0; i < totalEmprestimos; i++) {
        fprintf(arquivo, "%d;%d;%d;%d/%d/%d;%d/%d/%d;%s\n",
                emprestimos[i].codigo,
                emprestimos[i].matriculaUsuario,
                emprestimos[i].codigoLivro,
                emprestimos[i].dataEmprestimo.dia,
                emprestimos[i].dataEmprestimo.mes,
                emprestimos[i].dataEmprestimo.ano,
                emprestimos[i].dataDevolucao.dia,
                emprestimos[i].dataDevolucao.mes,
                emprestimos[i].dataDevolucao.ano,
                emprestimos[i].status);
    }
    fclose(arquivo);
}

// Realiza um backup dos arquivos de dados
void fazerBackup() {
    printf("Realizando backup dos dados...\n");
    system("if exist data\\livros.txt copy data\\livros.txt data\\livros.bak > NUL 2>&1");
    system("if exist data\\usuarios.txt copy data\\usuarios.txt data\\usuarios.bak > NUL 2>&1");
    system("if exist data\\emprestimos.txt copy data\\emprestimos.txt data\\emprestimos.bak > NUL 2>&1");
    printf("Backup concluido.\n");
}