#include "bsai24022_King.h"
#include "bsai24022_Header.h"
#include "bsai24022_Board.h"
#include "bsai24022_Rook.h"

King::King(CLR c, Pos p, Board* b) : Pieces(c, p, b) , isMoved(false) {}
void King::draw() {
    DrawTexture(B->pieceTextures[(int)clr][5], P.ci * 100, P.ri * 100, WHITE);
}
bool King ::isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) {
    if (abs(sr - er) <= 1 && abs(sc - ec) <= 1) {
        return true;
    }

    if (!isMoved && sr == er && abs(sc - ec) == 2) {
        if (ec == sc + 2) {
            Rook* rook = dynamic_cast<Rook*>(B[sr][7]);
            if (rook && !rook->getMoved() && B[sr][sc + 1] == nullptr && B[sr][sc + 2] == nullptr) {
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (B[i][j] && B[i][j]->getclr() != this->getclr()) {
                            if (B[i][j]->isLegal(B, i, j, sr, sc) ||
                                B[i][j]->isLegal(B, i, j, sr, sc + 1) ||
                                B[i][j]->isLegal(B, i, j, sr, sc + 2)) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            }
        }
        else if (ec == sc - 2) {
            Rook* rook = dynamic_cast<Rook*>(B[sr][0]);
            if (rook && !(rook->getMoved()) && B[sr][sc - 1] == nullptr && B[sr][sc - 2] == nullptr && B[sr][sc - 3] == nullptr) {
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (B[i][j] && B[i][j]->getclr() != this->getclr()) {
                            if (B[i][j]->isLegal(B, i, j, sr, sc) ||
                                B[i][j]->isLegal(B, i, j, sr, sc - 1) ||
                                B[i][j]->isLegal(B, i, j, sr, sc - 2)) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            }
        }
    }

    return false;
}

void King:: setMoved() {
    isMoved = true; 
}
bool King:: getMoved() const {
    return isMoved; 
}