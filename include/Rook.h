/**
 * @file Rook.h
 * @brief Define a classe Rook para representar uma peça de torre no jogo de xadrez.
 */

#ifndef ROOK_H
#define ROOK_H

#include "Chess_constants.h"
#include "Piece.h"

/**
 * @class Rook
 * @brief Classe que representa uma peça de torre no jogo de xadrez. Herda da classe Piece.
 */
class Rook : public Piece {
public:
    /**
     * @brief Construtor da classe Rook.
     * @param RookColor A cor da peça de torre (WHITE ou BLACK).
     */
    Rook(int RookColor);

    /**
     * @brief Verifica se um movimento é válido para a torre.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidRookMove(int fromX, int fromY, int toX, toY) const;
};

#endif
