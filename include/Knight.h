/**
 * @file Knight.h
 * @brief Define a classe Knight para representar uma peça de cavaleiro no jogo de xadrez.
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include <cmath>

#include "Piece.h"
#include "Chess_constants.h"

/**
 * @class Knight
 * @brief Classe que representa uma peça de cavaleiro no jogo de xadrez. Herda da classe Piece.
 */
class Knight : public Piece {
public:
    /**
     * @brief Construtor da classe Knight.
     * @param KingColor A cor da peça de cavaleiro (WHITE ou BLACK).
     */
    Knight(int KingColor);

    /**
     * @brief Verifica se um movimento é válido para o cavaleiro.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidKnightMove(int fromX, int fromY, int toX, int toY) const;
};

#endif
