#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>

#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#include "Chess_constants.h"

using std::vector;
using std::list;
using std::string;

/**
 * @struct position
 * @brief Estrutura para representar a posição com linhas e colunas.
 */
struct position {
    int row; ///< A linha da posição.
    int col; ///< A coluna da posição.
};

const int BOARD_SIZE = 8; ///< Tamanho padrão do tabuleiro de xadrez.

const string defaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"; ///< FEN padrão para um tabuleiro de xadrez inicial. [Saiba mais](https://www.chess.com/terms/fen-chess)

/**
 * @class Chessboard
 * @brief Representa o tabuleiro de xadrez e suas operações.
 */
class Chessboard {
private:
    vector<vector<Piece>> board; ///< O tabuleiro de xadrez representado como uma matriz de peças.
    bool isWhiteTurn; ///< Indica se é o turno das peças brancas.

    position whiteKingPos; ///< Indica a posicção do rei branco
    position blackKingPos; ///< Indica a posicção do rei preto

    /**
     * @brief Verifica se um movimento de uma posição para outra é válido.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
    bool isValidMove(const position& from, const position& to) const;

    /**
     * @brief Verifica se o caminho entre duas posições está livre de obstáculos.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     * @return true se o caminho estiver livre, false caso contrário.
     */
    bool isPathClear(const position& from, const position& to) const;

    /**
     * @brief Atualiza a posição do rei após uma jogada.
     *
     * Esta função atualiza a posição do rei na estrutura de dados de posição após uma jogada
     * ser realizada.
     *
     * @param pos A posição após a jogada.
     */
    void updateKingPosition(const position& pos);

     /** @brief Verifica se um movimento de uma posição de origem para uma posição de destino
     * deixa o rei da cor atual em xeque.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     * @return true se o movimento deixar o rei em xeque, false caso contrário.
     */
    bool leavesKingInCheck(const position& from, const position& to) const;

    /**
     * @brief Verifica se uma dada posição está sob ataque.
     *
     * Esta função verifica se uma certa peça está sob ataque na posição especificada.
     *
     * @param pos A posição da peça a ser verificada.
     * @return true se a peça estiver sob ataque na posição, false caso contrário.
     */
    bool isPieceUnderAtack(const position& pos);


public:

    /**
     * @brief Construtor da classe Chessboard com um FEN personalizado.
     *
     *   Este construtor cria um tabuleiro de xadrez com base em uma notação FEN fornecida como parâmetro. 
     * O FEN é uma representação textual que descreve o estado atual de um tabuleiro de xadrez.
     * 
     *   Se o FEN passado como argumento for o  defaultFen (que representa a configuração inicial de peças no tabuleiro), 
     * o construtor criará um tabuleiro com essa configuração padrão.
     * 
     * @param fen A string FEN que descreve o estado do tabuleiro. [Saiba mais](https://www.chess.com/terms/fen-chess)
     */
    Chessboard(const string& fen);

    /**
     * @brief Imprime o tabuleiro na saída padrão.
     */
    void printBoard();

    /**
     * @brief Obtém todas as possíveis posições para movimentos válidos das peças no tabuleiro.
     *
     * Esta função retorna uma lista contendo todas as posições possíveis para movimentos válidos
     * das peças no tabuleiro atual. As posições são representadas pela estrutura 'position'.
     *
     * @return Uma lista de posições possíveis para movimentos válidos das peças no tabuleiro.
     */
    list<position> getAllPossibleMoves();
    
    /**
     * @brief Retorna a peça em uma posição específica no tabuleiro.
     *
     * @param row A linha da posição.
     * @param col A coluna da posição.
     * @return A peça na posição especificada.
     */
    Piece retPiece(const int& row, const int& col) const;

    /**
     * @brief Move uma peça de uma posição de origem para uma posição de destino.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     */
    void movePiece(const position& from, const position& to);

    /**
     * @brief Obtém uma lista de destinos possíveis para uma peça em uma determinada posição.
     *
     * @param from A posição da peça.
     * @return Uma lista de posições possíveis de destino.
     */
    list<position> getPossibleDestinations(const position& from);
    
    /**
     * @brief Verifica se o rei do jogador atual está em xeque.
     *
     * Esta função verifica se o rei do jogador atual está em xeque. Um rei está em xeque quando está sob ataque por uma peça adversária.
     *
     * @return true se o rei do jogador atual está em xeque, false caso contrário.
     */
    bool isCheck();

    /**
     * @brief Verifica se um jogador está em xeque-mate.
     *
     * Verifica se o jogador atual está em xeque-mate, ou seja, em uma situação em que o rei
     * do jogador não pode escapar de um xeque. Se for xeque-mate, o jogo deve terminar.
     *
     * @return true se o jogador estiver em xeque-mate, false caso contrário.
     */
    bool isCheckmate();
};

#endif
