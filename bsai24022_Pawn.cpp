#include "bsai24022_Pawn.h"
#include "bsai24022_Header.h"
#include "bsai24022_Board.h"

Pawn::Pawn(CLR c, Pos p, Board* b) : Pieces(c, p, b) {}

void Pawn::draw() {
    DrawTexture(B->pieceTextures[(int)clr][0], P.ci * 100, P.ri * 100, WHITE);
}

bool Pawn::isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) {
    if (sr < 0 || sr >= 8 || sc < 0 || sc >= 8 || er < 0 || er >= 8 || ec < 0 || ec >= 8) {
        return false;
    }

    int fd;
    int sr_init;

    if (clr == PWHITE) {
        fd = 1;
        sr_init = 1;
    }
    else {
        fd = -1;
        sr_init = 6;
    }

    if (er == sr + fd && ec == sc && B[er][ec] == nullptr) {
        return true;
    }

    if (sr == sr_init && er == sr + 2 * fd && ec == sc && B[sr + fd][sc] == nullptr && B[er][ec] == nullptr) {
        return true;
    }

    if (er == sr + fd && abs(ec - sc) == 1 && B[er][ec] != nullptr) {
        if (clr == PWHITE && B[er][ec]->getclr() == PBLACK) {
            return true;
        }
        if (clr == PBLACK && B[er][ec]->getclr() == PWHITE) {
            return true;
        }
    }

    return false;
}