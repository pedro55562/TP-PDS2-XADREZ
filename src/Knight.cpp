#include "../include/Knight.h"

    /**
     * @brief Construtor da classe Knight.
     * @param KingColor A cor da peça de cavaleiro (WHITE ou BLACK).
     */
Knight::Knight(const int& KingColor) : Piece(KNIGHT,KingColor) {}


    /**
     * @brief Verifica se um movimento é válido para o cavaleiro.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
bool Knight::isValidKnightMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const{

    if(fromX + 1 == toX && fromY + 2 == toY){//duas superior um direita
        return true;
    }else if(fromX - 1 == toX && fromY + 2 == toY){//duas superior um esquerda
        return true;
    }else if(fromX + 1 == toX && fromY - 2 == toY){//duas inferior um direita
        return true;
    }else if(fromX - 1 == toX && fromY - 2 == toY){//duas inferior um esquerda
        return true;
    }if(fromX + 2 == toX && fromY + 1 == toY){//uma superior duas direita
        return true;
    }else if(fromX - 2 == toX && fromY + 1 == toY){//uma superior duas esquerda
        return true;
    }else if(fromX + 2 == toX && fromY - 1 == toY){//uma inferior duas direita
        return true;
    }else if(fromX - 2 == toX && fromY - 1 == toY){//uma inferior duas esquerda
        return true;
    }else{
        return false;
    }
}