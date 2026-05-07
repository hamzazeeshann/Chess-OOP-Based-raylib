#pragma once
#include "bsai24022_Header.h"

class Board;

class Pieces {
protected:
    CLR clr;
    Pos P;
    Board* B;

public:
    Pieces(CLR c, Pos p, Board* b);
    virtual void draw() = 0;
    virtual bool isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) = 0;
    void PosSetter(Pos P);
    CLR getclr();
};