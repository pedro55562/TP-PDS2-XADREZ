#include "../include/Bishop.h"

 //fromX A coordenada X da posição de origem.
 //fromY A coordenada Y da posição de origem.
 //toX A coordenada X da posição de destino.
 //toY A coordenada Y da posição de destino.
 //toCollor A cor da peça de destino (WHITE ou BLACK).
 //preta = cima
 //branca = baixo

/**
 * @brief Construtor da classe Bishop.
 * @param BishopColor A cor da peça de bispo (WHITE ou BLACK).
 *  Este construtor inicializa um objeto Bishop com uma cor específica.
 *  Ele utiliza a classe base Piece para atribuir o tipo da peça como BISHOP
 * e sua cor (recebida como parâmetro) ao criar um novo objeto da classe Bishop.
 */
Bishop::Bishop(const int& BishopColor) : Piece(BISHOP, BishopColor) {}

    /**
     * @brief Verifica se um movimento é válido para o bispo.
     * @param fromX A coordenada X da posição de origem.
     * @param fromY A coordenada Y da posição de origem.
     * @param toX A coordenada X da posição de destino.
     * @param toY A coordenada Y da posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
 bool Bishop :: isValidBishopMove(const int& fromX, const int& fromY, const int& toX, const int& toY) const{
                    //REGRAS DA PEÇA 
// bispo se movimenta na diagonal 
//https://docente.ifrn.edu.br/geraldosilva/xadrez/REGRAS.pdf

    int tamanho;
    if(fromX > toX){
        tamanho = fromX - toX;
    }else{
        tamanho = toX - fromX;
    }

    if(fromX + tamanho == toX && fromY + tamanho == toY){//diagonal superior direita em relação ao centro
        return true;

    }else if(fromX - tamanho == toX && fromY + tamanho == toY){//diagonal superio esquerda em relação ao centro
        return true;

    }else if(fromX + tamanho == toX && fromY - tamanho == toY){//diagonal inferior direita em relação ao centro
        return true;

    }else if(fromX - tamanho == toX && fromY - tamanho == toY){//diagonal inferior esquerda em relação ao centro
        return true;

    }else{//movimento invalido 
        return false;
    }
}