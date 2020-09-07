#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include "Board.h"
#include "Computer.h"
#include "Player.h"

class Game{

    char win;
    Board board;
    Player player;
    Computer computer;

public:
    Game():
    win(NOONE),board(Board()), player(Player()),computer(Computer(NOONE)){};

    void run();
    static char isWinner(const std::vector<char>& board);
    static char switchSide(char piece);
private:
    void static instructions();
    char choseOpponent();
    char choseSide();
    void announceWinner(char winner, char computer, char human);
    char playAgain();
};

#endif