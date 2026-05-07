#include "bsai24022_Rook.h"
#include "bsai24022_Header.h"
#include "bsai24022_Board.h"

Rook::Rook(CLR c, Pos p, Board* b) : Pieces(c, p, b), hasMoved(false) {}

void Rook::draw() {
    DrawTexture(B->pieceTextures[(int)clr][3], P.ci * 100, P.ri * 100, WHITE);
}



bool Rook::isLegal2(Pieces* B[8][8], int sr, int sc, int er, int ec) {
    return (isHorizontalMove(sr, sc, er, ec) && HPC(B, sr, sc, er, ec)) ||
        (isVerticalMove(sr, sc, er, ec) && VPC(B, sr, sc, er, ec));


}

bool Rook::isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) {
    return (isHorizontalMove2(sr, sc, er, ec) && HPC2(B, sr, sc, er, ec)) ||
        (isVerticalMove2(sr, sc, er, ec) && VPC2(B, sr, sc, er, ec)) || (isDiagonalMove2(sr, sc, er, ec) && DPC2(B, sr, sc, er, ec));


}
void Rook::setMoved() {
    hasMoved = true; 
}

bool Rook:: getMoved() {
    return hasMoved; 
}