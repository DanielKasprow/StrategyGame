//
// Created by trane on 30.04.2023.
//

#include <list>

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#endif //UNTITLED_BOARD_H
using namespace std;

class Board{
    char **board;
    //string fileLocalization;

public:
    Board(string fileLocalization);
    ~Board();

    char getBoardPoint(int x, int y);
};
