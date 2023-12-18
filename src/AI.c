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
 * \brief Algoritmo minimax, calcula a melhor jogada possível
 * \return Retorna o jogador vencedor
 * \param jogador Valor que representa o jogador
 */
int minimax(int jogador)
{
    int vencedor = vitoria(),                      // verifica se há um vencedor
        jogada = -1, decisao, melhor_decisao = -2; // melhor_decisao = -2 para que o primeiro valor seja maior que ele
    if (vencedor)                                  // se houver um vencedor, retorna o jogador atual
        return vencedor * jogador;
    for (int i = 0; i < 9; i++) // percorre o tabuleiro
        if (!tabuleiro[i])      // se a posição estiver vazia
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
 * \brief Realiza o turno da AI
 * \return Retorna o valor da função avalia_tabuleiro
 */
int jogada_AI(void)
{
    int jogada = -1, melhor_decisao = -2, decisao;
    for (int i = 0; i < 9; i++) // percorre o tabuleiro
        if (!tabuleiro[i])      // se a posição estiver vazia
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