#include <iostream>
#include "Board.h"


Board::Board(): field(BOARDSELLS, EMPTY){
    for (int i = 0; i < 9; ++i) {
        field[i] = EMPTY;
    };
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    os << "\t" << board.field[0] << " | " << board.field[1] << " | " << board.field[2];
    os << "\n\t" << "---------";
    os << "\n\t" << board.field[3] << " | " << board.field[4] << " | " << board.field[5];
    os << "\n\t" << "---------";
    os << "\n\t" << board.field[6] << " | " << board.field[7] << " | " << board.field[8];
    os << "\n";
    return os;
}

//Verification of sell
bool Board::isEmpty(const std::vector<char>& board, int move) {
        return (board[move] == EMPTY);
}

int Board::operator[](short index) {
    return field[index];
}

const int& Board::operator[](short index) const {
    return field[index];
}

const std::vector<char> &Board::getField() const {
    return field;
}

void Board::setField(int move, char sign) {
    field[move] = sign;
}

bool Board::isBoardEmpty() {
    int j = 0;
    for (int i = 0; i < BOARDSELLS; ++i) {
        if (field[i] == EMPTY)
            j++;
    }
    return (j > 0)? false : true;
}

void Board::clearBoard() {

    for (int i = 0; i < field.size(); ++i)
        setField(i, ' ');
}
