/**
 * MIT License
 *
 * Copyright(c) 2022 Henrique Almeida <hcarvalhoalmeida7@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>

// verifica se há possibilidades de vitória para a função minimax
#define possibilidades() (tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[0] != 0   ? tabuleiro[0] \
                          : tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[3] != 0 ? tabuleiro[3] \
                          : tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[6] != 0 ? tabuleiro[6] \
                          : tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[0] != 0 ? tabuleiro[0] \
                          : tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[1] != 0 ? tabuleiro[1] \
                          : tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[2] != 0 ? tabuleiro[2] \
                          : tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[0] != 0 ? tabuleiro[0] \
                          : tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[2] != 0 ? tabuleiro[2] \
                                                                                                              : 0)

static int tabuleiro[9]; // tabuleiro do jogo

/**
 * \brief Função que imprime o tabuleiro
 */
static void print_tabuleiro(void)
{
    system("cls");
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
        case 0:
        case 3:
        case 6:
            printf("\n    --- --- --- \n    ");
            break;
        default:
            printf("|");
        }
        switch (tabuleiro[i])
        {
        case -1:
            printf(" X ");
            break;
        case 1:
            printf(" O ");
            break;
        default:
            printf("   ");
        }
    }
    printf("\n    --- --- --- \n\n");
}

/**
 * \brief Verifica se o jogo acabou
 * \return Retorna o jogador vencedor, 0 se não houver um e 9 se houver empate
 */
static int avalia_tabuleiro(void)
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i] == tabuleiro[i + 3] && tabuleiro[i + 3] == tabuleiro[i + 6])                 // verifica se há uma linha vencedora
            return tabuleiro[i];                                                                      // se houver, retorna o jogador vencedor
        if (tabuleiro[i * 3] == tabuleiro[i * 3 + 1] && tabuleiro[i * 3 + 1] == tabuleiro[i * 3 + 2]) // verifica se há uma coluna vencedora
            return tabuleiro[i * 3];                                                                  // se houver, retorna o jogador vencedor
    }
    if (tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8]) // verifica se há uma diagonal vencedora
        return tabuleiro[0];
    if (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6]) // verifica se há uma diagonal vencedora
        return tabuleiro[2];
    for (int i = 0; i < 9; i++) // verifica se há um empate
        if (tabuleiro[i] == 0)  // se há uma posição vazia, não há empate
            return 0;
    return 9; // se não houver vencedor e não houver posição vazia, há empate
}

/**
 * \brief Algoritmo minimax
 * \return Retorna o jogador vencedor
 * \param jogador Valor que representa o jogador
 */
static int minimax(int jogador)
{
    int vencedor = possibilidades(),               // verifica se há um vencedor
        jogada = -1, decisao, melhor_decisao = -2; // melhor_decisao = -2 para que o primeiro valor seja maior que ele
    if (vencedor != 0)                             // se houver um vencedor, retorna o jogador atual
        return vencedor * jogador;
    for (int i = 0; i < 9; i++) // percorre o tabuleiro inteiro
        if (tabuleiro[i] == 0)  // se a posição estiver vazia
        {
            tabuleiro[i] = jogador;       // preenche a posição com o jogador atual
            decisao = -minimax(-jogador); // chama a função minimax com o jogador oposto ao atual
            if (decisao > melhor_decisao) // se o resultado for maior que a saída
            {
                melhor_decisao = decisao; // a saída se torna o resultado
                jogada = i;               // a melhor jogada se torna a posição atual
            }
            tabuleiro[i] = 0; // limpa a posição atual
        }
    if (jogada == -1) // se não houver nenhuma jogada possível
        return 0;
    return melhor_decisao;
}

/**
 * \brief Função que realiza o turno da AI
 * \return Retorna o valor da função avalia_tabuleiro
 */
static int jogada_AI(void)
{
    int jogada = -1, melhor_decisao = -2, decisao;
    for (int i = 0; i < 9; i++) // percorre o tabuleiro
        if (tabuleiro[i] == 0)  // 0 = vazio
        {
            tabuleiro[i] = 1;             // 1 = AI
            decisao = -minimax(-1);       // -1 = jogador
            tabuleiro[i] = 0;             // 0 = vazio
            if (decisao > melhor_decisao) // se a jogada for melhor que as anteriores
            {
                melhor_decisao = decisao; // a saída se torna o resultado
                jogada = i;               // a melhor jogada se torna a posição atual
            }
        }
    tabuleiro[jogada] = 1;
    return avalia_tabuleiro();
}

/**
 * \brief Função que realiza o turno do jogador
 * \return Retorna o valor da função avalia_tabuleiro
 */
static int jogada_pessoa(void)
{
    printf(" Seu turno. Qual a sua opcao? ");
    while (1)
    {
        int jogada = fgetc(stdin) - 48; // pega o primeiro caractere da entrada converte para inteiro
        fflush(stdin);
        if (jogada >= 1 && jogada <= 9 && tabuleiro[jogada - 1] == 0) // 0 = vazio
        {
            tabuleiro[jogada - 1] = -1; // -1 = jogador
            break;                      // sai do loop
        }
        printf(" Tentativa invalida. Qual a sua opcao? ");
    }
    return avalia_tabuleiro();
}

/**
 * \brief Função que realiza o jogo
 * \return Retorna o jogador vencedor
 */
static int jogo(int jogador)
{
    int vencedor = 0;
    while (!vencedor) // 9 = empate, 1 = AI, -1 = jogador, 0 = jogo em andamento
        if (jogador)
        {
            print_tabuleiro();
            vencedor = jogada_pessoa();
            jogador--;
        }
        else
        {
            jogador++;
            vencedor = jogada_AI();
        }
    return vencedor;
}

static void novoJogo(void)
{

    printf(" Deseja jogar novamente? (s/n) ");
    char resposta;
    while (1)
    {
        resposta = fgetc(stdin);
        fflush(stdin);
        if (resposta == 's' || resposta == 'n')
            break;
        printf(" Resposta invalida. Deseja jogar novamente? (s/n) ");
    }
    if (resposta == 'n')
    {
        system("pause");
        exit(0);
    }
}

int main()
{

    while (1) // loop para jogar multiplas partidas
    {
        for (int i = 0; i < 9; i++)
            tabuleiro[i] = 0; // limpa o tabuleiro

        int vencedor = jogo(1); // 0 = vazio, 1 = AI, -1 = jogador

        print_tabuleiro();                                                  // imprime o tabuleiro final
        printf(vencedor == 9   ? "\n Empate! Nos vemos da proxima vez.\n\n" //
               : vencedor == 1 ? "\n Eu ganhei!\n\n"                        //
                               : "\n Impressionante, voce me derrotou\n\n"  //
        );

        novoJogo(); // permite uma nova partida
    }
    return 0;
}
