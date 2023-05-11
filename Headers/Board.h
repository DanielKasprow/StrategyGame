//
// Created by Daniel Kasprow on 30.04.2023.
//

#include <list>

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#endif //UNTITLED_BOARD_H

class Board{
    char **board;
    int boardHeight;
    int boardWidth;

public:
    explicit Board(const std::string& fileLocalization);
    ~Board();

    char getBoardPoint(int x, int y);
    int getBoardHeight() const;
    int getBoardWidth() const;
    int *getLocationPlayer(char player);
};
