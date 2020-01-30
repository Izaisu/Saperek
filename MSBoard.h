#ifndef SAPERPO_MSBOARD_H
#define SAPERPO_MSBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};


class MSBoard {

    Field board[100][100];
    int board_Width;
    int board_Height;
    GameMode mode;
    GameState state;
    void setBoard();
    int mineFieldCounter;
    int mineBoardCounter;
    int emptyField;
    int gameFields (int width, int height);
    int moves=0;
    bool onBoard(int x, int y)const;


public:
    MSBoard();
    MSBoard(int width, int height, GameMode g_mode);
    void setField(int x, int y, bool hasMine, bool hasFlag, bool isRevealed);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y);
    bool hasMine (int x, int y) const;
    bool hasFlag(int x, int y) const;
    bool isRevealed(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    GameState getGameState() const;
    char getFieldInfo(int x, int y);
    void untoggleFlag(int x, int y);
    bool isWon();


};


#endif //SAPERPO_MSBOARD_H
