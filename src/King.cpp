#include "../include/King.h"

bool King :: isValidKingMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const{
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