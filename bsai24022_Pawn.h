#pragma once
#include "bsai24022_Pieces.h"
#include "bsai24022_Board.h"

class Pawn : public Pieces {
public:
    
    Pawn(CLR c, Pos p, Board* b);
    void draw() override;
    bool isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) override;
};