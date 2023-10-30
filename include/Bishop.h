/**
 * @file Bishop.h
 * @brief Define a classe Bishop para representar uma peça de bispo no jogo de xadrez.
 */

#ifndef BISHOP_H
#define BISHOP_H

#include <cmath>

#include "Chess_constants.h"
#include "Piece.h"

/**
 * @class Bishop
 * @brief Classe que representa uma peça de bispo no jogo de xadrez. Herda da classe Piece.
 */
class Bishop : public Piece {

public:
    /**
     * @brief Construtor da classe Bishop.
     * @param BishopColor A cor da peça de bispo (WHITE ou BLACK).
     */
    Bishop(const int& BishopColor);

    /**
     * @brief Verifica se um movimento é válido para o bispo.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidBishopMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const;
};

#endif
