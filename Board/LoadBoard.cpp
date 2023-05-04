//
// Created by trane on 30.04.2023.
//
#include <string>
#include "../Headers/Board.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int boardWidthTemp;
int boardHeightTemp;

//Method that load board from file in format .txt
char **loadBoardFromFile(string file) {

    char **board;
    vector<string> boardTemp;
    ifstream loadboard(file);
    string rowLoad;

    //if exist file
    if (loadboard) {
        //load row from file in format string
        while (!loadboard.eof()) {
            getline(loadboard, rowLoad);
            boardTemp.push_back(rowLoad);

        }
        boardWidthTemp=boardTemp[0].size();
    }
    else {
        char **board = new char *[0];
        board[0] = new char[0];
        board[0][0] = -1;
    }
    loadboard.close();
    boardHeightTemp = boardTemp.size();

    board = new char*[boardHeightTemp];
    for (int x = 0; x < boardHeightTemp; x++) {
        board[x] = new char[boardWidthTemp];
    }
    //convert list to char 2d
    for (int i=0;i<boardHeightTemp ; i++) {
        rowLoad = boardTemp[i];
        strcpy(board[i], rowLoad.c_str());
    }

    return board;
}


Board::Board(string file) {

    Board::board = loadBoardFromFile(file);
    Board::boardWidth = boardWidthTemp;
    Board::boardHeight = boardHeightTemp;
};

char Board::getBoardPoint(int y, int x){
    return Board::board[y][x];
}
int *Board::getLocationPlayer(char player) {
    for(int height=0; height < boardHeightTemp; height++){
        for(int width=0; width < boardWidthTemp; width++){
            if(board[height][width] == player){
                int localization[2]={height,width};
                return localization;
            }
        }
    }
    return nullptr;
}

int Board::getBoardHeight() {
    return boardHeight;
}

int Board::getBoardWidth() {
    return boardWidth;
}


Board::~Board() {}