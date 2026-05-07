#pragma once
#include "bsai24022_Pieces.h"

class Board {
private:
    Pieces* B[8][8];
    CLR t;
public:
    Texture2D boardTexture;

    Texture2D pieceTextures[2][6];
public:
    Board();
    Board(string filename);
    void play();
    Pieces* PieceAt(Pos P);
    bool isValidPiece(Pieces* B[8][8], int r, int c, CLR turn);
    bool isValidBox(Pieces* B[8][8], int r, int c, CLR turn);
    void HighlightPiece(int sr, int sc, Pieces* B[][8], Color clr);
    void moveHighlight(int sr, int sc, CLR turn);
    bool isCheck(CLR turn);
    bool isCheckmate(CLR turn);
    bool isStalemate(CLR turn);
    void promotion(CLR turn);
    void promotion2(CLR turn, int sr, int sc);
    void saveToFile(string filename);
    ~Board();
};