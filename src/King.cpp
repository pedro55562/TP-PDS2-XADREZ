#include "../include/King.h"

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
    if(fromX == toX && fromY + 1 == toY){//superior
        return true;
    }else if(fromX == toX && fromY - 1 == toY){//inferior
        return true;
    }else if(fromX + 1 == toX && fromY + 1 == toY){//diagonal superior direita 
        return true;
    }else if(fromX - 1 == toX && fromY + 1 == toY){//diagonal superior esquerda 
        return true;
    }else if(fromX + 1 == toX && fromY - 1 == toY){//diagonal inferior direita 
        return true;
    }else if(fromX - 1 == toX && fromY - 1 == toY){//diagonal inferior esquerda 
        return true;
    }else{//movimento invalido 
        return false;
    }
}