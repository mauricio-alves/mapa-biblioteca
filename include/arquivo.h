#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "estruturas.h"

// Declarações das funções relacionadas a arquivos
void carregarLivros(Livro livros[], int* totalLivros);
void salvarLivros(const Livro livros[], int totalLivros);

void carregarUsuarios(Usuario usuarios[], int* totalUsuarios);
void salvarUsuarios(const Usuario usuarios[], int totalUsuarios);

void carregarEmprestimos(Emprestimo emprestimos[], int* totalEmprestimos);
void salvarEmprestimos(const Emprestimo emprestimos[], int totalEmprestimos);

void fazerBackup();

#endif