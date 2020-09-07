#ifndef TIC_TAC_TOE_OPPONENT_H
#define TIC_TAC_TOE_OPPONENT_H

#include <iostream>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "AbstractPlayer.h"

class Computer: public AbstractPlayer {

public:
    explicit Computer(char n_side): AbstractPlayer(n_side){}

    int move(Board &board) override;
};

#endif
