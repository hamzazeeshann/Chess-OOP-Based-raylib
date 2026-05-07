#pragma once
#include <raylib.h>
#include <iostream>
#include <cmath>
using namespace std;

class Pieces;
class Board;

enum CLR {
    PBLACK, PWHITE
};

struct Pos {
    int ri, ci;
};

bool isHorizontalMove(int sr, int sc, int er, int ec);
bool isVerticalMove(int sr, int sc, int er, int ec);
bool isHorizontalMove2(int sr, int sc, int er, int ec);
bool isVerticalMove2(int sr, int sc, int er, int ec);
bool isDiagonalMove(int sr, int sc, int er, int ec);
bool isDiagonalMove2(int sr, int sc, int er, int ec);
bool HPC(Pieces* B[][8], int sr, int sc, int er, int ec);
bool VPC(Pieces* B[][8], int sr, int sc, int er, int ec);
bool HPC2(Pieces* B[][8], int sr, int sc, int er, int ec);
bool VPC2(Pieces* B[][8], int sr, int sc, int er, int ec);
bool DPC(Pieces* B[][8], int sr, int sc, int er, int ec);
bool DPC2(Pieces* B[][8], int sr, int sc, int er, int ec);