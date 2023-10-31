#include "../include/Piece.h"

/**
 * @brief Construtor da classe Piece.
 *
 * Este construtor recebe o tipo e a cor da peça como parâmetros e os atribui às variáveis de membro.
 *
 * @param type1 O tipo da peça (ex: PAWN, ROOK, QUEEN, etc).
 * @param color1 A cor da peça (WHITEn ou BLACKn).
 */
Piece::Piece(const int& type1, const int& color1)
{
    type = type1;
    color = color1;
}

/**
 * @brief Construtor padrão da classe Piece.
 *
 * Este construtor cria uma peça vazia, ou seja, com tipo e cor definidos como EMPTY.
 */
Piece::Piece()
{
    type = EMPTY;
    color = EMPTY;
}

/**
 * @brief Obtém o tipo da peça.
 *
 * @return O tipo da peça, retornando o inteiro associado.
 */
int Piece::getType() const
{
    return type;
}

/**
 * @brief Obtém a cor da peça.
 *
 * @return A cor da peça, retornando o inteiro associado.
 */
int Piece::getColor() const
{
    return color;
}
