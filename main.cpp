#include <iostream>
#include <vector>
#include <map>

#include "Headers/Units.h"
#include "Headers/Board.h"
#include "GameActions.cpp"


int main() {
    string mediator = "D:\\Users\\trane\\CLionProjects\\untitled\\mapa.txt D:\\Users\\trane\\CLionProjects\\untitled\\status.txt D:\\Users\\trane\\CLionProjects\\untitled\\rozkazy.txt";
    vector<string> files = splitString(mediator, ' ');
    int *playerLocalization;
    bool endGame;

    Player *player;
    Player *enemyPlayer;
    player = new Player();
    enemyPlayer = new Player();
    Board board(files[0]);
    Base *playerBase;
    Base *enemyBase;
    std::map<int, FightingUnit *> fightingUnits;
    playerLocalization = board.getLocationPlayer('1');
    playerBase = new Base(playerLocalization[0], playerLocalization[1], 'P');
    playerLocalization = board.getLocationPlayer('2');
    enemyBase = new Base(playerLocalization[0], playerLocalization[1], 'E');

    int round = 1;
    while (!endGame) {
        if (round % 2 != 0) {
            checkPlayerCommand(files[2], player, playerBase, enemyBase, fightingUnits, 'P', board);
            fightingUnits = eliminateDefeatedUnits(fightingUnits);
            fightingUnits = newRound(player, playerBase, fightingUnits, 'P', board);
            saveStatusToFile(files[1],player,playerBase,enemyBase,fightingUnits);

            std::cout<<"Runda Gracza 2: zatwierdz"<<endl;
            system("pause");
            system("CLS");

        } else {
            checkPlayerCommand(files[2], enemyPlayer, enemyBase, playerBase, fightingUnits, 'E', board);
            fightingUnits = eliminateDefeatedUnits(fightingUnits);
            fightingUnits = newRound(enemyPlayer, enemyBase, fightingUnits, 'E', board);
            saveStatusToFile(files[1],enemyPlayer,enemyBase,playerBase,fightingUnits);
            std::cout<<"Runda Gracza 1: zatwierz"<<endl;
            system("pause");
            system("CLS");
        }

        if (playerBase->getDurability() <= 0) {
            std::cout<<"Gracz 2 wygral!";
            endGame = !endGame;
        }
        if(enemyBase->getDurability() <= 0){
            std::cout<<"Gracz 1 wygral!";
            endGame = !endGame;
        }


    }

    return 0;
}

