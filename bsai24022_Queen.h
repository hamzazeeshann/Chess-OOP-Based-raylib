#pragma once
#include "bsai24022_Bishop.h"
#include "bsai24022_Rook.h"

class Queen : public Bishop, public Rook {
public:
    
    Queen(CLR c, Pos p, Board* b);
    void draw() override;
    bool isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) override;
};