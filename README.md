# mapa-biblioteca

Manual do Usuário e Compilação
Como Compilar e Executar (Usando Dev-C++):
Crie um Projeto: Abra o Dev-C++ e vá em Arquivo -> Novo -> Projeto. Escolha "Console Application" e "Projeto C". Dê um nome ao projeto (ex: Biblioteca) e salve.

Adicione os Arquivos:

O Dev-C++ criará um main.c padrão. Substitua o conteúdo dele pelo código do main.c fornecido acima.

No painel do projeto (geralmente à esquerda), clique com o botão direito no nome do projeto e selecione Adicionar ao Projeto.

Selecione TODOS os outros arquivos .c e .h (livro.c, livro.h, usuario.c, usuario.h, etc.).

Compile e Execute:

Pressione a tecla F11 (ou vá em Executar -> Compilar e Executar).

O Dev-C++ irá compilar todos os arquivos .c juntos e gerar um executável.

Uma janela de console aparecerá com o menu principal do sistema.

Como Compilar e Executar (Usando GCC no Terminal - Linux/Mac/Windows com MinGW):
Navegue até a Pasta: Abra um terminal e use o comando cd para navegar até a pasta onde você salvou todos os arquivos.

Compile: Execute o seguinte comando:

Bash

gcc main.c livro.c usuario.c emprestimo.c arquivo.c menu.c util.c -o biblioteca.exe
Execute:

No Windows: .\biblioteca.exe

No Linux/Mac: ./biblioteca.exe

Funcionalidades do Sistema:
Gestão de Livros: Permite cadastrar novos livros, pesquisá-los por código, título ou autor, e listar todos os livros do acervo.

Gestão de Usuários: Permite cadastrar novos usuários da biblioteca, pesquisá-los por matrícula ou nome, e listar todos os usuários.

Gestão de Empréstimos: O coração do sistema. Permite registrar um empréstimo (vinculando um usuário a um livro), registrar uma devolução, renovar um empréstimo existente e ver uma lista de todos os empréstimos que ainda estão ativos.

Relatórios: Oferece funcionalidades avançadas, como a geração de uma lista de todos os usuários com empréstimos em atraso.

Persistência de Dados: Todos os dados são salvos automaticamente em arquivos .txt quando o programa é fechado e carregados quando ele é iniciado.

Backup Automático: Ao sair do sistema, cópias de segurança dos arquivos de dados (livros.bak, usuarios.bak, emprestimos.bak) são criadas.