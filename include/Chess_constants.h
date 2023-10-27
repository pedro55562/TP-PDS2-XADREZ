#ifndef CHESS_CONSTANTS_H
#define CHESS_CONSTANTS_H

/**
 * @file Chess_constants.h
 * @brief Define constantes relacionadas ao xadrez.
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
