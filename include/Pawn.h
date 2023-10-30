/**
 * @file Pawn.h
 * @brief Define a classe Pawn para representar uma peça de peão no jogo de xadrez.
 */

#ifndef PAWN_H
#define PAWN_H

#include "Chessboard.h"
#include "Chess_constants.h"
#include "Piece.h"

/**
 * @class Pawn
 * @brief Classe que representa uma peça de peão no jogo de xadrez. Herda da classe Piece.
 */
class Pawn : public Piece {
public:
    /**
     * @brief Construtor da classe Pawn.
     * @param pawncolor A cor da peça de peão (WHITE ou BLACK).
     */
    Pawn(int pawncolor);

    /**
     * @brief Verifica se um movimento é válido para o peão.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @param toCollor A cor da peça de destino (WHITE ou BLACK). Serve para verificar se há uma peça no destino e saber a sua cor.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidPawnMove(int fromX, int fromY, int toX, int toY, int toCollor);
};

#endif
