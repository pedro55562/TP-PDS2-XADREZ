#include "../include/Queen.h"

    /**
     * @brief Construtor da classe Queen.
     * @param QueenColor A cor da peça de rainha (WHITE ou BLACK).
     */
Queen::Queen(const int& QueenColor) : Piece(QUEEN, QueenColor) {}

    /**
     * @brief Verifica se um movimento é válido para a rainha.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
bool Queen :: isValidQueenMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const{

    int tamanhoX;
    if(fromX > toX){
        tamanhoX = fromX - toX;
    }else{
        tamanhoX = toX - fromX;
    }

    int tamanhoY;
    if(fromY > toY){
        tamanhoY = fromY - toY;
    }else{
        tamanhoY = toY - fromY;
    }

    if(fromY + tamanhoY == toY && tamanhoX == 0){//superior
        return true;
    }else if(fromY - tamanhoY == toY && tamanhoX == 0){//inverior
        return true;
    }else if(tamanhoY == 0 && fromX + tamanhoX == toX){//direita
        return true;
    }else if(tamanhoY == 0 && fromX - tamanhoX == toX){//esquerda
        return true;
    }else if(fromY + tamanhoY == toY && fromX + tamanhoY == toX){//diagonal superior direita
        return true;
    }else if(fromY + tamanhoY == toY && fromX - tamanhoY == toX){//diagonal superior esquerda
        return true;
    }else if(fromY - tamanhoY == toY && fromX + tamanhoY == toX){//diagonal inferior direita
        return true;
    }else if(fromY - tamanhoY == toY && fromX - tamanhoY == toX){//diagonal inferior esquerda
        return true;
    }else{//movimento invalido
        return false;
    }
}