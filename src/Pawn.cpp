#include "../include/Pawn.h"

//qual a variavel que armazena a quantidade de movimento de cada peça? 

 //fromX A coordenada X da posição de origem.
 //fromY A coordenada Y da posição de origem.
 //toX A coordenada X da posição de destino.
 //toY A coordenada Y da posição de destino.
 //toCollor A cor da peça de destino (WHITE ou BLACK).
 //preta = cima
 //branca = baixo
bool Pawn:: isValidPawnMove(const int& fromX, const int& fromY, const int& toX, const int& toY, const int& toCollor){
                //REGRAS DA PEÇA 
// peão na primeira jogada pode andar 2 casas para frente
// peão depois da primeira jogada pode andar 1 casa para frente
// é proibido fazer um movimento retrógrado ou para os lados 
//https://docente.ifrn.edu.br/geraldosilva/xadrez/REGRAS.pdf

// verifica qual o tipo de jogador
    if(toCollor == 16){
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
}