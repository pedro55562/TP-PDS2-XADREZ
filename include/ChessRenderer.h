/**
 * @file ChessRenderer.h
 * @brief Declara a classe ChessRenderer para renderizar o tabuleiro de xadrez e peças.
 */

#ifndef CHESSRENDER_H
#define CHESSRENDER_H

#include "Chessboard.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#include "Chess_constants.h"

#include <raylib.h>

/**
 * @defgroup ChessConstants Constantes do Tabuleiro
 * @{
 */
const int size = 8; ///< Tamanho do tabuleiro (8x8).
const int pixels = 800; ///< Tamanho da janela em pixels.
const int squaresize = pixels / size; ///< Tamanho de cada casa do tabuleiro em pixels.
/** @} */

/**
 * @defgroup ChessColors Cores do Tabuleiro
 * @{
 */
const Color dark = {161, 111, 90, 255}; ///< Cor escura do tabuleiro.
const Color light = {235, 210, 184, 255}; ///< Cor clara do tabuleiro.
const Color red_ = {230, 41, 55, 60}; ///< Cor vermelha para destinos possíveis.
/** @} */

/**
 * @class ChessRenderer
 * @brief Classe para renderizar o tabuleiro de xadrez e as peças.
 */
class ChessRenderer {

private:
    bool shouldClose; ///< Indica se a janela deve ser fechada.
    Chessboard& board; ///< Referência para o tabuleiro do backend.

    position SelectedPiece; ///< Armazena a posição da peça selecionada.
    bool isPieceSelected; ///< Indica se alguma peça está selecionada.

    /**
     * @defgroup ChessTextures Texturas das Peças
     * @{
     * @brief As texturas das peças serão carregadas a partir do diretório "./assets/images/chess_pieces".
     */
    Texture2D BISHOP_BLACK; ///< Textura para o bispo preto.
    Texture2D KING_BLACK; ///< Textura para o rei preto.
    Texture2D QUEEN_BLACK; ///< Textura para a rainha preta.
    Texture2D ROOK_BLACK; ///< Textura para a torre preta.
    Texture2D KNIGHT_BLACK; ///< Textura para o cavaleiro preto.
    Texture2D PAWN_BLACK; ///< Textura para o peão preto.

    Texture2D BISHOP_WHITE; ///< Textura para o bispo branco.
    Texture2D KING_WHITE; ///< Textura para o rei branco.
    Texture2D QUEEN_WHITE; ///< Textura para a rainha branca.
    Texture2D ROOK_WHITE; ///< Textura para a torre branca.
    Texture2D KNIGHT_WHITE; ///< Textura para o cavaleiro branco.
    Texture2D PAWN_WHITE; ///< Textura para o peão branco.
    /** @} */

    /**
     * @brief Renderiza o tabuleiro (fundo) na tela.
     *
     * @param row A linha atual.
     * @param col A coluna atual.
     */
    void renderBoard(const int row, const int col) const;

    /**
     * @brief Renderiza uma peça na posição especificada.
     *
     * @param pieceTexture Textura da peça a ser renderizada.
     * @param col A coluna da posição.
     * @param row A linha da posição.
     */
    void renderPiece(const Texture2D pieceTexture, const int col, const int row) const;

    /**
     * @brief Renderiza marcações nos destinos possíveis.
     *
     * @param from A posição de origem da peça.
     */
    void renderPossibleDestinations(const position from) const;

public:
    /**
     * @brief Construtor da classe ChessRenderer.
     *
     * Inicia a janela e carrega as texturas das peças.
     *
     * @param chessboard Referência para o tabuleiro de xadrez.
     */
    ChessRenderer(Chessboard& chessboard);

    /**
     * @brief Destrutor da classe ChessRenderer.
     *
     * Descarrega as texturas e fecha a janela.
     */
    ~ChessRenderer();

    /**
     * @brief Função principal de renderização.
     */
    void render();

    /**
     * @brief Verifica se a janela deve ser fechada.
     *
     * @return true se a janela deve ser fechada, false caso contrário.
     */
    bool shouldClose() const;

    /**
     * @brief Lida com a entrada do mouse para obter a posição de clique.
     *
     * @return A posição do clique do mouse, convertida de pixels para linhas e colunas.
     */
    position handleMouseInput();

    /**
     * @brief Atualiza a peça selecionada.
     *
     * @param from A posição de origem da peça selecionada.
     */
    void updateSelectedPiece(const position from);
};

#endif
