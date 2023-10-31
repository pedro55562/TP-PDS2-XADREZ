#include "../include/Chessboard.h"

#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

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
Chessboard::Chessboard(const string& fen)
{
    // Redimensionando a matriz board para o tamanho do tabuleiro(8x8).
    board.resize(BOARD_SIZE, vector<Piece>(BOARD_SIZE));
    
    // Começa a partir da posiçao 0,0 (canto superior esquerdo do tabuleiro)
    int row = 0;
    int col = 0;

    // Loop para ler a fen e carregaro tabuleiro, lendo e tratando cada char individualmente.
    for ( char c : fen)
    {
        // Fim da notação FEN
        if (c == ' ')
        {
            break;
        }
    // Caso o caractere for '/', significa que devemos partir para a proxima linha.
        else if (c == '/')
        {
            row++; 
            col = 0;
        }
    // Caso o caractere for um número, esse número indica a quantidade de casas vazias em sequência.
        else if (isdigit(c))
        {   
            int numberOfEmptySpaces = c - '0';
        // Loop para colocar no tabuleiro a quantidade caasas vazias
            for (int i = 0; i < numberOfEmptySpaces; i++)
            {
                board[row][col] = Piece(EMPTY, EMPTY);
                col++;
            }
        }
        else
        { // Switch-case responsavel por descobrir qual é a peça a ser inserida e inseri-la no tabuleiro
            switch (c)
            {
            case 'p':
                board[row][col] = Piece(PAWN, BLACKn);
                break;
            case 'P':
                board[row][col] = Piece(PAWN, WHITEn);
                break;
            case 'r':
                board[row][col] = Piece(ROOK, BLACKn);
                break;
            case 'R':
                board[row][col] = Piece(ROOK, WHITEn);
                break;
            case 'n':
                board[row][col] = Piece(KNIGHT, BLACKn);
                break;
            case 'N':
                board[row][col] = Piece(KNIGHT, WHITEn);
                break;
            case 'b':
                board[row][col] = Piece(BISHOP, BLACKn);
                break;
            case 'B':
                board[row][col] = Piece(BISHOP, WHITEn);
                break;
            case 'q':
                board[row][col] = Piece(QUEEN, BLACKn);
                break;
            case 'Q':
                board[row][col] = Piece(QUEEN, WHITEn);
                break;
            case 'k':
                board[row][col] = Piece(KING, BLACKn);
                break;
            case 'K':
                board[row][col] = Piece(KING, WHITEn);
                break;
            }
        // parte para a próxima casa
            col++;
        }
    }
}


    /**
     * @brief Imprime o tabuleiro na saída padrão.
     */
void Chessboard::printBoard() const
{
    // Loop para imprimir os tipos das peças no tabuleiro
    cout << endl << " Imprimindo o tido das peças: " << endl << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << " " << board[i][j].getType();
        }
        cout << endl; // Avança para a próxima linha após imprimir uma linha completa do tabuleiro
    }
    cout << endl;

    // Loop para imprimir as cores das peças no tabuleiro
    cout << endl << " Imprimindo a cor das peças: " << endl << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << " " << board[i][j].getColor();
        }
        cout << endl; // Avança para a próxima linha após imprimir uma linha completa do tabuleiro
    }
    cout << endl;
}


    /**
     * @brief Retorna a peça em uma posição específica no tabuleiro.
     *
     * @param row A linha da posição.
     * @param col A coluna da posição.
     * @return A peça na posição especificada.
     */
Piece Chessboard::retPiece(const int& row, const int& col) const
{
    return board[row][col];
}