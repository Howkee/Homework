#include "Computer.h"
#include "Board.h"
#include "Game.h"


int Computer::move(Board &board) {
    int move = 0;
    bool found = false;

    // if next move is winning, then pick it
    while ( !found && (move < board.getField().size()) )
    {
        if (board.isEmpty(board.getField(), move))
        {
            board.setField(move, side);
            found = (Game::isWinner(board.getField()) == getSide() );
            board.setField(move, EMPTY);
        }
        if (!found) ++move;
    }

    move = 0;
    //if humans next move is winning, have to prevent him from doing it
    while (!found && (move < board.getField().size()) )
    {
        if (board.isEmpty(board.getField(), move))
        {
            board.setField(move, Game::switchSide(getSide()));
            found = (Game::isWinner(board.getField()) == Game::switchSide(getSide()));
            board.setField(move, EMPTY);
        }
        if (!found) ++move;
    }

    // looking for the best move if noting intresting on the board
    if ( !found )
    {
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        move = 0;
        short i = 0;

        while ( !found && (i <  board.getField().size()) )
        {
            move = BEST_MOVES[i];
            if (Board::isEmpty(board.getField(), move))
                found = true;
            ++i;
        }
    }
    std::cout << " I made my move. Your turn/" << std::endl;
    return move;
}

