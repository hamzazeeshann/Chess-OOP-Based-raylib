#include "bsai24022_Board.h"

int main() {
    InitAudioDevice();
    InitWindow(800, 800, "Chess");
    SetTargetFPS(60);
    cout << "1. New game\n2. Load game\n";
    int c;
    cin >> c;
    Board* game;
    if (c == 1) {
        game = new Board();
    }
    else if (c == 2) {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        game = new Board(filename);
    }
    else {
        cout << "Invalid choice." << endl;
        CloseWindow();
        return 0;
    }
    game->play();
    delete game;
    CloseWindow();
    return 0;
}