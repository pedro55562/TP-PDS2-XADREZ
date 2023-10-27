CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
ASSETS_DIR = assets
EXE = ChessGame

ASSETS = $(ASSETS_DIR)/images/chess_pieces/ $(ASSETS_DIR)/sounds/ $(ASSETS_DIR)/fonts/ $(ASSETS_DIR)/config/ $(ASSETS_DIR)/other_assets/

DEBUG_FLAGS = -O0 -g -DEBUG

RAYLIB_LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
RAYLIB_INCLUDE = -I/usr/local/include/ 

OBJ = $(addprefix $(BUILD_DIR)/, main.o Chessboard.o Piece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o ChessRenderer.o)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXE) $(RAYLIB_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(RAYLIB_INCLUDE) -I$(INCLUDE_DIR) -c $< -o $@

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(EXE)

clean:
	rm -rf $(BUILD_DIR)/*
	rm ChessGame
	
run:
	./$(EXE)


.PHONY: debug clean run
