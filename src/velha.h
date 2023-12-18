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

// includes padrão
#include <stdio.h>
#include <stdlib.h>

// limpa a tela
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// tabuleiro do jogo
extern int *tabuleiro;

#define t tabuleiro

/**
 * \brief Verifica se há possibilidades de vitória para a função minimax
 * \return Retorna o jogador vencedor
 */
#define vitoria() t[0] == t[1] && t[1] == t[2] && t[0] != 0   ? t[0] \
                  : t[3] == t[4] && t[4] == t[5] && t[3] != 0 ? t[3] \
                  : t[6] == t[7] && t[7] == t[8] && t[6] != 0 ? t[6] \
                  : t[0] == t[3] && t[3] == t[6] && t[0] != 0 ? t[0] \
                  : t[1] == t[4] && t[4] == t[7] && t[1] != 0 ? t[1] \
                  : t[2] == t[5] && t[5] == t[8] && t[2] != 0 ? t[2] \
                  : t[0] == t[4] && t[4] == t[8] && t[0] != 0 ? t[0] \
                  : t[2] == t[4] && t[4] == t[6] && t[2] != 0 ? t[2] \
                                                              : 0

// funções

int avalia_tabuleiro(void);
int jogada_AI(void);
int jogada_pessoa(void);
int jogo(int jogador);
int main(void);
int minimax(int jogador);
void novo_jogo(void);
void print_tabuleiro(void);
