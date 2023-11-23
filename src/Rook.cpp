#include "../include/Rook.h"

 //fromX A coordenada X da posição de origem.
 //fromY A coordenada Y da posição de origem.
 //toX A coordenada X da posição de destino.
 //toY A coordenada Y da posição de destino.
 //toCollor A cor da peça de destino (WHITE ou BLACK).
 //preta = cima
 //branca = baixo
    
    /**
     * @brief Construtor da classe Rook.
     * @param RookColor A cor da peça de torre (WHITE ou BLACK).
     */
Rook::Rook(const int& RookColor) : Piece(ROOK, RookColor){}

    /**
     * @brief Verifica se um movimento é válido para a torre.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
bool Rook :: isValidRookMove(const int& fromX, const int& fromY, const int& toX, const int& toY)const{
                    //REGRAS DA PEÇA 
// torre se movimenta na horizontal e vertical quantas casas desejar
//https://docente.ifrn.edu.br/geraldosilva/xadrez/REGRAS.pdf

    if(fromX == toX && fromY > toY){// movimento na vertical
        return true;
    }else if(fromX == toX && fromY < toY){ // movimento na vertical
        return true;
    }else if(fromX > toX && fromY == toY){ // movimento na horizontal
        return true;
    }else if(fromX < toX && fromY == toY){ // movimento na horizontal
        return true;
    }else{//movimento invalido
        return false;
    }
}