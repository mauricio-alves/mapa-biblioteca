#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

// Limpa a tela do console
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pausa a execução até o usuário pressionar Enter
void pressioneEnterParaContinuar() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); 
    getchar();
}

// Retorna a data atual do sistema
Data obterDataAtual() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    Data data;
    data.dia = tm.tm_mday;
    data.mes = tm.tm_mon + 1;
    data.ano = tm.tm_year + 1900;
    return data;
}

// Calcula a data de devolução (7 dias após o empréstimo)
Data calcularDataDevolucao(Data dataEmprestimo) {
    Data dataDevolucao = dataEmprestimo;
    dataDevolucao.dia += 7;
    if (dataDevolucao.dia > 30) {
        dataDevolucao.dia -= 30;
        dataDevolucao.mes++;
        if (dataDevolucao.mes > 12) {
            dataDevolucao.mes = 1;
            dataDevolucao.ano++;
        }
    }
    return dataDevolucao;
}

// Compara duas datas para ordenação (ano, mês, dia)
int compararDatas(Data d1, Data d2) {
    if (d1.ano < d2.ano) return -1;
    if (d1.ano > d2.ano) return 1;
    if (d1.mes < d2.mes) return -1;
    if (d1.mes > d2.mes) return 1;
    if (d1.dia < d2.dia) return -1;
    if (d1.dia > d2.dia) return 1;
    return 0;
}