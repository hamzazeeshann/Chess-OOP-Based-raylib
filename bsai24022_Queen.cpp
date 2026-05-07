#include "bsai24022_Queen.h"
#include "bsai24022_Header.h"
#include "bsai24022_Board.h"

Queen::Queen(CLR c, Pos p, Board* b) : Pieces(c, p, b), Bishop(c, p, b), Rook(c, p, b) {}

void Queen::draw() {
    DrawTexture(B->pieceTextures[(int)clr][4], P.ci * 100, P.ri * 100, WHITE);
}

bool Queen::isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) {
    return Rook::isLegal2(B, sr, sc, er, ec) || Bishop::isLegal(B, sr, sc, er, ec);
}