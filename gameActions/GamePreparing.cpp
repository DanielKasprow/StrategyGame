//
// Created by Daniel kasprow on 10.05.23.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

std::vector<std::string> argToVector(int argc, char **argv){
    std::vector<std::string> files;
    for (int i = 1; i < argc; i++)
        files.emplace_back(argv[i]);
    return files;
}

int getTimePerRound(basic_string<char> time){
    int timePerSecond = 5;
    if(stoi(time))
        timePerSecond = stoi(time);
    return timePerSecond;
}