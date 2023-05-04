#include <iostream>
#include <vector>
#include <map>

#include "Headers/Units.h"
#include "Headers/Board.h"
#include "GameActions.cpp"
using namespace std;



int main() {
    string mediator = "D:\\Users\\trane\\CLionProjects\\untitled\\mapa.txt D:\\Users\\trane\\CLionProjects\\untitled\\status.txt D:\\Users\\trane\\CLionProjects\\untitled\\rozkazy.txt";
    vector<string> files = splitString(mediator, ' ');

    bool endGame;
    Board board(files[0]);
    cout<<board.getBoardPoint(4,30);
    std::map<int, FightingUnit*> fightingUnits;
    std::map<int, Worker*> workers;
    Base *playerBase;
    Base *enemyBase;


    FightingUnit *fightingUnit = new FightingUnit('P', Knight);
    fightingUnits[fightingUnit->getId()] = fightingUnit;
    fightingUnit = new FightingUnit('P', Swordsman);
    fightingUnits[fightingUnit->getId()] = fightingUnit;


    playerBase = new Base(0,0,'P');
    enemyBase = new Base(31,4,'E');


    while(!endGame){


        if(playerBase->getDurability()<=0 || enemyBase->getDurability()<=0) {
            endGame = !endGame;
        }
        endGame = !endGame;
    }*/

    //cout<<localizationPlayer;

    //playerBase = new Base(1,1,'P');

    //holder.push_back(new FightingUnit('P', Knight));
    //holder.push_back(new FightingUnit('P', Catapult));

    //holder[0]->setDurability(0);

    return 0;
}