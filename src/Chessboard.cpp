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
    
    isWhiteTurn = true;

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
                blackKingPos.col = col;
                blackKingPos.row = row;
                break;
            case 'K':
                board[row][col] = Piece(KING, WHITEn);
                whiteKingPos.col = col;
                whiteKingPos.row = row;
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
void Chessboard::printBoard()
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

    // Imprime a posição dos reis
    cout << "\n\n";
    cout << " Rei branco: " << whiteKingPos.row << " " << whiteKingPos.col << endl;
    cout << " Rei preto: " << blackKingPos.row << " " << blackKingPos.col << endl;
    cout << "\n\n";

    //Jogador atual:
    cout << "\nIsCheck: " << isCheck() << "\n\n";

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

    /**
     * @brief Move uma peça de uma posição de origem para uma posição de destino.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     */
void Chessboard::movePiece(const position& from, const position& to) {
    // Verifica se a posição de origem está vazia
    if (retPiece(from.row, from.col).getType() == EMPTY) {
        return; // Se estiver vazia, encerra a função (nenhuma peça para mover)
    }
    
    // Verifica se a peça na posição de origem tem a mesma cor da peça na posição de destino
    if (retPiece(from.row, from.col).getColor() == retPiece(to.row, to.col).getColor()) {
        return; // Se as peças tiverem a mesma cor, encerra a função (não é permitido mover para uma posição ocupada pela mesma cor)
    }
    
    // Verifica se a posição de destino está vazia e se o movimento é válido
    if (retPiece(from.row, from.col).getType() != EMPTY && retPiece(to.row, to.col).getType() == EMPTY && isValidMove(from, to)) {
        // Move a peça para a posição de destino, atualiza o tabuleiro e troca o turno
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY, EMPTY);
        isWhiteTurn = !isWhiteTurn;
        updateKingPosition(to);
    }
    
    // Verifica se a posição de destino está ocupada e se o movimento é válido
    if (retPiece(from.row, from.col).getType() != EMPTY && retPiece(to.row, to.col).getType() != EMPTY && isValidMove(from, to)) {
        // Captura a peça na posição de destino, move a peça de origem para lá, atualiza o tabuleiro e troca o turno
        board[to.row][to.col] = Piece(EMPTY, EMPTY);
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY, EMPTY);
        isWhiteTurn = !isWhiteTurn;
        updateKingPosition(to);
    }
}
    /**
     * @brief Atualiza a posição do rei após uma jogada.
     *
     * Esta função atualiza a posição do rei na estrutura de dados de posição após uma jogada
     * ser realizada.
     *
     * @param pos A posição após a jogada.
     */
    void Chessboard::updateKingPosition(const position& pos){
        // Verifica se a peça na posição 'pos' é um rei
        if(retPiece(pos.row,pos.col).getType() == KING){
            // Verifica se é o rei branco e atualiza sua posição se for
            if(retPiece(pos.row,pos.col).getColor() == WHITEn){
                whiteKingPos.row = pos.row;
                whiteKingPos.col = pos.col;
                return;
            }
            // Verifica se é o rei preto e atualiza sua posição se for
            if(retPiece(pos.row,pos.col).getColor() == BLACKn){
                blackKingPos.row = pos.row;
                blackKingPos.col = pos.col;
                return;
            }
        }
    }


    /**
     * @brief Verifica se o caminho entre duas posições está livre de obstáculos.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     * @return true se o caminho estiver livre, false caso contrário.
     */
bool Chessboard::isPathClear(const position& from, const position& to) const
{
    // Verifica se a posição inicial é a mesma que a posição final
    if (from.row == to.row && from.col == to.col)
    {
        return false; // Retorna falso se a posição inicial e final forem iguais (não há movimento)
    }

    int dRow = to.row - from.row; // Calcula a diferença nas linhas entre as posições
    int dCol = to.col - from.col; // Calcula a diferença nas colunas entre as posições

    // Movimento diagonal:
    if (abs(dRow) == abs(dCol))
    {
        // Define a direção do movimento na diagonal
        int dirRow = (dRow > 0) ? 1 : -1;
        int dirCol = (dCol > 0) ? 1 : -1;

        // Verifica o caminho diagonal entre as posições
        for (int curRow = from.row + dirRow, curCol = from.col + dirCol; curRow != to.row && curCol != to.col; curRow += dirRow, curCol += dirCol)
        {
            if (curRow > -1 && curRow < 8 && curCol > -1 && curCol < 8)
            {
                // Verifica se há peças no caminho diagonal
                if (retPiece(curRow, curCol).getType() != EMPTY)
                {
                    return false; // Retorna falso se houver uma peça no caminho
                }
            }
        }
    }

    // Movimento pelas linhas
    if (dCol == 0 && dRow != 0)
    {
        int dirRow = (dRow > 0) ? 1 : -1;

        // Verifica o caminho vertical entre as posições
        for (int curRow = from.row + dirRow; curRow != to.row; curRow += dirRow)
        {
            if (curRow > -1 && curRow < 8)
            {
                // Verifica se há peças no caminho vertical
                if (retPiece(curRow, from.col).getType() != EMPTY)
                {
                    return false; // Retorna falso se houver uma peça no caminho
                }
            }
        }
    }

    // Movimento pelas colunas
    if (dCol != 0 && dRow == 0)
    {
        int dirCol = (dCol > 0) ? 1 : -1;

        // Verifica o caminho horizontal entre as posições
        for (int curCol = from.col + dirCol; curCol != to.col; curCol += dirCol)
        {
            if (curCol > -1 && curCol < 8)
            {
                // Verifica se há peças no caminho horizontal
                if (retPiece(from.row, curCol).getType() != EMPTY)
                {
                    return false; // Retorna falso se houver uma peça no caminho
                }
            }
        }
    }

    return true; // Retorna verdadeiro se o caminho estiver livre entre as posições
}

    /**
     * @brief Verifica se um movimento de uma posição para outra é válido.
     *
     * @param from A posição de origem.
     * @param to A posição de destino.
     * @return true se o movimento for válido, false caso contrário.
     */
bool Chessboard::isValidMove(const position& from, const position& to) const {
    // Verifica se o caminho entre as posições está livre de obstáculos
    bool isitclear = isPathClear(from, to);
    
    // Se o caminho não estiver livre, retorna falso
    if (isitclear == false) {
                return false;
    }
    
    // Verifica se é o turno das peças brancas e se a peça na posição de origem é preta
    if (isWhiteTurn && retPiece(from.row, from.col).getColor() == BLACKn) {
                return false; // Retorna falso se for o turno das brancas e a peça na posição de origem for preta
    }
    
    // Verifica se não é o turno das peças brancas e se a peça na posição de origem é branca
    if (!isWhiteTurn && retPiece(from.row, from.col).getColor() == WHITEn) {
                return false; // Retorna falso se não for o turno das brancas e a peça na posição de origem for branca
    }
    
    // Verifica o tipo de peça na posição de origem e chama o método correspondente para validar o movimento
    switch (retPiece(from.row, from.col).getType()) {
        case KING: {
            King k(retPiece(from.row, from.col).getColor());
            return k.isValidKingMove(from.col, from.row, to.col, to.row);
        }
        case PAWN: {
            Pawn p(retPiece(from.row, from.col).getColor());
            return p.isValidPawnMove(from.col, from.row, to.col, to.row, board[to.row][to.col].getColor());
        }
        case BISHOP: {
            Bishop b(retPiece(from.row, from.col).getColor());
            return b.isValidBishopMove(from.col, from.row, to.col, to.row);
        }
        case QUEEN: {
            Queen q(retPiece(from.row, from.col).getColor());
            return q.isValidQueenMove(from.col, from.row, to.col, to.row);
        }
        case KNIGHT: {
            Knight n(retPiece(from.row, from.col).getColor());
            return n.isValidKnightMove(from.col, from.row, to.col, to.row);
        }
        case ROOK: {
            Rook r(retPiece(from.row, from.col).getColor());
            return r.isValidRookMove(from.col, from.row, to.col, to.row);
        }
    }
    return false; // Retorna falso se nenhum movimento válido foi encontrado
}

    /**
     * @brief Obtém uma lista de destinos possíveis para uma peça em uma determinada posição.
     *
     * @param from A posição da peça.
     * @return Uma lista de posições possíveis de destino.
     */
list<position> Chessboard::getPossibleDestinations(const position& from)
{
    // Lista que armazenará os destinos possíveis
    list<position> lista_;

    // Vetores de direções para linhas e colunas
    vector<int> dirRow = {1, -1};
    vector<int> dirCol = {1, -1};

    // Verifica o tipo de peça na posição inicial
    switch (retPiece(from.row, from.col).getType())
    {

    case KING:
    {
        // Direções possíveis para o Rei (horizontal, vertical e diagonal)
        vector<int> kdirRow = {0, 1, -1};
        vector<int> kdirCol = {0, 1, -1};

        // Itera sobre as direções possíveis para o Rei
        for (int dr : kdirRow)
        {
            for (int dc : kdirCol)
            {
                position dest = {from.row + dr, from.col + dc};
                // Verifica se a posição de destino está dentro do tabuleiro
                if (dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1)
                {
                    // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest); // Adiciona a posição de destino à lista
                    }
                }
            }
        }
        break;
    }

    case PAWN:
    {
        vector<int> PdirRow = {-1, -2, 1, 2}; // Vetor de movimentos possíveis para as linhas do peão
        vector<int> PdirCol = {0, 1, -1}; // Vetor de movimentos possíveis para as colunas do peão
        
        // Itera sobre as direções possíveis para o peão
        for (int dr : PdirRow)
        {
            for (int dc : PdirCol)
            {
                position dest = {from.row + dr, from.col + dc}; // Calcula a posição de destino para o peão
                    
                // Verifica se a posição de destino está dentro do tabuleiro
                if (dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1)
                {
                    // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                    }
                }
            }
        }
        break;
    }
    
    case BISHOP:
    {
        // movimento diagonal do bispo
        for (int dr : dirRow)
        {
            for (int dc : dirCol)
            {
                // Percorre na diagonal a partir da posição atual (from)
                for (int curRow = from.row + dr, curCol = from.col + dc; curRow < BOARD_SIZE && curRow > -1 && curCol < BOARD_SIZE && curCol > -1; curCol += dc, curRow += dr)
                {
                    position dest = {curRow, curCol}; // Calcula a posição de destino na diagonal
                    
                    // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                    }
                    else
                    {
                        break; // Sai do loop caso o movimento não seja válido ou se encontrar uma peça na diagonal
                    }
                }
            }
        }

        break;
    }
        
    case QUEEN:
    {
        // Movimento vertical (pelas linhas)
        for (int dr : dirRow)
        {
            for (int curRow = from.row + dr; curRow < BOARD_SIZE && curRow > -1; curRow += dr)
            {
                position dest = {curRow, from.col}; // Calcula a posição de destino na linha
                    
                // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                }
                else
                {
                    break; // Sai do loop se encontrar uma peça no caminho ou se a posição não for válida
                }
            }
        }
        
        // Movimento horizontal (pelas colunas)
        for (int dc : dirCol)
        {
            for (int curCol = from.col + dc; curCol < BOARD_SIZE && curCol > -1; curCol += dc)
            {
                position dest = {from.row, curCol}; // Calcula a posição de destino na coluna
                    
                // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                }
                else
                {
                    break; // Sai do loop se encontrar uma peça no caminho ou se a posição não for válida
                }
            }
        }

        // Movimento diagonal
        for (int dr : dirRow)
        {
            for (int dc : dirCol)
            {
                for (int curRow = from.row + dr, curCol = from.col + dc; curRow < BOARD_SIZE && curRow > -1 && curCol < BOARD_SIZE && curCol > -1; curCol += dc, curRow += dr)
                {
                    position dest = {curRow, curCol}; // Calcula a posição de destino na diagonal
                        
                    // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                    }
                    else
                    {
                        break; // Sai do loop se encontrar uma peça no caminho ou se a posição não for válida
                    }
                }
            }
        }

        break;
    }

    case KNIGHT:
    {
        // Vetor de posições válidas para o movimento do cavalo em L
        vector<position> validmoves = {{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};
        
        // Itera sobre as posições válidas para o movimento do cavalo
        for (int i = 0; i < (int) validmoves.size(); i++)
        {
            position dest = {from.row + validmoves[i].row , from.col + validmoves[i].col }; // Calcula a posição de destino
            
            // Verifica se a posição de destino está dentro do tabuleiro
            if( dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1 )
            { 
                // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                }
            }
        }

        break;
    }
        
    case ROOK:
    {
        // Movimento vertical (pelas linhas)
        for (int dr : dirRow)
        {
            for (int curRow = from.row + dr; curRow < BOARD_SIZE && curRow > -1; curRow += dr)
            {
                position dest = {curRow, from.col}; // Calcula a posição de destino na linha
                    
                // Verifica se a posição de destino está dentro do tabuleiro
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                }
                else
                {
                    break; // Sai do loop se encontrar uma peça no caminho ou se a posição não for válida
                }
            }
        }
        
        // Movimento horizontal (pelas colunas)
        for (int dc : dirCol)
        {
            for (int curCol = from.col + dc; curCol < BOARD_SIZE && curCol > -1; curCol += dc)
            {
                position dest = {from.row, curCol}; // Calcula a posição de destino na coluna
                    
                // Verifica se a posição de destino está dentro do tabuleiro
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                }
                else
                {
                    break; // Sai do loop se encontrar uma peça no caminho ou se a posição não for válida
                }
            }
        }
        break;
    }

    }
    
    return lista_;
}

// gerar todos os movimentos do OPONENTE!
list<position> Chessboard::getAllPossibleMoves(){
    isWhiteTurn = !isWhiteTurn;

    // Lista que armazenará os destinos possíveis
    list<position> lista_;

    // Vetores de direções para linhas e colunas
    vector<int> dirRow = {1, -1};
    vector<int> dirCol = {1, -1};
    for(int from_row = 0; from_row < 8; from_row++){
        for(int from_col = 0; from_col < 8; from_col++){
            position from = {from_row,from_col};            

            // Verifica o tipo de peça na posição inicial
            switch (retPiece(from_row, from_col).getType())
            {
                
            case KING:
            {
                // Direções possíveis para o Rei (horizontal, vertical e diagonal)
                vector<int> kdirRow = {0, 1, -1};
                vector<int> kdirCol = {0, 1, -1};

                // Itera sobre as direções possíveis para o Rei
                for (int dr : kdirRow)
                {
                    for (int dc : kdirCol)
                    {
                        position dest = {from_row + dr, from_col + dc};
                        // Verifica se a posição de destino está dentro do tabuleiro
                        if (dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1)
                        {
                            // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                            if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor())
                            {
                                lista_.push_back(dest); // Adiciona a posição de destino à lista
                            }
                        }
                    }
                }
                break;
            }
            case PAWN:
            {
                vector<int> PdirRow;
                vector<int> PdirCol;

                // Define as direções de movimento do peão com base na cor (branco ou preto)
                if (retPiece(from_row, from_col).getColor() == WHITEn) {
                    PdirRow = {-1,-2}; // Peão branco move para cima (linhas decrescentes)
                } else {
                    PdirRow = {1,2}; // Peão preto move para baixo (linhas crescentes)
                }
                
                PdirCol = {0}; // O peão move-se somente verticalmente
                
                for (int dr : PdirRow)
                {
                    for (int dc : PdirCol)
                    {
                        position dest = {from_row + dr, from_col + dc}; // Calcula a posição de destino para o peão
                                    
                        // Verifica se a posição de destino está dentro do tabuleiro
                        if (dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1)
                        {
                            // Verifica se o movimento é válido e se a posição de destino está vazia
                            if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getType() == EMPTY && dest.col == from.col)
                            {
                                lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                            }
                        }
                    }
                }

                // Captura diagonal
                vector<int> captureCols = {1, -1}; // Colunas para captura diagonal
                for (int dr : PdirRow)
                {
                    for (int dc : captureCols)
                    {
                        position dest = {from_row + dr, from_col + dc}; // Calcula a posição de destino para a captura diagonal
                                        
                        // Verifica se a posição de destino está dentro do tabuleiro e se é uma peça adversária
                        if (dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1 &&
                            isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor() &&
                            abs(dc) == 1) // Movimento diagonal (coluna alterada)
                        {
                            lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                        }
                    }
                }
                break;
            }
            case BISHOP:
            {
                // movimento diagonal do bispo
                for (int dr : dirRow)
                {
                    for (int dc : dirCol)
                    {
                        // Percorre na diagonal a partir da posição atual (from)
                        for (int curRow = from_row + dr, curCol = from_col + dc; curRow < BOARD_SIZE && curRow > -1 && curCol < BOARD_SIZE && curCol > -1; curCol += dc, curRow += dr)
                        {
                            position dest = {curRow, curCol}; // Calcula a posição de destino na diagonal
                            
                            // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                            if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor() && (dest.row != from.row) && (dest.col != from.col))
                            {
                                lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                            }
                        }
                    }
                }
                break;
            }
                
            case QUEEN:
            {
                // Movimento vertical (pelas linhas)
                for (int dr : dirRow)
                {
                    for (int curRow = from_row + dr; curRow < BOARD_SIZE && curRow > -1; curRow += dr)
                    {
                        position dest = {curRow, from_col}; // Calcula a posição de destino na linha
                            
                        // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                        if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor())
                        {
                            lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                        }
                    }
                }
                
                // Movimento horizontal (pelas colunas)
                for (int dc : dirCol)
                {
                    for (int curCol = from_col + dc; curCol < BOARD_SIZE && curCol > -1; curCol += dc)
                    {
                        position dest = {from_row, curCol}; // Calcula a posição de destino na coluna
                            
                        // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                        if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor())
                        {
                            lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                        }
                    }
                }

                // Movimento diagonal
                for (int dr : dirRow)
                {
                    for (int dc : dirCol)
                    {
                        for (int curRow = from_row + dr, curCol = from_col + dc; curRow < BOARD_SIZE && curRow > -1 && curCol < BOARD_SIZE && curCol > -1; curCol += dc, curRow += dr)
                        {
                            position dest = {curRow, curCol}; // Calcula a posição de destino na diagonal
                                
                            // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                            if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor())
                            {
                                lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                            }

                        }
                    }
                }
                break;
            }

            case KNIGHT:
            {
                // Vetor de posições válidas para o movimento do cavalo em L
                vector<position> validmoves = {{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};
                
                // Itera sobre as posições válidas para o movimento do cavalo
                for (int i = 0; i < (int) validmoves.size(); i++)
                {
                    position dest = {from_row + validmoves[i].row , from_col + validmoves[i].col }; // Calcula a posição de destino
                    
                    // Verifica se a posição de destino está dentro do tabuleiro
                    if( dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1 )
                    { 
                        // Verifica se o movimento é válido e se a peça na posição de destino é de cor diferente
                        if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor())
                        {
                            lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                        }
                    }
                }
                break;
            }
                
            case ROOK:
            {
                // Movimento vertical (pelas linhas)
                for (int dr : dirRow)
                {
                    for (int curRow = from_row + dr; curRow < BOARD_SIZE && curRow > -1; curRow += dr)
                    {
                        position dest = {curRow, from_col}; // Calcula a posição de destino na linha
                            
                        // Verifica se a posição de destino está dentro do tabuleiro
                        if (isValidMove(from, dest) && ( (retPiece(dest.row, dest.col).getType() == EMPTY) 
                        || (retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor()) ))                        {
                            lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                        }
                    }
                }
                
                // Movimento horizontal (pelas colunas)
                for (int dc : dirCol)
                {
                    for (int curCol = from_col + dc; curCol < BOARD_SIZE && curCol > -1; curCol += dc)
                    {
                        position dest = {from_row, curCol}; // Calcula a posição de destino na coluna
                            
                        // Verifica se a posição de destino está dentro do tabuleiro
                        // Verifica se a posição de destino está dentro do tabuleiro
                        if (isValidMove(from, dest) && ( (retPiece(dest.row, dest.col).getType() == EMPTY) 
                        || (retPiece(dest.row, dest.col).getColor() != retPiece(from_row, from_col).getColor()) ) )
                        {
                            lista_.push_back(dest); // Adiciona a posição de destino à lista de destinos possíveis
                        }
                    }
                }
                break;
            }

            }
        }
    }   
    isWhiteTurn = !isWhiteTurn; 
    return lista_; 
}

bool Chessboard::isPieceUnderAtack(const position& pos){
    list<position> lista_ = getAllPossibleMoves();
    for(auto it = lista_.begin(); it != lista_.end(); it++){
        if ( (it->col == pos.col) && (it->row == pos.row)){
            return true;
        }
    }
    return false;
}

bool Chessboard::leavesKingInCheck(const position& from, const position& to) const{
    
}

bool Chessboard::isCheck(){
    if(isWhiteTurn){
        return isPieceUnderAtack(whiteKingPos);
    }
    if(!isWhiteTurn){
        return isPieceUnderAtack(blackKingPos);
    }
    return false;
}
