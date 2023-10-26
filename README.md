# TP-PDS2-XADREZ

## 1. Tema escolhido
- Jogo de Xadrez

## 2. Integrantes do grupo
- Pedro Antonio de Souza Campos Rodrigues
- Ítalo Nunes Pereira Vieira

## 3. Apresentação do Problema

// apresentar o problema

## 4. Visão Geral da Solução

// visao geral

## 5. Estrutura do Projeto

// estrutura do projeto

## 6. Instruções de Instalação

// instruçoes de instalação 


## 7. Instruções de Uso

// instruçoes de uso

## 8. Principais Dificuldades

// O tópico será escrito ao término do projeto

## Cartões CRC (Classe, Responsabilidade, Colaborador):

| Chessboard  |
|----------------|
| **Descrição:** A classe `Chessboard` representa um tabuleiro de xadrez e lida com operações relacionadas à configuração do tabuleiro, movimento de peças e verificação de regras do xadrez. O tabuleiro é representado por uma matriz 8x8, onde cada elemento é um objeto `Piece`. |
| **Responsabilidades** | 
| - Montar o tabuleiro a partir de uma configuração FEN padrão ou personalizada. |
| - Imprimir o tabuleiro na saída padrão. |
| - Retornar uma peça em uma determinada posição do tabuleiro. |
| - Mover uma peça do tabuleiro a partir das coordenadas de origem e destino. |
| - Verificar se um movimento é válido de acordo com as regras do xadrez. |
| - Verificar se o caminho entre duas posições está limpo para um movimento de peça. |
| - Retornar uma lista de destinos possíveis para uma peça em uma determinada posição. |
| **Colaboradores**     |
| - `Piece`: A classe `Piece` é usada para representar as peças de xadrez no tabuleiro. |
| - `Bishop`, `Pawn`, `Knight`, `Queen`, `King`, `Rook`: Essas classes representam tipos específicos de peças de xadrez e são usadas para criar e gerenciar as peças no tabuleiro. |
| - `Chess_constants`: Arquivo para armazenar algumas constantes relacionadas ao xadrez|
| - `position`: A estrutura `position` é usada para representar as coordenadas de linha e coluna no tabuleiro. |

| ChessRenderer  |
|----------------|
| **Descrição:** A classe `ChessRenderer` lida com a renderização gráfica de um jogo de xadrez, incluindo o tabuleiro, peças e interações do usuário. Um dos membros privados da classe é uma referência
ao estado do tabuleiro no backend. |
| **Responsabilidades** | 
| - Iniciar a janela de renderização e carregar texturas das peças de xadrez. |
| - Lidar com a renderização geral do jogo de xadrez. |
| - Renderizar o fundo do tabuleiro. |
| - Renderizar as peças de xadrez no tabuleiro. |
| - Renderizar marcações de destinos possíveis. |
| - Tratar entrada do mouse e retornar a posição do clique no formato da estrutura position.|
| - Encerrar a janela de renderização e descarregar texturas. |
| **Colaboradores**     |
| - `Chessboard`: A classe `Chessboard` é usada para obter informações sobre o estado do jogo de xadrez. |
| - `Bishop`, `Pawn`, `Knight`, `Queen`, `King`, `Rook`, `Piece`: Classes que representam as peças de xadrez e são usadas para carregar texturas e renderizar peças. |
| - `Chess_constants`: Arquivo que contém constantes relacionadas ao xadrez. |
| - `raylib`: Biblioteca utilizada para renderização gráfica e interações com o usuário. |

| Piece  |
|----------------|
| **Descrição:** A classe `Piece` representa uma peça no jogo de xadrez, armazenando informações sobre seu tipo e cor.
| **Responsabilidades** | 
| - Armazenar o tipo (como peão, torre, rainha, etc.) de uma peça no jogo de xadrez.
| - Armazenar a cor (branca ou preta) da peça no jogo de xadrez. |
| **Colaboradores**     |
| - Nenhum colaborador direto, mas faz uso das constantes definidas em "Chess_constants.h" para representar o tipo de peça (como `EMPTY`, `PAWN`, `ROOK`, etc.). |


| Pawn  |
|----------------|
| **Descrição:** A classe `Pawn` representa o peão no jogo de xadrez. Ela herda da classe `Piece` e é responsável por verificar se os movimentos do peão são válidos de acordo com as regras do xadrez. |
| **Responsabilidades** | 
| - Verificar se um movimento de peão é válido, considerando a posição de origem, a posição de destino e a cor das peças.
| - Implementar a lógica de ataque do peão, onde ele pode mover-se diagonalmente uma casa para capturar uma peça adversária.
| - Gerenciar a capacidade do peão de mover-se duas casas na primeira jogada, desde que não haja obstruções em seu caminho. |
| **Colaboradores**     |
| - `Piece`: A classe `Piece` é herdada e usada para obter informações sobre o tipo e a cor do peão. |
| - `Chess_constants`: Arquivo que contém constantes relacionadas ao xadrez. |
| - `Chessboard`: A classe `Chessboard` não é diretamente usada nesta classe, mas é relevante para o contexto do jogo de xadrez. |
| - `position`: A estrutura `position` é usada para representar as coordenadas de linha e coluna no tabuleiro de xadrez. |


## User Stories:

**User Story 1 - Iniciar um novo jogo**
- **Descrição:** Como um jogador, quero iniciar um novo jogo para jogar
- **Critérios de Aceitação:**
- Ao ser iniciado, as peças devem estar na posição inicial de acordo com as regras
- O jogador branco deve começar o jogo

**User Story 2 - Interface gráfica**
- **Descrição:** Como um jogador, quero um jogo com uma interface grafica interativa
- **Critérios de Aceitação:**
- O jogo deve ter uma interface gráfica que inclua um tabuleiro de xadrez e peças claramente visíveis.
- O jogador deve ser capaz de interagir com o jogo por meio da interface gráfica.

**User Story 3 - Movimentar Peças no Tabuleiro**
- **Descrição:** Como um jogador, quero poder mover as peças no tabuleiro usando o mouse.
- **Critérios de Aceitação:**
- Para mover uma peça, o jogador deve clicar em uma peça e em seguida ele deve clicar na casa de destino.
- Após cada movimento, o jogo deve atualizar o estado do tabuleiro.
- Após cada movimento, o turno deve ser passado para o outro jogador.

 **User Story 4 - Validar movimentos de acordo com as regras**
- **Descrição:** Como um jogador, quero que o jogo valide meus movimentos de acordo com as regras do xadrez, para evitar movimentos ilegais.
- **Critérios de Aceitação:**
- O jogo deve verificar se o movimento de uma peça é legal de acordo com as regras do xadrez.
- Se um jogador tentar realizar um movimento ilegal, o jogo deve impedir que o movimento seja executado.
- Os movimentos legais devem ser permitidos.

 **User Story 5 - Visualizar possiveis destinos**
- **Descrição:** Como um jogador, quero poder ver os possiveis destinos ao clicar em uma peça.
- **Critérios de Aceitação:**
- Ao clicar em uma peça, o jogo deve mostrar as posições para as quais essa peça pode se mover.
- O realce deve ser removido quando o jogador realizar um movimento ou desselecionar a peça.

 **User Story 6 - Xeque**
- **Descrição:** Como um jogador, quero que o xeque esteja implementdado.
- **Critérios de Aceitação:**
- O movimento que colocou o rei em xeque deve ser legal de acordo com as regras do jogo.
- O jogo deve continuar após o xeque, permitindo que o jogador em xeque tome medidas para sair da situação.
- Após um xeque, o jogador deve ser capaz de realizar qualquer movimento legal, incluindo o movimento do rei, desde que ele saia do xeque.

**User Story 7 - Xeque-mate**
- **Descrição:** Como um jogador, quero que o xeque-mate esteja implementdado.
- **Critérios de Aceitação:**
- O sistema deve reconhecer e declarar o xeque-mate quando o rei de um jogador estiver em xeque, e não houver nenhum movimento legal disponível para sair do xeque.
- Deve ser impossível para o jogador em xeque-mate realizar qualquer ação que o tire da situação, pois não há movimentos legais disponíveis.
- Os movimentos que levaram ao xeque-mate devem ser legais de acordo com as regras do xadrez.






