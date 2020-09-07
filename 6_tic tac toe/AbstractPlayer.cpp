#include "AbstractPlayer.h"

char AbstractPlayer::getSide() const {
    return side;
}

void AbstractPlayer::setSide(char m_side) {
    side = m_side;
}
