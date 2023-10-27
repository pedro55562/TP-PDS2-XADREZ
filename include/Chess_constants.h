#ifndef CHESS_CONSTANTS_H
#define CHESS_CONSTANTS_H

// Algumas constantes utilizadas:

/*
    Utilizaremos os 5 bits menos significativos de numeros inteiros para 
    representar cada peça, sendo os da 3 da direita sendo responsavel para o tipo
    e os 2 da esquerda para a cor.
    sendo:
    01: branco
    10: preto

    Abaixo segue a declaração utilizando base 10:
*/

    // Constantes para representar casa vazia
    const int EMPTY = 0;

    // Constantes para representar os tipos de peças
    const int KING = 1;
    const int QUEEN = 2;
    const int ROOK = 3;
    const int BISHOP = 4;
    const int KNIGHT = 5;
    const int PAWN = 6;

    // Constantes para representar as cores
    const int WHITEn = 8;
    const int BLACKn = 16;

#endif 