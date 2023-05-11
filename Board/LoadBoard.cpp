//
// Created by Daniel Kasprow on 30.04.2023.
//
#include <string>
#include "../Headers/Board.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

int boardWidthTemp;
int boardHeightTemp;

//Method that load board from file in format .txt
char **loadBoardFromFile(const std::string& file) {

    char **board;
    std::vector<std::string> boardTemp;
    std::ifstream loadBoard(file);
    std::string rowLoad;

    //if exist file
    if (loadBoard) {
        //load row from file in format string
        while (!loadBoard.eof()) {
            getline(loadBoard, rowLoad);
            if (!rowLoad.empty())
                boardTemp.push_back(rowLoad);

        }
        boardWidthTemp = boardTemp[0].size();
    } else {
        std::cout<<"Bledna mapa";
        exit(0);
    }
    loadBoard.close();
    boardHeightTemp = boardTemp.size();

    board = new char *[boardHeightTemp];
    for (int x = 0; x < boardHeightTemp; x++) {
        board[x] = new char[boardWidthTemp];
    }
    //convert list to char 2d
    for (int i = 0; i < boardHeightTemp; i++) {
        rowLoad = boardTemp[i];
        strcpy(board[i], rowLoad.c_str());
    }

    return board;
}


Board::Board(const std::string& file) {

    Board::board = loadBoardFromFile(file);
    Board::boardWidth = boardWidthTemp;
    Board::boardHeight = boardHeightTemp;
};

char Board::getBoardPoint(int y, int x) {
    return Board::board[y][x];
}

int *Board::getLocationPlayer(char player) {
    for (int height = 0; height < boardHeightTemp; height++) {
        for (int width = 0; width < boardWidthTemp; width++) {
            if (board[height][width] == player) {
                static int localization[2];
                localization[0] = height;
                localization[1] = width;

                return localization;
            }
        }
    }
    return nullptr;
}

int Board::getBoardHeight() const {
    return boardHeight;
}

int Board::getBoardWidth() const {
    return boardWidth;
}


Board::~Board() = default;