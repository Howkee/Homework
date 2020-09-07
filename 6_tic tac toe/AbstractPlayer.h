#ifndef TIC_TAC_TOE_ABSTRACTPLAYER_H
#define TIC_TAC_TOE_ABSTRACTPLAYER_H

#include "Board.h"

const char X = 'X';
const char O = 'O';
const char NOONE = 'N';
const char TIE = 'T';
const char COMPUTER = 'c';
const char HUMAN = 'H';
const char YES = 'Y';
const char NO = 'N';

class AbstractPlayer {
protected:
    char side;

public:
    explicit AbstractPlayer(char n_side):
            side(n_side) {};

    char getSide() const;
    void setSide(char side);
    virtual int move(Board& board) = 0;
};


#endif
