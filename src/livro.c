#include <stdio.h>
#include <string.h>
#include "livro.h"
#include "util.h"

// Busca um livro pelo código e retorna seu índice no vetor
int buscarLivroPorCodigo(const Livro livros[], int totalLivros, int codigo) {
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Cadastra um novo livro
void cadastrarLivro(Livro livros[], int* totalLivros) {
    if (*totalLivros >= MAX_LIVROS) {
        printf("Limite maximo de livros cadastrados atingido!\n");
        return;
    }

    Livro novoLivro;
    printf("--- Cadastro de Novo Livro ---\n");
    printf("Codigo: ");
    scanf("%d", &novoLivro.codigo);
    
    if (buscarLivroPorCodigo(livros, *totalLivros, novoLivro.codigo) != -1) {
        printf("Erro: Ja existe um livro com este codigo.\n");
        return;
    }

    printf("Titulo: ");
    scanf(" %[^\n]", novoLivro.titulo);
    printf("Autor: ");
    scanf(" %[^\n]", novoLivro.autor);
    printf("Editora: ");
    scanf(" %[^\n]", novoLivro.editora);
    printf("Ano de Publicacao: ");
    scanf("%d", &novoLivro.anoPublicacao);
    printf("Numero de Exemplares: ");
    scanf("%d", &novoLivro.numExemplares);

    novoLivro.exemplaresDisponiveis = novoLivro.numExemplares;
    strcpy(novoLivro.status, "disponivel");

    livros[*totalLivros] = novoLivro;
    (*totalLivros)++;
    
    printf("\nLivro cadastrado com sucesso!\n");
}

// Pesquisa livros por código, título ou autor
void pesquisarLivro(const Livro livros[], int totalLivros) {
    int opcao;
    printf("--- Pesquisar Livro ---\n");
    printf("1. Por Codigo\n");
    printf("2. Por Titulo\n");
    printf("3. Por Autor\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    int encontrados = 0;
    switch (opcao) {
        case 1: {
            int codigo;
            printf("Digite o codigo: ");
            scanf("%d", &codigo);
            int index = buscarLivroPorCodigo(livros, totalLivros, codigo);
            if (index != -1) {
                printf("\nLivro Encontrado:\n");
                printf("Codigo: %d\nTitulo: %s\nAutor: %s\nDisponiveis: %d/%d\n",
                       livros[index].codigo, livros[index].titulo, livros[index].autor,
                       livros[index].exemplaresDisponiveis, livros[index].numExemplares);
                encontrados++;
            }
            break;
        }
        case 2: {
            char tituloBusca[101];
            printf("Digite o titulo (ou parte dele): ");
            scanf(" %[^\n]", tituloBusca);
            printf("\nResultados para \"%s\":\n", tituloBusca);
            for (int i = 0; i < totalLivros; i++) {
                if (strstr(livros[i].titulo, tituloBusca) != NULL) {
                     printf("Codigo: %d | Titulo: %s | Autor: %s\n",
                           livros[i].codigo, livros[i].titulo, livros[i].autor);
                     encontrados++;
                }
            }
            break;
        }
        case 3: {
            char autorBusca[81];
            printf("Digite o autor (ou parte do nome): ");
            scanf(" %[^\n]", autorBusca);
            printf("\nResultados para \"%s\":\n", autorBusca);
            for (int i = 0; i < totalLivros; i++) {
                if (strstr(livros[i].autor, autorBusca) != NULL) {
                     printf("Codigo: %d | Titulo: %s | Autor: %s\n",
                           livros[i].codigo, livros[i].titulo, livros[i].autor);
                     encontrados++;
                }
            }
            break;
        }
        default:
            printf("Opcao invalida!\n");
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com o criterio informado.\n");
    }
}

// Lista todos os livros cadastrados
void listarLivros(const Livro livros[], int totalLivros) {
    printf("--- Lista de Todos os Livros ---\n");
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalLivros; i++) {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", livros[i].codigo);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Status: %s\n", livros[i].status);
        printf("Disponiveis: %d de %d\n", livros[i].exemplaresDisponiveis, livros[i].numExemplares);
    }
    printf("----------------------------------\n");
}

// Pesquisa avançada de livros por múltiplos critérios
void pesquisaAvancadaLivro(const Livro livros[], int totalLivros) {
    char autorBusca[81];
    int anoBusca = 0; 
    int encontrados = 0;

    printf("--- Busca Avancada de Livros ---\n");
    printf("Deixe em branco (pressione Enter) para ignorar um criterio.\n\n");

    printf("Digite o autor (ou parte do nome): ");
    fgets(autorBusca, sizeof(autorBusca), stdin);
    if (strchr(autorBusca, '\n') == NULL) while (getchar() != '\n');
    autorBusca[strcspn(autorBusca, "\n")] = 0; 

    printf("Digite o ano de publicacao (ou 0 para ignorar): ");
    scanf("%d", &anoBusca);

    printf("\n--- Resultados da Busca Avancada ---\n");
    for (int i = 0; i < totalLivros; i++) {
        int atendeAutor = (strlen(autorBusca) == 0) || (strstr(livros[i].autor, autorBusca) != NULL);
        int atendeAno = (anoBusca == 0) || (livros[i].anoPublicacao == anoBusca);

        if (atendeAutor && atendeAno) {
            printf("Codigo: %d | Titulo: %s | Autor: %s | Ano: %d\n",
                   livros[i].codigo, livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com os criterios informados.\n");
    }
}