/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2022-2023, Henrique Almeida
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "velha.h"

int *tabuleiro;

/**
 * \brief Pergunta se o usuário deseja jogar novamente
 */
void novo_jogo(void)
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
        free(tabuleiro);
        exit(0);
    }
}

/**
 * \brief Verifica se existe um vencedor
 * \param jogador Define se o jogador começa ou não
 * \return Retorna o jogador vencedor
 */
int jogo(int jogador)
{
    int vencedor = 0;
    while (!vencedor) // 9 = empate, 1 = AI, -1 = jogador, 0 = jogo em andamento
        vencedor = (jogador = !jogador) ? jogada_pessoa() : jogada_AI();
    return vencedor;
}

int main(void)
{
    tabuleiro = malloc(sizeof(int) * 9);
    char inicio = 0;
    while (1)
    {
        for (int i = 0; i < 9; i++)
            tabuleiro[i] = 0; // inicia o tabuleiro
        int vencedor = jogo(inicio++ % 2); // 0 = jogador começa, 1 = AI começa
        print_tabuleiro();
        printf(vencedor == 9    ? "\n Empate! Nos vemos da proxima vez.\n\n" //
               : vencedor == AI ? "\n Eu ganhei!\n\n"                        //
                                : "\n Impressionante, voce me derrotou\n\n"  //
        );
        novo_jogo();
    }
}
