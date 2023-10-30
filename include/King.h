/**
 * @file King.h
 * @brief Define a classe King para representar uma peça de rei no jogo de xadrez.
 */

#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Chess_constants.h"

/**
 * @class King
 * @brief Classe que representa uma peça de rei no jogo de xadrez. Herda da classe Piece.
 */
class King : public Piece {
public:
    /**
     * @brief Construtor da classe King.
     * @param KingColor A cor da peça de rei (WHITE ou BLACK).
     */
    King(const int& KingColor);

    /**
     * @brief Verifica se um movimento é válido para o rei.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidKingMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const;
};

#endif
