#include <stdio.h>
#include "../include/estruturas.h"
#include "../include/arquivo.h"
#include "../include/menu.h"
#include "../include/util.h"

int main() {
    // Vetores para armazenar todos os dados em memória
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    Emprestimo emprestimos[MAX_EMPRESTIMOS];

    // Contadores para o número de registros em cada vetor
    int totalLivros = 0;
    int totalUsuarios = 0;
    int totalEmprestimos = 0;

    // Carrega os dados dos arquivos para a memória ao iniciar
    carregarLivros(livros, &totalLivros);
    carregarUsuarios(usuarios, &totalUsuarios);
    carregarEmprestimos(emprestimos, &totalEmprestimos);

    int opcao;
    do {
        opcao = menuPrincipal();

        switch (opcao) {
            case 1:
                menuGestaoLivros(livros, &totalLivros);
                break;
            case 2:
                menuGestaoUsuarios(usuarios, &totalUsuarios);
                break;
            case 3:
                menuGestaoEmprestimos(emprestimos, &totalEmprestimos, livros, totalLivros, usuarios, totalUsuarios);
                break;
            case 4:
                menuRelatorios(emprestimos, totalEmprestimos, usuarios, totalUsuarios, livros, totalLivros);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pressioneEnterParaContinuar();
        }

    } while (opcao != 0);

    // Salva todos os dados de volta para os arquivos antes de fechar
    salvarLivros(livros, totalLivros);
    salvarUsuarios(usuarios, totalUsuarios);
    salvarEmprestimos(emprestimos, totalEmprestimos);

    // Realiza o backup automático
    fazerBackup();

    printf("Sistema finalizado. Ate logo!\n");

    return 0;
}