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
                
    int drow = toY - fromY;
    int dcol = toX - fromX;

    if (dcol == 0 && toCollor == EMPTY)
    {
        if (getColor() == BLACKn)
        {
            if (fromY == 1)
            {
                return (drow == 1) || (drow == 2);
            }
            if (fromY != 1)
            {
                return (drow == 1);
            }
        }
        if (getColor() == WHITEn)
        {
            if (fromY == 6)
            {
                return (drow == -1) || (drow == -2);
            }
            if (fromY != 1)
            {
                return (drow == -1);
            }
        }
    }

    if ((toCollor != EMPTY) && (dcol == 1 || dcol == -1) )
    {

        if (getColor() == BLACKn && toCollor == WHITEn)
        {
            return ((dcol == 1)||(dcol == -1))&&(drow == 1);
        }
        if (getColor() == WHITEn && toCollor == BLACKn)
        {
            return ((dcol == 1)||(dcol == -1))&&(drow == -1);
        }
    }

    return false;
}