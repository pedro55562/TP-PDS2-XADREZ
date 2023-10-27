#ifndef CHESS_CONSTANTS_H
#define CHESS_CONSTANTS_H

/**
 * @file Chess_constants.h
 * @brief Define constantes relacionadas ao xadrez.
 */

/**
 * @brief Representação de peças de xadrez em inteiros usando bits.
 *
 * No contexto deste código, usamos os 5 bits menos significativos de números inteiros
 * para representar cada peça de xadrez. Os 3 bits à direita são responsáveis pelo tipo
 * da peça, enquanto os 2 bits à esquerda indicam a cor da peça. 
 * 
 * - 01: Representa peças brancas.
 * - 10: Representa peças pretas.
 *
 * Portanto, ao combinar os bits do tipo e da cor, podemos representar qualquer peça de xadrez
 * em um único número inteiro.
 *
 * Exemplo:
 * Suponha que desejamos representar um peão branco. Seu tipo é PAWN (6) e sua cor é WHITE (8).
 * Para combinar essas informações, usamos OR bit a bit (|).
 */

/**
 * @defgroup ChessPieceTypes Tipos de Peças
 * @{
 */
const int EMPTY = 0;  ///< Representa uma casa vazia.
const int KING = 1;   ///< Representa um rei.
const int QUEEN = 2;  ///< Representa uma rainha.
const int ROOK = 3;   ///< Representa uma torre.
const int BISHOP = 4; ///< Representa um bispo.
const int KNIGHT = 5; ///< Representa um cavaleiro.
const int PAWN = 6;   ///< Representa um peão.
/** @} */

/**
 * @defgroup ChessPieceColors Cores das Peças
 * @{
 */
const int WHITE = 8;  ///< Representa a cor branca.
const int BLACK = 16; ///< Representa a cor preta.
/** @} */

#endif