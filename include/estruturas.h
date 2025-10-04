#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// Constantes para limitar o tamanho dos vetores
#define MAX_LIVROS 500
#define MAX_USUARIOS 200
#define MAX_EMPRESTIMOS 1000

// Estrutura para representar uma data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura para representar um Livro (Requisito 1)
typedef struct {
    int codigo;
    char titulo[101];
    char autor[81];
    char editora[61];
    int anoPublicacao;
    int numExemplares;
    int exemplaresDisponiveis; 
    char status[20];
} Livro;

// Estrutura para representar um Usuário (Requisito 2)
typedef struct {
    int matricula;
    char nomeCompleto[101];
    char curso[51];
    char telefone[16];
    Data dataCadastro;
} Usuario;

// Estrutura para representar um Empréstimo (Requisito 3)
typedef struct {
    int codigo;
    int matriculaUsuario;
    int codigoLivro;
    Data dataEmprestimo;
    Data dataDevolucao;
    char status[20]; 
} Emprestimo;

#endif 