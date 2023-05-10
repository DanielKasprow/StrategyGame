#include <iostream>
#include <vector>
#include <map>
#include <thread>

#include "Headers/Units.h"
#include "Headers/Board.h"
#include "gameActions/GameActions.cpp"
#include "gameActions/NewRound.cpp"
#include "gameActions/GamePreparing.cpp"


int main(int argc, char **argv) {
    std::vector<std::string> files = argToVector(argc, argv);
    int timePerRoundInSeconds = getTimePerRound( files[3]);



    int delay = timePerRoundInSeconds;
    delay *= CLOCKS_PER_SEC;
    clock_t now;

    Player *player;
    Player *enemyPlayer;
    player = new Player();
    enemyPlayer = new Player();
    Board board(files[0]);
    Base *playerBase;
    Base *enemyBase;
    std::map<int, FightingUnit *> fightingUnits;

    //set base players location from file
    int *playerLocalization;
    playerLocalization = board.getLocationPlayer('1');
    playerBase = new Base(playerLocalization[0], playerLocalization[1], 'P');
    playerLocalization = board.getLocationPlayer('2');
    enemyBase = new Base(playerLocalization[0], playerLocalization[1], 'E');

    int round = 0;
    while (round < 2000) {
        round++;
        system("clear");
        switch (round % 2) {
            case 1:
                saveStatusToFile(files[1], *player, *playerBase, *enemyBase, fightingUnits);
                std::cout << "\nRunda Gracza 1: czas " + to_string(timePerRoundInSeconds) + " secundy" << endl;
                now = clock();
                while(clock() - now <delay);

                checkPlayerCommand(files[2], player, playerBase, enemyBase, fightingUnits, 'P', board);
                fightingUnits = eliminateDefeatedUnits(fightingUnits);
                fightingUnits = newRound(player, playerBase, fightingUnits, 'P', board);
                break;

            case 0:
                saveStatusToFile(files[1], *enemyPlayer, *enemyBase,*playerBase,  fightingUnits);
                std::cout << "\nRunda Gracza 2: czas " + to_string(timePerRoundInSeconds) + " secundy" << endl;
                now = clock();
                while(clock() - now <delay);

                checkPlayerCommand(files[2], enemyPlayer, enemyBase, playerBase, fightingUnits, 'E', board);
                fightingUnits = eliminateDefeatedUnits(fightingUnits);
                fightingUnits = newRound(enemyPlayer, enemyBase, fightingUnits, 'E', board);
                break;
        }

        //checking players base durability if have 0 or less, it's game over
        if (playerBase->getDurability() <= 0) {
            std::cout << "Gracz 2 wygral!";
            break;
        }
        if (enemyBase->getDurability() <= 0) {
            std::cout << "Gracz 1 wygral!";
            break;
        }
        if (round >= 2000)
            std::cout << "Koniec gry, czas minął!";
    }

    return 0;
}

