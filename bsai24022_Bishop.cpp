#include "bsai24022_Bishop.h"
#include "bsai24022_Header.h"
#include "bsai24022_Board.h"

Bishop::Bishop(CLR c, Pos p, Board* b) : Pieces(c, p, b) {}

void Bishop::draw() {
    DrawTexture(B->pieceTextures[(int)clr][2], P.ci * 100, P.ri * 100, WHITE);
}

bool Bishop::isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) {
    return isDiagonalMove(sr, sc, er, ec) && DPC(B, sr, sc, er, ec);
}