#ifndef PIECE_H
#define PIECE_H 

#include "Chess_constants.h"

class Piece {
private:

    /// @var type
    /// Armazena o tipo da peça (como peão, torre, rainha, etc).
    /// De acordo com as constantes estabelecidas em Chess_constantsh.
    int type;

    /// @var color
    /// Armazena a cor da peça (branca ou preta).
    /// De acordo com as constantes estabelecidas em Chess_constantsh.
    int color;

public:
    /// @brief Construtor da classe Piece.
    /// @param type1 O tipo da peça (ex: PAWN, ROOK, QUEEN, etc).
    /// @param color1 A cor da peça (WHITEn ou BLACKn).
    Piece(const int& type1, const int& color1);

    /// @brief Construtor padrão da classe Piece.
    /// Constroi uma peça vazia, ou seja type = 0 e color = 0.
    Piece();

    /// @brief Obtém o tipo da peça.
    /// @return O tipo da peça, retornando o inteiro associado.
    int getType() const;

    /// @brief Obtém a cor da peça.
    /// @return A cor da peça, retornando o inteiro associado.
    int getColor() const;
};

#endif