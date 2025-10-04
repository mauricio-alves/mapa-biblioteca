#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "estruturas.h"

// Declarações das funções relacionadas a empréstimos de livros
void realizarEmprestimo(Emprestimo emprestimos[], int* totalEmprestimos, Livro livros[], int totalLivros, const Usuario usuarios[], int totalUsuarios);
void realizarDevolucao(Emprestimo emprestimos[], int totalEmprestimos, Livro livros[], int totalLivros);
void listarEmprestimosAtivos(const Emprestimo emprestimos[], int totalEmprestimos, const Usuario usuarios[], int totalUsuarios, const Livro livros[], int totalLivros);
void renovarEmprestimo(Emprestimo emprestimos[], int totalEmprestimos);
void relatorioUsuariosComAtraso(const Emprestimo emprestimos[], int totalEmprestimos, const Usuario usuarios[], int totalUsuarios);
void relatorioLivrosMaisEmprestados(const Emprestimo emprestimos[], int totalEmprestimos, const Livro livros[], int totalLivros);

#endif 