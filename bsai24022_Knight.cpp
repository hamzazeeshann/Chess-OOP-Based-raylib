#include "bsai24022_Knight.h"
#include "bsai24022_Header.h"

Knight::Knight(CLR c, Pos p, Board* b) : Pieces(c, p, b) {}

void Knight::draw() {
    DrawTexture(B->pieceTextures[(int)clr][1], P.ci * 100, P.ri * 100, WHITE);
}
bool Knight ::isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) {
    return ((er - sr) * (er - sr) + (ec - sc) * (ec - sc)) == 5;
}