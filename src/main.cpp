/*
  *****************************************************
  *                                                   *
  * O Lord, Thank you for your goodness in our lives. *
  *     Please bless this code to our compilers.      *
  *                     Amen.                         *
  *                                                   *
  *****************************************************
*/

#include "../include/ChessRenderer.h"
#include "../include/Chessboard.h"

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

int main (){
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
  
  return 0;
}