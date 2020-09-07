#include <iostream>
#include <cstdlib>
#include "Game.h"

void Game::instructions(){
    std::cout << "Welcome to the Tic-Tac-Toe.\n";
    std::cout << "Make your move by entering a number, 1 - 9.\n";
    std::cout << "\t1 | 2 | 3\n";
    std::cout << "\t---------\n";
    std::cout << "\t4 | 5 | 6\n";
    std::cout << "\t---------\n";
    std::cout << "\t7 | 8 | 9\n\n";
}

char Game::choseOpponent(){
    std::cout << "Who will be your opponent! Chose wisely!\n";
    std::cout << "Computer or human (C/H):";
    char opponent;
    std::cin >> opponent;
    while ( (opponent == 'c') || (opponent == 'h') ){
        std::cout << "Attension, please. That`s not what the answer I want to hear. Try again after turning on your brains!\n";
        std::cout << "Computer or human (C/H):";
        std::cin >> opponent;
    }
    //std::cout << opponent;
    return  opponent;
}

char Game::choseSide() {
    char decision;
    while (true) {
        std::cout << "Chose your side: X/O \n";
        std::cin >> decision;
        if ((decision != X) && (decision != O))
            std::cout << "\nPlease, try again! Wrong data input\n";

        if (decision == X) return X;
        if (decision == O) return O;
    }
}

char Game::switchSide(char decision){
    return (decision == X)? O : X;
}

void Game::announceWinner(char winner, char opponent, char player){
    if ( (winner == opponent) || (winner == player))
    {
        std::cout << winner << "'s won!\n";
    }
      else
    {
        std::cout << "It's a tie. Winner is frendship!\n";
    }
}

char Game::isWinner(const std::vector<char>& board){
    const int TOTAL_ROWS = 8;
    const int WINNING_ROWS[TOTAL_ROWS][3] = { {0, 1, 2},
                                              {3, 4, 5},
                                              {6, 7, 8},
                                              {0, 3, 6},
                                              {1, 4, 7},
                                              {2, 5, 8},
                                              {0, 4, 8},
                                              {2, 4, 6} };
    // if any winning row has three same values(not EMPTY), return winner
    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
             (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
             (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
        {
            return board[WINNING_ROWS[row][0]];
        }
    }
    // game is going on
    return NOONE;
}

char Game::playAgain(){
    char again;
    while (true) {
        std::cout << "Want to play again? Y/N\n";
        std::cin >> again;
        win = NOONE;
        if ((again != 'Y') && (again != 'N')) {
            std::cout << "\nPlease, try again! Wrong data input\n";
            std::cin >> again;
        }
        return again;
    }
}

void Game::run() {
    instructions();

    int move;
    char end = YES;
    AbstractPlayer *opponent;

    char opponentSide = choseOpponent();
    player.setSide(choseSide());

    while (end == YES) {

        if (opponentSide == 'C') {
            opponent = new Computer(switchSide(player.getSide()));
        }
        if (opponentSide == 'H') {
            opponent = new Player(switchSide(player.getSide()));
        }

        char turn = X;
        board.clearBoard();
        std::cout << board << std::endl;
        while (win == NOONE) {

            if (turn == player.getSide()) {
                move = player.move(board);
                board.setField(move, player.getSide());
            }

            if (turn == opponent->getSide()) {
                move = opponent->move(board);
                board.setField(move, opponent->getSide());
            }
            std::cout << board << std::endl;
            win = isWinner(board.getField());
            //system("cls");
            if (board.isBoardEmpty())
                win = TIE;
            turn = switchSide(turn);
        }
        announceWinner(win, opponent->getSide(), player.getSide());
        end = playAgain();
    }
    delete opponent;
}