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
 * \brief Imprime o tabuleiro na tela
 */
void print_tabuleiro(void)
{
    system(CLEAR);
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

void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    fflush(stdin);
}

/**
 * \brief Realiza o turno do jogador
 * \return Retorna o valor da função avalia_tabuleiro
 */
int jogada_pessoa(void)
{
    print_tabuleiro();
    printf(" Seu turno. Qual a sua opcao? ");
    int jogada;
    while (1)
    {
        if (scanf("%d", &jogada) != 1)
        {
            limpar_buffer_entrada();
            printf("Tentativa invalida. Qual a sua opcao? ");
            continue;
        }
        limpar_buffer_entrada();
        printf("debug: %d\n", jogada);
        printf("debug: %d\n", !tabuleiro[jogada - 1]);
        if (jogada >= 1 && jogada <= 9 && !tabuleiro[jogada - 1]) // verifica se a jogada é válida
        {
            tabuleiro[jogada - 1] = -1; // -1 = jogador
            break;                      // sai do loop
        }
        printf(" Tentativa invalida. Qual a sua opcao? ");
    }
    return avalia_tabuleiro();
}
