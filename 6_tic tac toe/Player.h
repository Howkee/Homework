#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include "Board.h"
#include "AbstractPlayer.h"


class Player : public AbstractPlayer{

public:
    Player(): AbstractPlayer(NOONE) {};
    explicit Player(char m_side): AbstractPlayer(m_side) {};
    int move(Board& board) override;
};

#endif
