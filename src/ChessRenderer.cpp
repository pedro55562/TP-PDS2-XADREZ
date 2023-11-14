#include "../include/ChessRenderer.h"

#include <list>
#include <raylib.h>
#include <iostream>
#include "ChessRenderer.h"

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
