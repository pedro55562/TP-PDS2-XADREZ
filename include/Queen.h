/**
 * @file Queen.h
 * @brief Define a classe Queen para representar uma peça de rainha no jogo de xadrez.
 */

#ifndef QUEEN_H
#define QUEEN_H

#include "Chess_constants.h"
#include "Piece.h"

/**
 * @class Queen
 * @brief Classe que representa uma peça de rainha no jogo de xadrez. Herda da classe Piece.
 */
class Queen : public Piece {
public:
    /**
     * @brief Construtor da classe Queen.
     * @param QueenColor A cor da peça de rainha (WHITE ou BLACK).
     */
    Queen(const int& QueenColor);

    /**
     * @brief Verifica se um movimento é válido para a rainha.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidQueenMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const;
};

#endif
