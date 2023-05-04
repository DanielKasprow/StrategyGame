//
// Created by Daniel Kasprow on 04.05.2023.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include "Headers/Units.h"


std::vector<std::string> splitString(std::string mediator, char splitBy) {
    std::vector<std::string> files;
    std::stringstream check1(mediator);
    std::string intermediate;
    while (getline(check1, intermediate, splitBy)) {
        files.push_back(intermediate);
    }
    return files;
}

bool attackRange(int range, int x1, int y1, int x2, int y2) {
    if (abs(x1 + x2) + abs(y1 + y2) <= range)
        return true;
    else
        return false;
}

bool checkPlayerCommand(std::string file, Base playerBase, Base enemyBase, std::map<int, FightingUnit *> fightingUnits,
                        std::map<int, Worker *> workers, char owner) {
    std::vector<std::string> commandLine;
    std::ifstream loadboard(file);
    std::string rowLoad;
    std::vector<std::string> commandSplited;
    bool falseCommands;
    //if exist file
    if (loadboard) {
        //load row from file in format string
        while (!loadboard.eof()) {
            getline(loadboard, rowLoad);
            commandLine.push_back(rowLoad);
        }


        for (auto i: commandLine) {
            commandSplited = splitString(i, ' ');
            //Checking command for Base
            if (to_string(playerBase.getId()) == commandSplited[0] && commandSplited.size() == 3) {
                if (commandSplited[1] == "B" && playerBase.getProductionTime() == 0) {
                    if (commandSplited[2] == "K" || commandSplited[2] == "S" || commandSplited[2] == "A"
                        || commandSplited[2] == "P" || commandSplited[2] == "R" || commandSplited[2] == "C" ||
                        commandSplited[2] == "W") {}
                    else
                        falseCommands = true;
                } else
                    falseCommands = true;
            } else {
                //checking command for fighting unit
                if (fightingUnits[stoi(commandSplited[0])]->getOwner() == owner) {
                    //checking command attack
                    if (commandSplited[1] == "A" && commandSplited.size() == 3) {
                        //checking command attacked unit if is an enemy unit
                        if (fightingUnits[stoi(commandSplited[2])]->getOwner() != owner) {
                            if (attackRange(fightingUnits[stoi(commandSplited[0])]->getRange(),
                                            fightingUnits[stoi(commandSplited[0])]->getLocalizationX(),
                                            fightingUnits[stoi(commandSplited[0])]->getLocalizationY(),
                                            fightingUnits[stoi(commandSplited[2])]->getLocalizationX(),
                                            fightingUnits[stoi(commandSplited[2])]->getLocalizationY())) {}
                            else
                                falseCommands = true;
                        } else
                            falseCommands = true;
                    } else if (commandSplited[1] == "M" && commandSplited.size() == 4) {
                        if ((enemyBase.getLocalizationY() == stoi(commandSplited[3]) &&
                             enemyBase.getLocalizationX() == stoi(commandSplited[4])))
                            falseCommands = true;
                        else {
                            for (auto [index, i]: fightingUnits) {
                                if ((i->getLocalizationY() == stoi(commandSplited[3]) &&
                                     i->getLocalizationX() == stoi(commandSplited[4])))
                                    falseCommands = true;
                            }
                        }


                    } else
                        falseCommands = true;
                } else if (workers[stoi(commandSplited[0])]->getOwner() == owner) {
                    if (commandSplited[1] == "A" && commandSplited.size() == 3) {
                        //checking command attacked unit if is an enemy unit
                        if (workers[stoi(commandSplited[2])]->getOwner() != owner) {
                            if (attackRange(workers[stoi(commandSplited[0])]->getRange(),
                                            workers[stoi(commandSplited[0])]->getLocalizationX(),
                                            workers[stoi(commandSplited[0])]->getLocalizationY(),
                                            workers[stoi(commandSplited[2])]->getLocalizationX(),
                                            workers[stoi(commandSplited[2])]->getLocalizationY())) {}
                            else
                                falseCommands = true;
                        } else
                            falseCommands = true;
                    } else if (commandSplited[1] == "M" && commandSplited.size() == 4) {
                        if ((enemyBase.getLocalizationY() == stoi(commandSplited[3]) &&
                             enemyBase.getLocalizationX() == stoi(commandSplited[4])))
                            falseCommands = true;
                        else {
                            for (auto [index, i]: workers) {
                                if ((i->getLocalizationY() == stoi(commandSplited[3]) &&
                                     i->getLocalizationX() == stoi(commandSplited[4])))
                                    falseCommands = true;
                            }
                        }


                    } else
                        falseCommands = true;

                } else
                    falseCommands = true;
            }
        }
    } else {
        std::cout << "not Found command file";
        falseCommands = true;
    }
    if (falseCommands = true)
        std::cout << "incorrect command";
    return falseCommands;
}