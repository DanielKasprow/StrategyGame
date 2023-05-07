#include <iostream>
#include <vector>
#include <map>

#include "Headers/Units.h"
#include "Headers/Board.h"
#include "gameActions/GameActions.cpp"


int main() {
    std::cout<<"podaj sciezkie plikow mapa.txt status.txt rozkazy.txt"<<endl;
    string mediator;
    std::cin>>mediator;
    system("clear");
    vector<string> files = splitString(mediator, ' ');
    int *playerLocalization;
    
    Player *player;
    Player *enemyPlayer;
    player = new Player();
    enemyPlayer = new Player();
    Board board(files[0]);
    Base *playerBase;
    Base *enemyBase;
    std::map<int, FightingUnit *> fightingUnits;

    //set base players location from file
    playerLocalization = board.getLocationPlayer('1');
    playerBase = new Base(playerLocalization[0], playerLocalization[1], 'P');
    playerLocalization = board.getLocationPlayer('2');
    enemyBase = new Base(playerLocalization[0], playerLocalization[1], 'E');

    int round = 0;
    while (round < 2000) {
        round++;
        if (round % 2 != 0) {
            saveStatusToFile(files[1],player,playerBase,enemyBase,fightingUnits);
            std::cout<<"\nRunda Gracza 1: zatwierdz"<<endl;
            std::cin.get();
            system("clear");
            checkPlayerCommand(files[2], player, playerBase, enemyBase, fightingUnits, 'P', board);
            fightingUnits = eliminateDefeatedUnits(fightingUnits);
            fightingUnits = newRound(player, playerBase, fightingUnits, 'P', board);



        } else {
            saveStatusToFile(files[1],enemyPlayer,playerBase,enemyBase,fightingUnits);
            std::cout<<"\nRunda Gracza 2: zatwierdz"<<endl;
            std::cin.get();
            system("clear");
            checkPlayerCommand(files[2], enemyPlayer, enemyBase, playerBase, fightingUnits, 'E', board);
            fightingUnits = eliminateDefeatedUnits(fightingUnits);
            fightingUnits = newRound(enemyPlayer, enemyBase, fightingUnits, 'E', board);


        }

        //checking players base durability if have 0 or less, it's game over
        if (playerBase->getDurability() <= 0) {
            std::cout<<"Gracz 2 wygral!";
            break;
        }
        if(enemyBase->getDurability() <= 0){
            std::cout<<"Gracz 1 wygral!";
            break;
        }
        if(round >= 2000)
            std::cout<<"Koniec gry, czas minął!";
    }

    return 0;
}

