#pragma once
#include "bsai24022_Pieces.h"

class Rook : virtual public Pieces {

protected:
    bool hasMoved;
public:
    Rook(CLR c, Pos p, Board* b);
    void draw() override;
    bool isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) override;
    bool isLegal2(Pieces* B[8][8], int sr, int sc, int er, int ec);
    void setMoved();
    bool getMoved();
};