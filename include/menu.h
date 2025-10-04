#ifndef MENU_H
#define MENU_H

#include "estruturas.h"

// Declarações das funções relacionadas ao menu
int menuPrincipal();
void menuGestaoLivros(Livro livros[], int* totalLivros);
void menuGestaoUsuarios(Usuario usuarios[], int* totalUsuarios);
void menuGestaoEmprestimos(Emprestimo emprestimos[], int* totalEmprestimos, Livro livros[], int totalLivros, Usuario usuarios[], int totalUsuarios);
void menuRelatorios(const Emprestimo emprestimos[], int totalEmprestimos, const Usuario usuarios[], int totalUsuarios, const Livro livros[], int totalLivros);

#endif