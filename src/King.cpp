#include "../include/King.h"
#include <cmath>

    /**
     * @brief Construtor da classe King.
     * @param KingColor A cor da peça de rei (WHITE ou BLACK).
     */
King::King(const int& KingColor): Piece(KING,KingColor){}

    /**
     * @brief Verifica se um movimento é válido para o rei.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
bool King::isValidKingMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const{
    int dx = abs(toX - fromX);
    int dy = abs(toY - fromY);
    return (dx == 1)||(dy == 1);
}