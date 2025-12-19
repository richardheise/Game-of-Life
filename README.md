# Game of Life

Este é um projeto em C que implementa o Jogo da Vida de John Conway.

## O que é o Jogo da Vida?

O Jogo da Vida é um autômato celular que simula a evolução de uma população de células em um tabuleiro. As regras são simples:

*   Uma célula morta com exatamente 3 vizinhas vivas torna-se viva.
*   Uma célula viva com 2 ou 3 vizinhas vivas continua viva.
*   Qualquer outra célula viva morre por solidão ou superpopulação.

## Compilando o Projeto

Para compilar o projeto, utilize o comando `make`:

```bash
make
```

Isso irá gerar um executável chamado `game_of_life`.

## Executando o Jogo

Para executar o jogo, rode o seguinte comando:

```bash
./game_of_life <linhas> <colunas>
```

Substitua `<linhas>` e `<colunas>` pelo tamanho do tabuleiro que você deseja.

### Padrões

A pasta `inputs/` contém alguns padrões iniciais que podem ser usados para iniciar o jogo.

*   `blinker.txt`: Um oscilador simples.
*   `gosper_gun.txt`: Uma "arma" que dispara gliders continuamente.

Para usar um padrão, você pode redirecionar o conteúdo do arquivo para a entrada padrão do programa.

#### Exemplo com o Gosper Glider Gun

```bash
./game_of_life 40 40 < inputs/gosper_gun.txt
```

#### Exemplo com o Blinker

```bash
./game_of_life 20 20 < inputs/blinker.txt
```

## Limpando os Arquivos Compilados

Para remover os arquivos gerados pela compilação, execute:

```bash
make clean
```
