#include "bsai24022_Pieces.h"
#include "bsai24022_Board.h"

Pieces::Pieces(CLR c, Pos p, Board* b) : clr(c), P(p), B(b) {
}
void Pieces::PosSetter(Pos P) {
    this->P = P;
}

CLR Pieces::getclr() {
    return clr;
}