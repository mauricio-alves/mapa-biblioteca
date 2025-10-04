#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emprestimo.h"
#include "livro.h"      
#include "usuario.h"   
#include "util.h"

// Realiza um novo empréstimo
void realizarEmprestimo(Emprestimo emprestimos[], int* totalEmprestimos, Livro livros[], int totalLivros, const Usuario usuarios[], int totalUsuarios) {
    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Limite de emprestimos atingido.\n");
        return;
    }

    int matricula, codigoLivro;
    printf("--- Realizar Emprestimo ---\n");
    printf("Digite a matricula do usuario: ");
    scanf("%d", &matricula);

    int idxUsuario = buscarUsuarioPorMatricula(usuarios, totalUsuarios, matricula);
    if (idxUsuario == -1) {
        printf("Erro: Usuario nao encontrado.\n");
        return;
    }

    printf("Digite o codigo do livro: ");
    scanf("%d", &codigoLivro);
    int idxLivro = buscarLivroPorCodigo(livros, totalLivros, codigoLivro);
    if (idxLivro == -1) {
        printf("Erro: Livro nao encontrado.\n");
        return;
    }

    if (livros[idxLivro].exemplaresDisponiveis <= 0) {
        printf("Erro: Nao ha exemplares disponiveis deste livro.\n");
        return;
    }

    Emprestimo novoEmprestimo;
    novoEmprestimo.codigo = *totalEmprestimos + 1;
    novoEmprestimo.matriculaUsuario = matricula;
    novoEmprestimo.codigoLivro = codigoLivro;
    novoEmprestimo.dataEmprestimo = obterDataAtual();
    novoEmprestimo.dataDevolucao = calcularDataDevolucao(novoEmprestimo.dataEmprestimo);
    strcpy(novoEmprestimo.status, "ativo");

    emprestimos[*totalEmprestimos] = novoEmprestimo;
    (*totalEmprestimos)++;
    livros[idxLivro].exemplaresDisponiveis--;

    if (livros[idxLivro].exemplaresDisponiveis == 0) {
        strcpy(livros[idxLivro].status, "emprestado");
    }

    printf("\nEmprestimo realizado com sucesso!\n");
    printf("Devolver ate: %02d/%02d/%d\n", novoEmprestimo.dataDevolucao.dia, novoEmprestimo.dataDevolucao.mes, novoEmprestimo.dataDevolucao.ano);
}

// Realiza a devolução de um empréstimo
void realizarDevolucao(Emprestimo emprestimos[], int totalEmprestimos, Livro livros[], int totalLivros) {
    int codigoEmprestimo;
    printf("--- Realizar Devolucao ---\n");
    printf("Digite o codigo do emprestimo a ser devolvido: ");
    scanf("%d", &codigoEmprestimo);

    int idxEmprestimo = -1;
    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].codigo == codigoEmprestimo && strcmp(emprestimos[i].status, "ativo") == 0) {
            idxEmprestimo = i;
            break;
        }
    }

    if (idxEmprestimo == -1) {
        printf("Erro: Emprestimo ativo nao encontrado com este codigo.\n");
        return;
    }

    strcpy(emprestimos[idxEmprestimo].status, "devolvido");
    
    int idxLivro = buscarLivroPorCodigo(livros, totalLivros, emprestimos[idxEmprestimo].codigoLivro);
    if (idxLivro != -1) {
        if (livros[idxLivro].exemplaresDisponiveis == 0) {
            strcpy(livros[idxLivro].status, "disponivel");
        }
        livros[idxLivro].exemplaresDisponiveis++;
    }

    printf("Devolucao realizada com sucesso!\n");
}

// Lista todos os empréstimos ativos
void listarEmprestimosAtivos(const Emprestimo emprestimos[], int totalEmprestimos, const Usuario usuarios[], int totalUsuarios, const Livro livros[], int totalLivros) {
    printf("--- Lista de Emprestimos Ativos ---\n");
    int count = 0;
    for (int i = 0; i < totalEmprestimos; i++) {
        if (strcmp(emprestimos[i].status, "ativo") == 0) {
            int idxUsuario = buscarUsuarioPorMatricula(usuarios, totalUsuarios, emprestimos[i].matriculaUsuario);
            int idxLivro = buscarLivroPorCodigo(livros, totalLivros, emprestimos[i].codigoLivro);
            
            printf("-------------------------------\n");
            printf("Codigo Emprestimo: %d\n", emprestimos[i].codigo);
            if(idxUsuario != -1) printf("Usuario: %s (%d)\n", usuarios[idxUsuario].nomeCompleto, emprestimos[i].matriculaUsuario);
            if(idxLivro != -1) printf("Livro: %s (%d)\n", livros[idxLivro].titulo, emprestimos[i].codigoLivro);
            printf("Data Devolucao: %02d/%02d/%d\n", emprestimos[i].dataDevolucao.dia, emprestimos[i].dataDevolucao.mes, emprestimos[i].dataDevolucao.ano);
            count++;
        }
    }

    if (count == 0) {
        printf("Nenhum emprestimo ativo no momento.\n");
    }
}

// Renova um empréstimo ativo
void renovarEmprestimo(Emprestimo emprestimos[], int totalEmprestimos) {
    int codigoEmprestimo;
    printf("--- Renovar Emprestimo ---\n");
    printf("Digite o codigo do emprestimo a ser renovado: ");
    scanf("%d", &codigoEmprestimo);

    int idxEmprestimo = -1;
    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].codigo == codigoEmprestimo && strcmp(emprestimos[i].status, "ativo") == 0) {
            idxEmprestimo = i;
            break;
        }
    }

    if (idxEmprestimo == -1) {
        printf("Erro: Emprestimo ativo nao encontrado com este codigo.\n");
        return;
    }

    Data hoje = obterDataAtual();
    if(compararDatas(hoje, emprestimos[idxEmprestimo].dataDevolucao) > 0) {
        printf("Nao e possivel renovar um emprestimo em atraso.\n");
        return;
    }

    emprestimos[idxEmprestimo].dataEmprestimo = hoje;
    emprestimos[idxEmprestimo].dataDevolucao = calcularDataDevolucao(hoje);

    printf("Emprestimo renovado com sucesso! Nova data de devolucao: %02d/%02d/%d\n", 
           emprestimos[idxEmprestimo].dataDevolucao.dia, 
           emprestimos[idxEmprestimo].dataDevolucao.mes, 
           emprestimos[idxEmprestimo].dataDevolucao.ano);
}

// Gera um relatório de usuários com empréstimos em atraso
void relatorioUsuariosComAtraso(const Emprestimo emprestimos[], int totalEmprestimos, const Usuario usuarios[], int totalUsuarios) {
    printf("--- Relatorio de Emprestimos em Atraso ---\n");
    Data hoje = obterDataAtual();
    int count = 0;

    for (int i = 0; i < totalEmprestimos; i++) {
        if (strcmp(emprestimos[i].status, "ativo") == 0 && compararDatas(hoje, emprestimos[i].dataDevolucao) > 0) {
            int idxUsuario = buscarUsuarioPorMatricula(usuarios, totalUsuarios, emprestimos[i].matriculaUsuario);
            if(idxUsuario != -1) {
                printf("Usuario: %s (Matricula: %d) | Devolucao: %02d/%02d/%d\n", 
                       usuarios[idxUsuario].nomeCompleto, 
                       usuarios[idxUsuario].matricula, 
                       emprestimos[i].dataDevolucao.dia,
                       emprestimos[i].dataDevolucao.mes,
                       emprestimos[i].dataDevolucao.ano);
                count++;
            }
        }
    }

    if (count == 0) {
        printf("Nenhum usuario com emprestimos em atraso.\n");
    }
}

// Estrutura para armazenar a contagem de empréstimos por livro
typedef struct {
    int codigoLivro;
    int contagem;
} LivroContagem;

// Função de comparação para o qsort, para ordenar do maior para o menor
int compararContagem(const void* a, const void* b) {
    LivroContagem* livroA = (LivroContagem*)a;
    LivroContagem* livroB = (LivroContagem*)b;
    return (livroB->contagem - livroA->contagem);
}

// Gera um relatório dos livros mais emprestados
void relatorioLivrosMaisEmprestados(const Emprestimo emprestimos[], int totalEmprestimos, const Livro livros[], int totalLivros) {
    if (totalEmprestimos == 0) {
        printf("Nenhum emprestimo foi realizado ainda.\n");
        return;
    }

    LivroContagem contagem[MAX_LIVROS] = {0};
    int totalLivrosUnicos = 0;

    for (int i = 0; i < totalEmprestimos; i++) {
        int codigoAtual = emprestimos[i].codigoLivro;
        int encontrado = 0;
        for (int j = 0; j < totalLivrosUnicos; j++) {
            if (contagem[j].codigoLivro == codigoAtual) {
                contagem[j].contagem++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado && totalLivrosUnicos < MAX_LIVROS) {
            contagem[totalLivrosUnicos].codigoLivro = codigoAtual;
            contagem[totalLivrosUnicos].contagem = 1;
            totalLivrosUnicos++;
        }
    }

    qsort(contagem, totalLivrosUnicos, sizeof(LivroContagem), compararContagem);

    printf("--- Relatorio de Livros Mais Emprestados ---\n");
    int limite = (totalLivrosUnicos < 5) ? totalLivrosUnicos : 5;
    for (int i = 0; i < limite; i++) {
        int idxLivro = buscarLivroPorCodigo(livros, totalLivros, contagem[i].codigoLivro);
        if (idxLivro != -1) {
            printf("%d. Titulo: %s | Emprestimos: %d\n",
                   i + 1,
                   livros[idxLivro].titulo,
                   contagem[i].contagem);
        }
    }
}