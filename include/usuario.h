#ifndef USUARIO_H
#define USUARIO_H

#include "estruturas.h"

// Declarações das funções relacionadas a usuários
void cadastrarUsuario(Usuario usuarios[], int* totalUsuarios);
void pesquisarUsuario(const Usuario usuarios[], int totalUsuarios);
void listarUsuarios(const Usuario usuarios[], int totalUsuarios);
int buscarUsuarioPorMatricula(const Usuario usuarios[], int totalUsuarios, int matricula);

#endif 