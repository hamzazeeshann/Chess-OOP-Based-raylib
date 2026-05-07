#pragma once
#include "bsai24022_Pieces.h"

class King : public Pieces {
protected:
    bool isMoved;
public:
    King(CLR c, Pos p, Board* b);
    void draw() override;
    bool isLegal(Pieces* B[8][8], int sr, int sc, int er, int ec) override;
    void setMoved();
    bool getMoved() const;
};