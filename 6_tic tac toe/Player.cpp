#include "Player.h"
#include "Board.h"

#include <iostream>
#include <vector>

int Player::move(Board& board) {
    int move;
    std::cout << "Your move (chose amound numbers from 1 to 9):\n";
    std::cin >> move;
    while ( !Board::isEmpty(board.getField(), --move)){
        std::cout << "Attension, please. This sell is already taken. Can`t you see that? :P\n";
        std::cout << "Your move (chose amound numbers from 1 to 9):";
        std::cin >> move;
    }
    return move;
}


