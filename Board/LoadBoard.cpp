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

//Method that load board from file in format .txt
char **loadBoardFromFile(string file) {

    char **board;
    vector<string> boardTemp;
    ifstream loadboard(file);
    int widhtBoard = 0;
    string rowLoad;

    //if exist file
    if (loadboard) {
        //load row from file in format string
        while (!loadboard.eof()) {
            getline(loadboard, rowLoad);
            boardTemp.push_back(rowLoad);
            widhtBoard = rowLoad.length();
        }
    }
    else {
        char **board = new char *[0];
        board[0] = new char[0];
        board[0][0] = -1;
    }
    loadboard.close();


    board = new char*[boardTemp.size()];
    for (int x = 0; x < boardTemp.size(); x++) {
        board[x] = new char[widhtBoard];
    }

    //convert list to char 2d
    for (int i=0;i<boardTemp.size() ; i++) {
        rowLoad = boardTemp[i];
        strcpy(board[i], rowLoad.c_str());
    }
    return board;
}

Board::Board(string file) {
    board = loadBoardFromFile(file);
};

char Board::getBoardPoint(int x, int y){
    return board[x][y];
}

Board::~Board() {};