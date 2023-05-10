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
#include "../Headers/Player.h"

std::vector<std::string> splitString(const std::string &line, char splitBy) {
    std::vector<std::string> files;
    std::stringstream check1(line);
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

void changeGoldOfPlayerAndSetProductionToBase(Base *playerBase, Player *player, int cost, int productionTime, char unitType) {
    if (player->getGold() - cost > 0) {
        player->setGold(player->getGold() - cost);
        playerBase->setProductionTime(productionTime);
        playerBase->setProductionType(unitType);
    } else
        cout << "Nie wystarczajaca ilosc zlota";
}

//set unit production in base player
void setBaseProduction(Base *playerBase, Player *player, string productionType) {
    char *unitType = new char[productionType.length()];
    std::strcpy(unitType, productionType.c_str());

    switch (unitType[0]) {
        case 'K':
            changeGoldOfPlayerAndSetProductionToBase(playerBase, player, 400, 5, unitType[0]);
            break;
        case 'S':
            changeGoldOfPlayerAndSetProductionToBase(playerBase, player, 250, 3, unitType[0]);
            break;
        case 'A':
            changeGoldOfPlayerAndSetProductionToBase(playerBase, player, 250, 3, unitType[0]);
            break;
        case 'P':
            changeGoldOfPlayerAndSetProductionToBase(playerBase, player, 200, 3, unitType[0]);
            break;
        case 'R':
            changeGoldOfPlayerAndSetProductionToBase(playerBase, player, 500, 4, unitType[0]);
            break;
        case 'C':
            changeGoldOfPlayerAndSetProductionToBase(playerBase, player, 800, 6, unitType[0]);
            break;
        case 'W':
            changeGoldOfPlayerAndSetProductionToBase(playerBase, player, 100, 2, unitType[0]);
            break;
    }
}

void checkPlayerCommand(const std::string &file, Player *player, Base *playerBase, Base *enemyBase,
                        std::map<int, FightingUnit *> fightingUnits, char owner, Board board) {
    std::vector<std::string> commandLine;
    std::ifstream loadBoard(file);
    std::string rowLoad;
    std::vector<std::string> commandSplited;

    //if exist file
    if (loadBoard) {

        //load row from file in format string
        while (!loadBoard.eof()) {
            getline(loadBoard, rowLoad);
            if (rowLoad.length() > 0)
                commandLine.push_back(rowLoad);
        }


        for (auto command: commandLine) {

            commandSplited = splitString(command, ' ');

            //Checking command for Base
            if (to_string(playerBase->getId()) == commandSplited[0] && commandSplited.size() == 3) {
                if (commandSplited[1] == "B" && playerBase->getProductionTime() <= 0) {
                    //Checking build existing unit Type
                    if (commandSplited[2] == "K" || commandSplited[2] == "S" || commandSplited[2] == "A"
                        || commandSplited[2] == "P" || commandSplited[2] == "R" || commandSplited[2] == "C" ||
                        commandSplited[2] == "W") {
                        setBaseProduction(playerBase, player, commandSplited[2]);
                    }

                } else
                    std::cout << "Komenda: " + command + " jest nie prawidlowa";

            } else {
                if (fightingUnits[stoi(commandSplited[0])]) {
                    //checking command for fighting unit
                    if (fightingUnits[stoi(commandSplited[0])]->getOwner() == owner) {
                        //checking command attack
                        if (commandSplited[1] == "A" && commandSplited.size() == 3) {
                            //Checking unit if attack in this round
                            if (!fightingUnits[stoi(commandSplited[0])]->getAlreadyAttacking()) {
                                //if attack enemy unit
                                if (fightingUnits[stoi(commandSplited[2])]) {
                                    //checking command attacked unit if is an enemy unit
                                    if (fightingUnits[stoi(commandSplited[2])]->getOwner() != owner) {
                                        //checking attack range
                                        if (rangeCalculation(fightingUnits[stoi(commandSplited[0])]->getRange(),
                                                             fightingUnits[stoi(commandSplited[0])]->getLocalizationX(),
                                                             fightingUnits[stoi(commandSplited[0])]->getLocalizationY(),
                                                             fightingUnits[stoi(commandSplited[2])]->getLocalizationX(),
                                                             fightingUnits[stoi(
                                                                     commandSplited[2])]->getLocalizationY())) {


                                            //change durability of attacked unit
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
                                            std::cout << "Komenda: " + command + " jest nie prawidlowa";
                                    } else
                                        std::cout << "Komenda: " + command + " jest nie prawidlowa";

                                    //checking attack enemy base
                                } else if (enemyBase->getId() == stoi(commandSplited[2])) {
                                    //cheching attack range
                                    if (rangeCalculation(fightingUnits[stoi(commandSplited[0])]->getRange(),
                                                         fightingUnits[stoi(commandSplited[0])]->getLocalizationX(),
                                                         fightingUnits[stoi(commandSplited[0])]->getLocalizationY(),
                                                         enemyBase->getLocalizationX(),
                                                         enemyBase->getLocalizationY())) {

                                        //change durability of attacked unit
                                        int enemyHP = enemyBase->getDurability();
                                        char *attackingEnemyType = new char[enemyBase->getName().length()];
                                        std::strcpy(attackingEnemyType,
                                                    enemyBase->getName().c_str());
                                        int attack = fightingUnits[stoi(commandSplited[0])]->getAttack(
                                                attackingEnemyType[0]);
                                        enemyBase->setDurability(enemyHP - attack);
                                        fightingUnits[stoi(commandSplited[0])]->setAlreadyAttacking();

                                    } else
                                        std::cout << "Komenda: " + command + " jest nie prawidlowa";
                                } else
                                    std::cout << "Komenda: " + command + " jest nie prawidlowa";

                            } else
                                std::cout
                                        << "Jednostka: " + to_string(fightingUnits[stoi(commandSplited[0])]->getId()) +
                                           " juz atakowala w tej rundzie";
                        } else if (commandSplited[1] == "M" && commandSplited.size() == 4) {

                            if (board.getBoardHeight() > stoi(commandSplited[2]) &&
                                board.getBoardWidth() > stoi(commandSplited[3]) && 0 <= stoi(commandSplited[2]) &&
                                0 <= stoi(commandSplited[2])) {

                                //checking localization enemy base, natural blockers
                                if (!(enemyBase->getLocalizationY() == stoi(commandSplited[2]) &&
                                      enemyBase->getLocalizationX() == stoi(commandSplited[3])) &&
                                    board.getBoardPoint(stoi(commandSplited[2]), stoi(commandSplited[3])) != '9') {

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
                                } else
                                    std::cout << "Komenda: " + command + " jest nie prawidlowa";
                            } else
                                std::cout << "Komenda: " + command + " jest nie prawidlowa";
                        } else
                            std::cout << "Komenda: " + command + " jest nie prawidlowa";
                    } else
                        std::cout << "Komenda: " + command + " jest nie prawidlowa";
                } else
                    std::cout << "Komenda: " + command + " jest nie prawidlowa";
            }
        }
    } else {
        std::cout << "Nie znaleziono pliku";
    }

}

