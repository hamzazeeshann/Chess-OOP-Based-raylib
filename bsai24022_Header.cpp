#include "bsai24022_Header.h"

bool isHorizontalMove(int sr, int sc, int er, int ec) {
    return (sr == er);
}
bool isHorizontalMove2(int sr, int sc, int er, int ec) {
    return (sr == er) and (abs(sc-ec)%3 == 0);
}

bool isVerticalMove(int sr, int sc, int er, int ec) {
    return (sc == ec);
}

bool isVerticalMove2(int sr, int sc, int er, int ec) {
    return (sc == ec) and (abs(sr - er) % 3 == 0);
}

bool isDiagonalMove(int sr, int sc, int er, int ec) {
    int dr = er - sr, dc = ec - sc;
    return (abs(dr) == abs(dc));
}

bool isDiagonalMove2(int sr, int sc, int er, int ec) {
    int dr = er - sr, dc = ec - sc;
    bool temp = abs(dr) % 2 == 0 and abs(dc) % 2 == 0;
    return (abs(dr) == abs(dc)) and temp;
}

bool HPC(Pieces* B[][8], int sr, int sc, int er, int ec) {
    if (sr != er || sc == ec) return false;
    if (ec > sc) {
        for (int i = sc + 1; i < ec; i++) {
            if (B[sr][i] != nullptr) return false;
        }
    }
    else if (ec < sc) {
        for (int i = ec + 1; i < sc; i++) {
            if (B[sr][i] != nullptr) return false;
        }
    }
    return true;
}
bool HPC2(Pieces* B[][8], int sr, int sc, int er, int ec) {
    if (sr != er || sc == ec) return false;
    if (ec > sc) {
        for (int i = sc + 3; i < ec; i+=3) {
            if (B[sr][i] != nullptr) return false;
        }
    }
    else if (ec < sc) {
        for (int i = ec + 3; i < sc; i+=3) {
            if (B[sr][i] != nullptr) return false;
        }
    }
    return true;
}

bool VPC(Pieces* B[][8], int sr, int sc, int er, int ec) {
    if (sc != ec || sr == er) return false;
    if (er > sr) {
        for (int i = sr + 1; i < er; i++) {
            if (B[i][sc] != nullptr) return false;
        }
    }
    else if (er < sr) {
        for (int i = er + 1; i < sr; i++) {
            if (B[i][sc] != nullptr) return false;
        }
    }
    return true;
}
bool VPC2(Pieces* B[][8], int sr, int sc, int er, int ec) {
    if (sc != ec || sr == er) return false;
    if (er > sr) {
        for (int i = sr + 3; i < er; i+=3) {
            if (B[i][sc] != nullptr) return false;
        }
    }
    else if (er < sr) {
        for (int i = er + 3; i < sr; i+=3) {
            if (B[i][sc] != nullptr) return false;
        }
    }
    return true;
}

bool DPC(Pieces* B[][8], int sr, int sc, int er, int ec) {
    int dr = er - sr, dc = ec - sc;
    if (abs(dr) != abs(dc) || dr == 0) return false;
    if (dr > 0 && dc > 0) {
        for (int i = 1; i < dr; i++) {
            if (B[sr + i][sc + i] != nullptr) return false;
        }
    }
    else if (dr > 0 && dc < 0) {
        for (int i = 1; i < dr; i++) {
            if (B[sr + i][sc - i] != nullptr) return false;
        }
    }
    else if (dr < 0 && dc > 0) {
        for (int i = 1; i < -dr; i++) {
            if (B[sr - i][sc + i] != nullptr) return false;
        }
    }
    else if (dr < 0 && dc < 0) {
        for (int i = 1; i < -dr; i++) {
            if (B[sr - i][sc - i] != nullptr) return false;
        }
    }
    return true;
}
bool DPC2(Pieces* B[][8], int sr, int sc, int er, int ec) {
    int dr = er - sr, dc = ec - sc;
    if (abs(dr) != abs(dc) || dr == 0) return false;
    if (dr > 0 && dc > 0) {
        for (int i = 2; i < dr; i+=2) {
            if (B[sr + i][sc + i] != nullptr) return false;
        }
    }
    else if (dr > 0 && dc < 0) {
        for (int i = 2; i < dr; i+=2) {
            if (B[sr + i][sc - i] != nullptr) return false;
        }
    }
    else if (dr < 0 && dc > 0) {
        for (int i = 2; i < -dr; i+=2) {
            if (B[sr - i][sc + i] != nullptr) return false;
        }
    }
    else if (dr < 0 && dc < 0) {
        for (int i = 2; i < -dr; i+=2) {
            if (B[sr - i][sc - i] != nullptr) return false;
        }
    }
    return true;
}