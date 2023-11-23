#include "../include/Pawn.h"

    /**
     * @brief Construtor da classe Pawn.
     * @param pawncolor A cor da peça de peão (WHITE ou BLACK).
     */
Pawn::Pawn(const int& pawncolor) : Piece(PAWN, pawncolor){}

    /**
     * @brief Verifica se um movimento é válido para o peão.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @param toCollor A cor da peça de destino (WHITE ou BLACK). Serve para verificar se há uma peça no destino e saber a sua cor.
     * @return true se o movimento for válido, false caso contrário.
     */
bool Pawn:: isValidPawnMove(const int& fromX, const int& fromY, const int& toX, const int& toY, const int& toCollor){
                //REGRAS DA PEÇA 
// peão na primeira jogada pode andar 2 casas para frente
// peão depois da primeira jogada pode andar 1 casa para frente
// é proibido fazer um movimento retrógrado ou para os lados 
//https://docente.ifrn.edu.br/geraldosilva/xadrez/REGRAS.pdf

// verifica qual o tipo de jogador
    if(toCollor == BLACKn){
        //verifica se o movimento é retrógrado ou para os lados 
        if(fromX != toX || fromY -1 == toY){
            return false;
        }else if(fromX == toX && fromY + 1 == toY){
            //verifica se o movimento e valido 
            return true;
        }else if(fromX == toX && fromY + 2 == toY){
            //verifica se é o primeiro movimento da peça 
            return true;
        }
    }else{
        //verifica se o movimento é retrógrado ou para os lados 
        if(fromX == toX || fromY + 1 == toY){
            return false;
        }else if(fromX == toX && fromY - 1 == toY){
            //verifica se o movimento e valido 
            return true;
        }else if(fromX == toX && fromY - 2 == toY){
            //verifica se é o primeiro movimento da peça 
            return true;
        }
    }
    return false;
}