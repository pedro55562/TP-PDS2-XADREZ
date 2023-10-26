all:

Bishop:
	g++ -c ./src/Bishop.cpp -I .include -o ./build/Bishop.o

ChessRenderer:
	g++ -c ./src/ChessRenderer.cpp -I .include -o ./build/ChessRenderer.o

Chess_constants:
	g++ -c ./src/Chess_constants.cpp -I .include -o ./build/Chess_constants.o

Chessboard:
	g++ -c ./src/Chessboard.cpp -I .include -o ./build/Chessboard.o

King:
	g++ -c ./src/King.cpp -I .include -o ./build/King.o

Knight:
	g++ -c ./src/Knight.cpp -I .include -o ./build/Knight.o

Pawn:
	g++ -c ./src/Pawn.cpp -I .include -o ./build/Pawn.o

Piece:
	g++ -c ./src/Piece.cpp -I .include -o ./build/Piece.o

Queen:
	g++ -c ./src/Queen.cpp -I .include -o ./build/Queen.o

Rook:
	g++ -c ./src/Rook.cpp -I .include -o ./build/Rook.o

clear:
	clear
	