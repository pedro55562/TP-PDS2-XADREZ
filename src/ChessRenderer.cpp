#include "../include/ChessRenderer.h"

#include <list>
#include <raylib.h>
#include <iostream>

using std::list;


// Construtor da classe ChessRenderer
ChessRenderer::ChessRenderer(Chessboard &chboard) : board(chboard)
{
  // Inicializa a posição da peça selecionada como (0,0) e indica que nenhuma peça está selecionada
  SelectedPiece = {0,0};
  isPieceSelected = false;

  // Inicializa a janela com o tamanho especificado, título "Chess" e uma taxa de atualização de 30 quadros por segundo
  InitWindow(pixels, pixels, "Chess");
  shouldclose_ = false; // Inicializa shouldclose_ como falso
  SetTargetFPS(30);

  // Carrega as texturas das peças a partir dos arquivos de imagem
  BISHOP_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/BISHOP_BLACK.png"));
  KING_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KING_BLACK.png"));
  QUEEN_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/QUEEN_BLACK.png"));
  ROOK_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/ROOK_BLACK.png"));
  KNIGHT_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KNIGHT_BLACK.png"));
  PAWN_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/PAWN_BLACK.png"));

  BISHOP_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/BISHOP_WHITE.png"));
  KING_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KING_WHITE.png"));
  QUEEN_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/QUEEN_WHITE.png"));
  ROOK_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/ROOK_WHITE.png"));
  KNIGHT_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KNIGHT_WHITE.png"));
  PAWN_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/PAWN_WHITE.png"));
}


// Renderiza o quadrado do tabuleiro na posição (row, col) com a cor apropriada (claro ou escuro).
void ChessRenderer::renderBoard(const int& row, const int& col) const
{
  // Verifica se a soma de linha e coluna é par ou ímpar para determinar a cor do quadrado
  bool isLight = (row + col) % 2 == 0;

  // Se for um quadrado claro, desenha um retângulo com a cor "light", caso contrário, com a cor "dark"
  if (isLight)
  {
    DrawRectangle(col * squaresize, row * squaresize, squaresize, squaresize, light);
  }
  else
  {
    DrawRectangle(col * squaresize, row * squaresize, squaresize, squaresize, dark);
  }
}


// Renderiza uma peça na posição especificada com a textura fornecida.
void ChessRenderer::renderPiece(const Texture2D& pieceTexture, const int& col, const int& row) const
{
  Vector2 temp;
  temp.x = col * squaresize; // Calcula a coordenada x na tela com base na coluna
  temp.y = row * squaresize; // Calcula a coordenada y na tela com base na linha

  // Desenha a textura da peça na posição (x, y) com uma rotação de 0 graus, escala de 0.125 e cor branca
  DrawTextureEx(pieceTexture, temp, 0, 0.125, WHITE);
}


// Destrutor da classe ChessRenderer
ChessRenderer::~ChessRenderer()
{
  // Descarrega as texturas das peças e fecha a janela
  UnloadTexture(BISHOP_BLACK);
  UnloadTexture(KING_BLACK);
  UnloadTexture(QUEEN_BLACK);
  UnloadTexture(ROOK_BLACK);
  UnloadTexture(KNIGHT_BLACK);
  UnloadTexture(PAWN_BLACK);

  UnloadTexture(BISHOP_WHITE);
  UnloadTexture(KING_WHITE);
  UnloadTexture(QUEEN_WHITE);
  UnloadTexture(ROOK_WHITE);
  UnloadTexture(KNIGHT_WHITE);
  UnloadTexture(PAWN_WHITE);

  CloseWindow(); // Fecha a janela
}
