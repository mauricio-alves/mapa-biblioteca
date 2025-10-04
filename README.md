# Atividade MAPA - Sistema de Gerenciamento de Biblioteca em C

Sistema de gerenciamento de biblioteca desenvolvido como atividade MAPA para a disciplina de Linguagem e Técnicas de Programação. O projeto foi desenvolvido em **linguagem C**, utilizando bibliotecas padrão, manipulação de arquivos de texto para persistência de dados, e uma estrutura modularizada com arquivos de cabeçalho (`.h`) e código-fonte (`.c`) separados por responsabilidade.

O sistema permite o cadastro de livros e usuários, além do controle de empréstimos e devoluções, simulando o gerenciamento do acervo de uma biblioteca.

## Como começar:

Para testar este projeto localmente, você precisará de um compilador C (como o GCC) instalado e configurado no seu sistema.

1.  Primeiro, clone este repositório para a sua máquina local:
    ```bash
    git clone https://github.com/mauricio-alves/mapa-biblioteca.git
    ```
2.  Navegue até a pasta do projeto:
    ```bash
    cd mapa-biblioteca
    ```
3.  Compile o projeto:
      ```bash
      gcc src/*.c -Iinclude -o biblioteca.exe
      ```
4.  Execute o programa:
    ```powershell
    ./biblioteca.exe
    ```

**Obs.:** Para usuários de Windows, é recomendado ter o **MinGW-w64** instalado (através do [MSYS2](https://www.msys2.org/)) para ter acesso ao comando `gcc`. Certifique-se de que o caminho para o executável (`gcc.exe`) foi adicionado ao PATH do sistema.

## Manual do Usuário

Ao executar o programa, você será apresentado a um menu principal com 4 seções principais e a opção de sair.

### 1. Gestão de Livros
Neste menu, você pode gerenciar todo o acervo da biblioteca.
- **Cadastrar Livro:** Adiciona um novo livro ao sistema. Serão solicitados dados como Código, Título, Autor, Editora, Ano e Número de exemplares.
- **Pesquisar Livro:** Permite buscar por um livro específico no acervo através do seu Código, Título ou Autor.
- **Listar todos os Livros:** Exibe uma lista formatada de todos os livros cadastrados no sistema, mostrando suas informações principais e a quantidade de exemplares disponíveis.

### 2. Gestão de Usuários
Esta seção é dedicada ao gerenciamento dos usuários da biblioteca.
- **Cadastrar Usuário:** Adiciona um novo usuário. O sistema pedirá dados como Matrícula, Nome Completo, Curso e Telefone. A data de cadastro é gerada automaticamente.
- **Pesquisar Usuário:** Permite buscar por um usuário através de sua Matrícula ou Nome.
- **Listar todos os Usuários:** Mostra uma lista com a Matrícula, Nome e Curso de todos os usuários cadastrados.

### 3. Gestão de Empréstimos
Aqui você pode controlar a entrada e saída de livros.
- **Realizar Empréstimo:** Cria um novo registro de empréstimo. O sistema solicitará a matrícula do usuário e o código do livro. Uma verificação é feita para garantir que o usuário existe e que há exemplares do livro disponíveis. A data de devolução é calculada para 7 dias após o empréstimo.
- **Realizar Devolução:** Finaliza um empréstimo ativo. Você precisará informar o código do empréstimo. Ao ser devolvido, o exemplar do livro volta a ficar disponível no acervo.
- **Renovar Empréstimo:** Permite estender o prazo de um empréstimo ativo por mais 7 dias a partir da data atual. Empréstimos em atraso não podem ser renovados.
- **Listar Empréstimos Ativos:** Exibe uma lista de todos os livros que estão atualmente emprestados, mostrando o código do empréstimo, o nome do usuário, o título do livro e a data prevista para devolução.

### 4. Relatórios
Esta seção oferece visões administrativas sobre o estado da biblioteca.
- **Usuários com Empréstimos em Atraso:** Gera um relatório mostrando todos os usuários que não devolveram um livro no prazo estipulado.

### 0. Sair
Ao escolher esta opção, o sistema salva todas as alterações feitas (novos livros, usuários, empréstimos e devoluções) nos arquivos `livros.txt`, `usuarios.txt` e `emprestimos.txt` dentro da pasta `data/`. Além disso, uma cópia de segurança (`.bak`) de cada arquivo é criada automaticamente.