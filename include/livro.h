#ifndef LIVRO_H
#define LIVRO_H

#include "estruturas.h"

// Declarações das funções relacionadas a livros
void cadastrarLivro(Livro livros[], int* totalLivros);
void pesquisarLivro(const Livro livros[], int totalLivros);
void listarLivros(const Livro livros[], int totalLivros);
int buscarLivroPorCodigo(const Livro livros[], int totalLivros, int codigo);
void pesquisaAvancadaLivro(const Livro livros[], int totalLivros);

#endif 