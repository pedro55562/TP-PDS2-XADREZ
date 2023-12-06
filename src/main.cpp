/*
  *****************************************************
  *                                                   *
  * O Senhor, obrigado por Sua bondade em nossas      *
  * vidas. Por favor, abençoe este código para os    *
  * nossos compiladores. Amen.                         *
  *                                                   *
  *****************************************************
*/

#include "../include/ChessRenderer.h"
#include "../include/Chessboard.h"
#include "../include/Chess_constants.h"
#include "../include/Bishop.h"
#include "../include/Bishop.h"
#include "../include/King.h"
#include "../include/Knight.h"
#include "../include/Pawn.h"
#include "../include/Piece.h"
#include "../include/Queen.h"
#include "../include/Rook.h"

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <raylib.h>

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

/**
 * @brief Função principal do jogo de xadrez.
 *
 * Aqui é iniciado o jogo de xadrez, incluindo a criação do tabuleiro, a renderização gráfica
 * e o loop principal do jogo.
 *
 * @return 0 para indicar término bem-sucedido.
 */
int main (){
  try
  {  
    // Cria um objeto Chessboard inicializado com a posição padrão do xadrez (defaultFen)
    Chessboard board(defaultFen);

    // Cria um objeto ChessRenderer passando o tabuleiro como argumento
    ChessRenderer graphicboard(board);
    
    board.printBoard();

    // Loop principal do jogo
    while ( !graphicboard.shouldClose() ){
      graphicboard.render();
      position movefrom = graphicboard.handleMouseInput();
      graphicboard.updateSelectedPiece(movefrom);
      position moveto;
      if (board.retPiece(movefrom.row, movefrom.col).getType() != EMPTY && graphicboard.shouldClose() == false){
        moveto = graphicboard.handleMouseInput();
      }
      board.movePiece(movefrom, moveto);
      graphicboard.updateSelectedPiece(movefrom);
      cout << "--------\n";
      board.printBoard();
    }
  }catch(OutOfBounds& ex)
  {
    // Tratamento da exceção para posição fora dos limites do tabuleiro
    cout << "Erro: A posição (" << ex.p.row << ", " << ex.p.col << ") está fora dos limites do tabuleiro! \n";
  }

  return 0;
}