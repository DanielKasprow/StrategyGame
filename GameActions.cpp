//
// Created by Daniel Kasprow on 04.05.2023.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cstring>
#include "Headers/Player.h"


std::vector<std::string> splitString(const std::string &mediator, char splitBy) {
    std::vector<std::string> files;
    std::stringstream check1(mediator);
    std::string intermediate;
    while (getline(check1, intermediate, splitBy)) {
        files.push_back(intermediate);
    }
    return files;
}

bool rangeCalculation(int range, int x1, int y1, int x2, int y2) {
    if (abs(x1 - x2) + abs(y1 - y2) <= range)
        return true;
    else
        return false;
}

int changeActionPoints(FightingUnit *fightingUnit, int x, int y) {
    int actionsPoints = fightingUnit->getActionPoints();
    int usingActionPoints = abs(x - fightingUnit->getLocalizationX()) + abs(y - fightingUnit->getLocalizationY());

    return actionsPoints - usingActionPoints;
}

void checkPlayerCommand(const std::string &file, Player *player, Base *playerBase, Base *enemyBase,
                        std::map<int, FightingUnit *> fightingUnits, char owner, Board board) {
    std::vector<std::string> commandLine;
    std::ifstream loadboard(file);
    std::string rowLoad;
    std::vector<std::string> commandSplited;

    //if exist file
    if (loadboard) {
        //load row from file in format string
        while (!loadboard.eof()) {
            getline(loadboard, rowLoad);
            commandLine.push_back(rowLoad);
        }


        for (auto command: commandLine) {
            commandSplited = splitString(command, ' ');

            //Checking command for Base
            if (to_string(playerBase->getId()) == commandSplited[0] && commandSplited.size() == 3) {
                if (commandSplited[1] == "B" && playerBase->getProductionTime() == 0) {
                    //Checking build existing unit Type
                    if (commandSplited[2] == "K" || commandSplited[2] == "S" || commandSplited[2] == "A"
                        || commandSplited[2] == "P" || commandSplited[2] == "R" || commandSplited[2] == "C" ||
                        commandSplited[2] == "W") {
                        char *unitType = new char[commandSplited[2].length()];
                        std::strcpy(unitType, commandSplited[2].c_str());

                        switch (unitType[0]) {
                            case 'K':
                                player->setGold(player->getGold() - 400);
                                break;
                            case 'S':
                                player->setGold(player->getGold() - 250);
                                break;
                            case 'A':
                                player->setGold(player->getGold() - 250);
                                break;
                            case 'P':
                                player->setGold(player->getGold() - 200);
                                break;
                            case 'R':
                                player->setGold(player->getGold() - 500);
                                break;
                            case 'C':
                                player->setGold(player->getGold() - 800);
                                break;
                            case 'W':
                                player->setGold(player->getGold() - 100);
                                break;
                        }

                        playerBase->setProductionType(unitType[0]);

                    }

                } else
                    std::cout << "Command: " + command + " are incorrect";

            } else {

                //checking command for fighting unit
                if (fightingUnits[stoi(commandSplited[0])]->getOwner() == owner) {
                    //checking command attack
                    if (commandSplited[1] == "A" && commandSplited.size() == 3) {
                        if (fightingUnits[stoi(commandSplited[2])]) {
                            //checking command attacked unit if is an enemy unit
                            if (fightingUnits[stoi(commandSplited[2])]->getOwner() != owner) {
                                //cheching attack range
                                if (rangeCalculation(fightingUnits[stoi(commandSplited[0])]->getRange(),
                                                     fightingUnits[stoi(commandSplited[0])]->getLocalizationX(),
                                                     fightingUnits[stoi(commandSplited[0])]->getLocalizationY(),
                                                     fightingUnits[stoi(commandSplited[2])]->getLocalizationX(),
                                                     fightingUnits[stoi(commandSplited[2])]->getLocalizationY())) {
                                    int enemyHP = fightingUnits[stoi(commandSplited[2])]->getDurability();
                                    char *attackingEnemyType = new char[fightingUnits[stoi(
                                            commandSplited[2])]->getName().length()];
                                    std::strcpy(attackingEnemyType,
                                                fightingUnits[stoi(commandSplited[2])]->getName().c_str());

                                    int attack = fightingUnits[stoi(commandSplited[0])]->getAttack(
                                            attackingEnemyType[0]);
                                    fightingUnits[stoi(commandSplited[2])]->setDurability(enemyHP - attack);
                                    fightingUnits[stoi(commandSplited[0])]->setAlreadyAttacking();

                                } else
                                    std::cout << "Command: " + command + " are incorrect";
                            } else
                                std::cout << "Command: " + command + " are incorrect";

                            //checking movement command
                        } else if (commandSplited[1] == "M" && commandSplited.size() == 4) {

                            if (board.getBoardHeight() > stoi(commandSplited[2]) &&
                                board.getBoardWidth() > stoi(commandSplited[3]) && 0 <= stoi(commandSplited[2]) &&
                                0 <= stoi(commandSplited[2])) {

                                //checking localization enemy base, natural blockers
                                if ((enemyBase->getLocalizationY() != stoi(commandSplited[2]) ||
                                     enemyBase->getLocalizationX() != stoi(commandSplited[3])) ||
                                    board.getBoardPoint(stoi(commandSplited[2]), stoi(commandSplited[3])) == '6') {

                                    bool isEnemyUnit = false;
                                    for (auto [index, i]: fightingUnits) {
                                        if ((i->getLocalizationY() == stoi(commandSplited[2]) &&
                                             i->getLocalizationX() == stoi(commandSplited[3]))) {
                                            isEnemyUnit = true;
                                        }
                                        if (!isEnemyUnit && (
                                                //checking actions point for movement
                                                rangeCalculation(
                                                        fightingUnits[stoi(commandSplited[0])]->getActionPoints(),
                                                        fightingUnits[stoi(commandSplited[0])]->getLocalizationX(),
                                                        fightingUnits[stoi(commandSplited[0])]->getLocalizationY(),
                                                        stoi(commandSplited[2]), stoi(commandSplited[3])))) {

                                            //new action point of unit
                                            fightingUnits[stoi(commandSplited[0])]->setActionPoints(
                                                    changeActionPoints(fightingUnits[stoi(commandSplited[0])],
                                                                       stoi(commandSplited[2]),
                                                                       stoi(commandSplited[3])));
                                            //new localization of unit
                                            fightingUnits[stoi(commandSplited[0])]->setLocalization(
                                                    stoi(commandSplited[2]),
                                                    stoi(commandSplited[3]));


                                        }
                                    }
                                }
                            }
                        } else
                            std::cout << "Command: " + command + " are incorrect";
                    } else
                        std::cout << "Command: " + command + " are incorrect";
                }
            }
        }
    } else {
        std::cout << "not Found command file";
    }

}


//Function using to clear map from defeated units
std::map<int, FightingUnit *> eliminateDefeatedUnits(std::map<int, FightingUnit *> fightingUnits) {

    vector<int> idUnits;
    //loking for units with 0 or less hp
    for (auto [id, unit]: fightingUnits) {
        if (unit->getDurability() <= 0) {
            idUnits.push_back(unit->getId());
        }
    }
    //erase units from map
    for (auto id: idUnits) {
        fightingUnits.erase(id);
    }
    return fightingUnits;
}

std::map<int, FightingUnit *>
newRound(Player *player, Base *base, std::map<int, FightingUnit *> fightingUnits, char owner, Board board) {
    for (auto [id, unit]: fightingUnits) {
        if (unit->getOwner() == owner) {
            unit->newRound();
            if (board.getBoardPoint(unit->getLocalizationX(), unit->getLocalizationY()) == '6')
                player->setGold(player->getGold() + 50);
        }
        if (base->getProductionTime() > 0) {
            base->setProductionTime(base->getProductionTime() - 1);
            if (base->getProductionTime() == 0) {
                FightingUnit *fightingUnit;
                switch (base->getProductionType()) {
                    case 'K':
                        fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),
                                                        owner, Knight);
                        break;
                    case 'S':
                        fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),
                                                        owner, Swordsman);
                        break;
                    case 'A':
                        fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),
                                                        owner, Archer);
                        break;
                    case 'P':
                        fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),
                                                        owner, Pikeman);
                        break;
                    case 'R':
                        fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),
                                                        owner, Ram);
                        break;
                    case 'C':
                        fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),
                                                        owner, Catapult);
                        break;
                    case 'W':
                        fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),
                                                        owner, Worker);
                        break;
                }

                fightingUnits[fightingUnit->getId()] = fightingUnit;
                base->setProductionType('0');
            }
        }

    }
    return fightingUnits;
}

void saveStatusToFile(string file, Player *player, Base *playerBase, Base *enemyBase, std::map<int, FightingUnit *> fightingUnits) {
    vector<string> linesToFile;
    linesToFile.push_back(to_string(player->getGold()) + " //ilosc zlota ");
    linesToFile.push_back("P B " + to_string(playerBase->getId()) + " " + to_string(playerBase->getLocalizationY()) + " " + to_string(playerBase->getLocalizationX()) + " " + to_string(playerBase->getDurability()) + " " + playerBase->getProductionType());
    linesToFile.push_back("E B " + to_string(enemyBase->getId()) + " " + to_string(enemyBase->getLocalizationY()) + " " + to_string(enemyBase->getLocalizationX()) + " " + to_string(enemyBase->getDurability()) + " " + enemyBase->getProductionType());
    for(auto [id,unit]:fightingUnits){
        linesToFile.push_back(to_string(unit->getOwner()) + " "+ unit->getName() + " "+ to_string(unit->getId()) + " " + to_string(unit->getLocalizationY()) + " " + to_string(unit->getLocalizationX()) + " " + to_string(unit->getDurability()));
    }

    ofstream saveToFile(file);
    for(auto line:linesToFile){
        saveToFile<<line<<endl;
    }
}