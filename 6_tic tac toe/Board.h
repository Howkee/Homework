#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <ostream>
#include <vector>

const char EMPTY = ' ';
const short BOARDSELLS = 9;

class Board{
    std::vector<char> field;

public:
    Board();
    void setField(int move, char sign);
    const std::vector<char> &getField() const;
    bool isBoardEmpty();
    void clearBoard();
    bool static isEmpty(const std::vector<char>& board, int move);

private:
    int operator[](short index);
    const int& operator[](short index) const;
    friend std::ostream &operator<<(std::ostream &os, const Board &board);

};

#endif
