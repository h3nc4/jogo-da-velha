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

/**
 * \brief Função auxiliar para iterar sobre o tabuleiro e realizar a lógica comum
 * \param jogador Valor que representa o jogador
 * \param melhor_decisao Ponteiro para a melhor decisão
 * \param jogada Ponteiro para a melhor jogada
 */
void melhor_jogada(int jogador, int *melhor_decisao, int *jogada)
{
    for (int i = 0; i < 9; i++) // percorre o tabuleiro
        if (!tabuleiro[i]) // se a posição estiver vazia
        {
            tabuleiro[i] = jogador; // preenche a posição com o jogador atual
            int decisao = -minimax(-jogador); // chama a função minimax com o jogador oposto ao atual
            tabuleiro[i] = 0; // limpa a posição atual
            if (decisao > *melhor_decisao) // se o resultado for maior que o conhecido
            {
                *melhor_decisao = decisao; // armazena o melhor resultado até o momento
                *jogada = i; // a melhor jogada se torna a posição atual
            }
        }
}

/**
 * \brief Algoritmo minimax, calcula a melhor jogada possível
 * \return Retorna o jogador vencedor
 * \param jogador Valor que representa o jogador
 */
int minimax(int jogador)
{
    int vencedor = vitoria(), // verifica se há um vencedor
        jogada = -1, // jogada = -1 para que qualquer local a sobrescreva
        melhor_decisao = -2; // melhor_decisao = -2 para que o primeiro valor o sobrescreva
    if (vencedor) // se houver um vencedor, retorna o jogador atual
        return vencedor * jogador;
    melhor_jogada(jogador, &melhor_decisao, &jogada); // itera sobre o tabuleiro
    if (jogada == -1) // se não houver nenhuma jogada possível
        return 0;
    return melhor_decisao; // retorna a melhor decisão
}

/**
 * \brief Realiza o turno da AI
 * \return Retorna o valor da função avalia_tabuleiro
 */
int jogada_AI(void)
{
    int jogada = -1, melhor_decisao = -2;
    melhor_jogada(AI, &melhor_decisao, &jogada);
    tabuleiro[jogada] = AI; // executa a melhor jogada
    return avalia_tabuleiro();
}
