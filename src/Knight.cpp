#include "../include/Knight.h"


bool Knight :: isValidKnightMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const{

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