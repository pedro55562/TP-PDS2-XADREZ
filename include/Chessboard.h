#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>

/**
 * @struct position
 * @brief Estrutura para representar a posição com linhas e colunas.
 */
struct position {
    int row; ///< A linha da posição.
    int col; ///< A coluna da posição.
};

using std::vector;
using std::list;
using std::string;

const int BOARD_SIZE = 8; ///< Tamanho padrão do tabuleiro de xadrez.

const string defaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"; ///< FEN padrão para um tabuleiro de xadrez inicial. [vide](https://www.chess.com/terms/fen-chess)

#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#include "Chess_constants.h"

/**
 * @class Chessboard
 * @brief Representa o tabuleiro de xadrez e suas operações.
 */
class Chessboard {
private:
    vector<vector<Piece>> board; ///< O tabuleiro de xadrez representado como uma matriz de peças.
    bool isWhiteTurn; ///< Indica se é o turno das peças brancas.

    /**
     * @brief Verifica se um movimento de uma posição para outra é válido.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidMove(const position from, const position to) const;

    /**
     * @brief Verifica se o caminho entre duas posições está livre de obstáculos.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     * @return true se o caminho estiver livre, false caso contrário.
     */
    bool isPathClear(const position from, const position to) const;

public:
    /**
     * @brief Construtor padrão da classe Chessboard.
     *
     * Cria um tabuleiro de xadrez com a configuração padrão.
     */
    Chessboard();

    /**
     * @brief Construtor da classe Chessboard com um FEN personalizado.
     *
     * Cria um tabuleiro de xadrez com base em um FEN (Notação de Álgebra de Xadrez) fornecido como parâmetro.
     *
     * @param fen A string FEN que descreve o estado do tabuleiro. [vide](https://www.chess.com/terms/fen-chess)
     */
    Chessboard(const string& fen);

    /**
     * @brief Imprime o tabuleiro na saída padrão.
     */
    void printBoard() const;

    /**
     * @brief Retorna a peça em uma posição específica no tabuleiro.
     *
     * @param row A linha da posição.
     * @param col A coluna da posição.
     * @return A peça na posição especificada.
     */
    Piece retPiece(const int row, const int col) const;

    /**
     * @brief Move uma peça de uma posição de origem para uma posição de destino.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     */
    void movePiece(const position from, const position to);

    /**
     * @brief Obtém uma lista de destinos possíveis para uma peça em uma determinada posição.
     *
     * @param from A posição da peça.
     * @return Uma lista de posições possíveis de destino.
     */
    list<position> getPossibleDestinations(const position from);
};

#endif
