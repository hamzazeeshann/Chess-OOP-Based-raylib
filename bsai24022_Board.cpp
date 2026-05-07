#include "bsai24022_Board.h"
#include "bsai24022_Pawn.h"
#include "bsai24022_Rook.h"
#include "bsai24022_Knight.h"
#include "bsai24022_Bishop.h"
#include "bsai24022_Queen.h"
#include "bsai24022_King.h"
#include "bsai24022_Header.h"
#include "fstream"
using namespace std;
Board::Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            B[i][j] = nullptr;
        }
    }

    B[0][0] = new Rook(PWHITE, { 0, 0 }, this);
    B[0][1] = new Knight(PWHITE, { 0, 1 }, this);
    B[0][2] = new Bishop(PWHITE, { 0, 2 }, this);
    B[0][3] = new Queen(PWHITE, { 0, 3 }, this);
    B[0][4] = new King(PWHITE, { 0, 4 }, this);
    B[0][5] = new Bishop(PWHITE, { 0, 5 }, this);
    B[0][6] = new Knight(PWHITE, { 0, 6 }, this);
    B[0][7] = new Rook(PWHITE, { 0, 7 }, this);
    for (int j = 0; j < 8; j++) {
        B[1][j] = new Pawn(PWHITE, { 1, j }, this);
    }

    B[7][0] = new Rook(PBLACK, { 7, 0 }, this);
    B[7][1] = new Knight(PBLACK, { 7, 1 }, this);
    B[7][2] = new Bishop(PBLACK, { 7, 2 }, this);
    B[7][3] = new Queen(PBLACK, { 7, 3 }, this);
    B[7][4] = new King(PBLACK, { 7, 4 }, this);
    B[7][5] = new Bishop(PBLACK, { 7, 5 }, this);
    B[7][6] = new Knight(PBLACK, { 7, 6 }, this);
    B[7][7] = new Rook(PBLACK, { 7, 7 }, this);
    for (int j = 0; j < 8; j++) {
        B[6][j] = new Pawn(PBLACK, { 6, j }, this);
    }
    boardTexture = LoadTexture("board.png");
    pieceTextures[0][0] = LoadTexture("wpawn.png");
    pieceTextures[0][1] = LoadTexture("wknight.png");
    pieceTextures[0][2] = LoadTexture("wbishop.png");
    pieceTextures[0][3] = LoadTexture("wrook.png");
    pieceTextures[0][4] = LoadTexture("wqueen.png");
    pieceTextures[0][5] = LoadTexture("wking.png");
    pieceTextures[1][0] = LoadTexture("bpawn.png");
    pieceTextures[1][1] = LoadTexture("bknight.png");
    pieceTextures[1][2] = LoadTexture("bbishop.png");
    pieceTextures[1][3] = LoadTexture("brook.png");
    pieceTextures[1][4] = LoadTexture("bqueen.png");
    pieceTextures[1][5] = LoadTexture("bking.png");
    t = PBLACK;
}

Board::Board(string filename) {
    ifstream rdr(filename);
    if (!rdr) {
        cout << "File not found";
        exit(1);
    }
    char p;
    rdr >> p >> p >> p >> p >> p >> p;
    if (p == 'E')
        t = PBLACK;
    else if (p == 'K')
        t = PWHITE;
    else {
        cout << "Error in file format i.e: TURN endl Board formation\n";
        exit(1);
    } 
    boardTexture = LoadTexture("board.png");
    pieceTextures[0][0] = LoadTexture("wpawn.png");
    pieceTextures[0][1] = LoadTexture("wknight.png");
    pieceTextures[0][2] = LoadTexture("wbishop.png");
    pieceTextures[0][3] = LoadTexture("wrook.png");
    pieceTextures[0][4] = LoadTexture("wqueen.png");
    pieceTextures[0][5] = LoadTexture("wking.png");
    pieceTextures[1][0] = LoadTexture("bpawn.png");
    pieceTextures[1][1] = LoadTexture("bknight.png");
    pieceTextures[1][2] = LoadTexture("bbishop.png");
    pieceTextures[1][3] = LoadTexture("brook.png");
    pieceTextures[1][4] = LoadTexture("bqueen.png");
    pieceTextures[1][5] = LoadTexture("bking.png");

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            rdr >> p;
            switch (p) {
            case 'K':
                B[i][j] = new King(PWHITE, { i, j }, this);
                break;
            case 'k':
                B[i][j] = new King(PBLACK, { i, j }, this);
                break;
            case 'Q':
                B[i][j] = new Queen(PWHITE, { i, j }, this);
                break;
            case 'q':
                B[i][j] = new Queen(PBLACK, { i, j }, this);
                break;
            case 'R':
                B[i][j] = new Rook(PWHITE, { i, j }, this);
                break;
            case 'r':
                B[i][j] = new Rook(PBLACK, { i, j }, this);
                break;
            case 'B':
                B[i][j] = new Bishop(PWHITE, { i, j }, this);
                break;
            case 'b':
                B[i][j] = new Bishop(PBLACK, { i, j }, this);
                break;
            case 'N':
                B[i][j] = new Knight(PWHITE, { i, j }, this);
                break;
            case 'n':
                B[i][j] = new Knight(PBLACK, { i, j }, this);
                break;
            case 'P':
                B[i][j] = new Pawn(PWHITE, { i, j }, this);
                break;
            case 'p':
                B[i][j] = new Pawn(PBLACK, { i, j }, this);
                break;
            case '-':
                B[i][j] = nullptr;
                break;
            default:
                cout << "invalid piece character '" << p << "' at position " << i << "," << j << "\n";
                exit(1);
            }
        }

    }
}


void PrintBoard(Pieces* B[8][8], Board* board) {
    DrawTexture(board->boardTexture, 0, 0, WHITE);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (B[i][j] != nullptr) 
                B[i][j]->draw();
        }
    }
}

bool Board::isValidPiece(Pieces* B[8][8], int r, int c, CLR turn) {
    if (r < 0 || r >= 8 || c < 0 || c >= 8) return false;
    if (B[r][c] == nullptr) return false;
    if ((turn == PWHITE && B[r][c]->getclr() != PWHITE) || (turn == PBLACK && B[r][c]->getclr() != PBLACK)) 
        return false;
    return true;
}

bool Board::isValidBox(Pieces* B[8][8], int r, int c, CLR turn) {
    if (r < 0 || r >= 8 || c < 0 || c >= 8)
        return false;
    if (B[r][c] == nullptr) return true;
    if (B[r][c] != nullptr && ((turn == PWHITE && B[r][c]->getclr() == PWHITE) || (turn == PBLACK && B[r][c]->getclr() == PBLACK)))
        return false;
    return true;
}



bool Board::isCheck(CLR turn) {
    int kr = -1, kc = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (B[i][j] != nullptr && B[i][j]->getclr() == turn && dynamic_cast<King*>(B[i][j])) {
                kr = i;
                kc = j;
                break;
            }
        }
        if (kr != -1) break;
    }

    if (kr == -1) 
        return false;

    CLR opp = PWHITE;
    if (turn == PWHITE) {
        opp = PBLACK;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (B[i][j] != nullptr && B[i][j]->getclr() == opp && B[i][j]->isLegal(B, i, j, kr, kc)) {
                
                return true;
            }
        }
    }
    return false;
}

bool Board::isCheckmate(CLR turn) {
    if (!isCheck(turn)) return false;

    for (int sr = 0; sr < 8; sr++) {
        for (int sc = 0; sc < 8; sc++) {
            if (B[sr][sc] != nullptr && B[sr][sc]->getclr() == turn) {
                for (int er = 0; er < 8; er++) {
                    for (int ec = 0; ec < 8; ec++) {
                        if (B[sr][sc]->isLegal(B, sr, sc, er, ec) && isValidBox(B, er, ec, turn)) {
                            Pieces* temp = B[er][ec];
                            B[er][ec] = B[sr][sc];
                            B[sr][sc] = nullptr;

                            bool stillCheck = isCheck(turn);

                            B[sr][sc] = B[er][ec];
                            B[er][ec] = temp;

                            if (!stillCheck) return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Board::isStalemate(CLR turn) {
    if (isCheck(turn)) return false;

    for (int sr = 0; sr < 8; sr++) {
        for (int sc = 0; sc < 8; sc++) {
            if (B[sr][sc] != nullptr && B[sr][sc]->getclr() == turn) {
                for (int er = 0; er < 8; er++) {
                    for (int ec = 0; ec < 8; ec++) {
                        if (B[sr][sc]->isLegal(B, sr, sc, er, ec) && isValidBox(B, er, ec, turn)) {
                            Pieces* temp = B[er][ec];
                            B[er][ec] = B[sr][sc];
                            B[sr][sc] = nullptr;

                            bool stillCheck = isCheck(turn);

                            B[sr][sc] = B[er][ec];
                            B[er][ec] = temp;

                            if (!stillCheck) return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
void Board::promotion(CLR turn) {
    int col = -1;
    int row;
    if (turn == PWHITE)
        row = 7;
    else row = 0;
    for (int ci = 0; ci < 8; ci++) {
        if ((B[row][ci] != nullptr && B[row][ci]->getclr() == turn && dynamic_cast<Pawn*>(B[row][ci])) ) {
            col = ci;
            break;
        }
       
    }
    if (col == -1) 
        return;

    Rectangle queenRect = { 200, 350, 100, 100 };
    Rectangle rookRect = { 310, 350, 100, 100 };
    Rectangle bishopRect = { 420, 350, 100, 100 };
    Rectangle knightRect = { 530, 350, 100, 100 };
    Rectangle Rec = { 200,350,440,100 };
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        PrintBoard(B, this);
        DrawText("Promote to:", 300, 300, 20, BLACK);
        DrawRectangleRec(Rec, SKYBLUE);
        DrawTexture(pieceTextures[turn][4], 200, 350, WHITE);
        DrawTexture(pieceTextures[turn][3], 310, 350, WHITE);
        DrawTexture(pieceTextures[turn][2], 420, 350, WHITE);
        DrawTexture(pieceTextures[turn][1], 530, 350, WHITE);
        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse = GetMousePosition();
            Pos pos = { row, col };
            delete B[pos.ri][pos.ci];
            B[pos.ri][pos.ci] = nullptr;
            if (CheckCollisionPointRec(mouse, queenRect)) {
                B[pos.ri][pos.ci] = new Queen(turn, pos, this);
            }
            else if (CheckCollisionPointRec(mouse, rookRect)) {
                B[pos.ri][pos.ci] = new Rook(turn, pos, this);
            }
            else if (CheckCollisionPointRec(mouse, bishopRect)) {
                B[pos.ri][pos.ci] = new Bishop(turn, pos, this);
            }
            else if (CheckCollisionPointRec(mouse, knightRect)) {
                B[pos.ri][pos.ci] = new Knight(turn, pos, this);
            }
            if (B[pos.ri][pos.ci]) break;
        }
    }
}

void Board::promotion2(CLR turn, int sr, int sc) {
    int col = -1;
    int row=-1;  

    if (turn == PWHITE)
        turn = PBLACK;
    else
        turn = PWHITE;

    if ((dynamic_cast<Pawn*>(B[sr][sc])) ) {
            row = sr;
            col = sc; 
    
    }  
    if (col == -1 && row == -1) 
        return;

    Rectangle queenRect = { 200, 350, 100, 100 };
    Rectangle rookRect = { 310, 350, 100, 100 };
    Rectangle bishopRect = { 420, 350, 100, 100 };
    Rectangle knightRect = { 530, 350, 100, 100 };
    Rectangle Rec = { 200,350,440,100 };
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        PrintBoard(B, this);
        DrawText("Promote to:", 300, 300, 20, BLACK);
        DrawRectangleRec(Rec, SKYBLUE);
        DrawTexture(pieceTextures[turn][4], 200, 350, WHITE);
        DrawTexture(pieceTextures[turn][3], 310, 350, WHITE);
        DrawTexture(pieceTextures[turn][2], 420, 350, WHITE);
        DrawTexture(pieceTextures[turn][1], 530, 350, WHITE);
        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse = GetMousePosition();
            Pos pos = { row, col };
            delete B[pos.ri][pos.ci];
            B[pos.ri][pos.ci] = nullptr;
            if (CheckCollisionPointRec(mouse, queenRect)) {
                B[pos.ri][pos.ci] = new Queen(turn, pos, this);
            }
            else if (CheckCollisionPointRec(mouse, rookRect)) {
                B[pos.ri][pos.ci] = new Rook(turn, pos, this);
            }
            else if (CheckCollisionPointRec(mouse, bishopRect)) {
                B[pos.ri][pos.ci] = new Bishop(turn, pos, this);
            }
            else if (CheckCollisionPointRec(mouse, knightRect)) {
                B[pos.ri][pos.ci] = new Knight(turn, pos, this);
            }
            if (B[pos.ri][pos.ci]) break;
        }
    }
}

void Board::play() {
    int sr = -1, sc = -1, er, ec;
    bool pieceSelected = false;
    Sound moveSound = LoadSound("move.mp3");
    Sound captureSound = LoadSound("capture.mp3");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        PrintBoard(B, this);

        if (isCheckmate(t)) {
            DrawText("Checkmate!", 300, 400, 40, RED);
            EndDrawing();
            WaitTime(2);
            break;
        }
        else if (isCheck(t)) { 
            DrawText("Check!", 360, 400, 20, RED);
        }
        if (isStalemate(t)) {
            DrawText("Stalemate!", 300, 400, 40, RED);
            EndDrawing();
            WaitTime(2);
            break;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse = GetMousePosition();
            int row = mouse.y / 100;
            int col = mouse.x / 100;
            if (!pieceSelected) {
                if (isValidPiece(B, row, col, t)) {
                    sr = row;
                    sc = col;
                    pieceSelected = true;
                    HighlightPiece(sr, sc, B, YELLOW);
                    moveHighlight(sr, sc, t);
                }
            }
            else {
                er = row;
                ec = col;
                if (isValidBox(B, er, ec, t) && B[sr][sc]->isLegal(B, sr, sc, er, ec)) {
                    King* king = dynamic_cast<King*>(B[sr][sc]);
                    if (king && !king->getMoved() && abs(ec - sc) == 2) {
                        if (ec == sc + 2) {
                            B[er][ec - 1] = B[er][7];
                            B[er][ec - 1]->PosSetter({ er, ec - 1 });
                            B[er][7] = nullptr;
                        }
                        else if (ec == sc - 2) {
                            B[er][ec + 1] = B[er][0];
                            B[er][ec + 1]->PosSetter({ er, ec + 1 });
                            B[er][0] = nullptr;
                        }
                    }
                    Pieces* temp = B[er][ec];
                    B[er][ec] = B[sr][sc];
                    B[er][ec]->PosSetter({ er,ec });
                    B[sr][sc] = nullptr;

                    if (King* movedKing = dynamic_cast<King*>(B[er][ec])) {
                        movedKing->setMoved();
                    }
                    else if (Rook* movedRook = dynamic_cast<Rook*>(B[er][ec])) {
                        movedRook->setMoved();
                    }
                    if (isCheck(t)) {
                        B[sr][sc] = B[er][ec];
                        B[er][ec] = temp;
                    }
                    else {
                        if (temp != nullptr) {
                            PlaySound(captureSound);
                        }
                        else {
                            PlaySound(moveSound);
                        }
                        promotion(t);

                        if (t == PWHITE)
                            t = PBLACK;
                        else
                            t = PWHITE;

                        if (isCheck(t)) {  
                            promotion2(t, er, ec);
                        }

                        if (t == PWHITE)
                            t = PBLACK;
                        else
                            t = PWHITE;
                        saveToFile("game.txt");
                        if (t == PWHITE)
                            t = PBLACK;
                        else
                            t = PWHITE;

                    }
                }
                pieceSelected = false;
                sr = -1;
                sc = -1;
            }
        }

        if (pieceSelected) {
            HighlightPiece(sr, sc, B, YELLOW);
            moveHighlight(sr, sc, t);
        }

        EndDrawing();
    }
}

Pieces* Board::PieceAt(Pos P) {
    return B[P.ri][P.ci];
}
void Board::HighlightPiece(int sr, int sc, Pieces* B[][8], Color clr) {
    DrawRectangle(sc * 100, sr * 100, 100, 100, Fade(clr, 0.5f));
    if (B[sr][sc]) B[sr][sc]->draw();
}
void Board::moveHighlight(int sr, int sc, CLR turn) {
    bool inCheck = isCheck(turn);

    for (int er = 0; er < 8; er++) {
        for (int ec = 0; ec < 8; ec++) {
            if (B[sr][sc] && B[sr][sc]->isLegal(B, sr, sc, er, ec) && isValidBox(B, er, ec, turn)) {
                Pieces* temp = B[er][ec];
                B[er][ec] = B[sr][sc];
                B[er][ec]->PosSetter({ er, ec });
                B[sr][sc] = nullptr;
                bool inCheck2 = isCheck(turn);
                B[sr][sc] = B[er][ec];
                B[sr][sc]->PosSetter({ sr, sc });
                B[er][ec] = temp;
                if (!inCheck2 && (!inCheck || !inCheck2)) {
                    if (B[er][ec] != nullptr) {
                        DrawRectangle(ec * 100, er * 100, 100, 100, Fade(RED, 0.3f));
                            B[er][ec]->draw();
                    }
                    else {
                        DrawRectangle(ec * 100, er * 100, 100, 100, Fade(YELLOW, 0.3f));
                    }
                }
            }
        }
    }
}
Board::~Board() {
    UnloadTexture(boardTexture);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            UnloadTexture(pieceTextures[i][j]);
        }
    }
}

void Board::saveToFile(string filename) {
    ofstream wtr(filename);
    if (!wtr) {
        cout << "Error opening file for writing" << endl;
        return;
    }
    if (t == PWHITE) {
        wtr << "PWHITE" << endl;
    }
    else
        wtr << "PBLACK" << endl;


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (B[i][j] == nullptr) {
                wtr << "-";
            }
            else {
                char c;
                if (dynamic_cast<Pawn*>(B[i][j])) c = 'P';
                else if (dynamic_cast<Queen*>(B[i][j])) c = 'Q';
                else if (dynamic_cast<Rook*>(B[i][j])) c = 'R';
                else if (dynamic_cast<Knight*>(B[i][j])) c = 'N';
                else if (dynamic_cast<Bishop*>(B[i][j])) c = 'B';
                else if (dynamic_cast<King*>(B[i][j])) c = 'K';


                if (B[i][j]->getclr() == PBLACK) {
                    c = c+32 ;
                }
                wtr << c;
            }
        }
        wtr << endl;
    }

    wtr.close();
}