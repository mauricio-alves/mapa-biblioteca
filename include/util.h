#ifndef UTIL_H
#define UTIL_H

#include "estruturas.h" 

// Inclui a definição da struct Data
void limparTela();
void pressioneEnterParaContinuar();
Data obterDataAtual();
Data calcularDataDevolucao(Data dataEmprestimo);
int compararDatas(Data d1, Data d2);

#endif 