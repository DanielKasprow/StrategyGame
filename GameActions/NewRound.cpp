//
// Created by Daniel kasprow on 10.05.23.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <map>


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

//function using to reset actions point, gain gold by workers etc. in new round
std::map<int, FightingUnit *>
newRound(Player *player, Base *base, std::map<int, FightingUnit *> fightingUnits, char owner, Board board) {
    for (auto [id, unit]: fightingUnits) {
        if (unit->getOwner() == owner) {
            unit->newRound();
            if (board.getBoardPoint(unit->getLocalizationY(), unit->getLocalizationX()) == '6')
                player->setGold(player->getGold() + 50);
        }
    }
    if (base->getProductionTime() > 0) {
        base->setProductionTime(base->getProductionTime() - 1);
        //create new instance of unit when base finish build unit
        if (base->getProductionTime() == 0) {
            FightingUnit *fightingUnit;
            switch (base->getProductionType()) {
                case 'K':
                    fightingUnit = new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),owner, Knight);
                            //new FightingUnit(base->getLocalizationY(), base->getLocalizationX(),owner, Knight);
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


    return fightingUnits;
}

//Function which save to file status of the game
void saveStatusToFile(const std::string& file, Player player, Base playerBase, const Base& enemyBase,
                      const std::map<int, FightingUnit *>& fightingUnits) {


    ofstream saveToFile(file);
    auto saveBaseToFile = [](Base base, char owner) -> std::string {
        return
                std::string(1, base.getOwner()) + " B " + std::to_string(base.getId()) + " " + std::to_string(base.getLocalizationY()) + " " +
                std::to_string(base.getLocalizationX()) + " " + std::to_string(base.getDurability()) + " " +
                base.getProductionType() +
                +" // baza " +((base.getOwner()==owner)?"gracza":"przeciwnika") + " w pozycji " + std::to_string(base.getLocalizationY()) + "," +
                std::to_string(base.getLocalizationX()) + " wytrzymałość " + std::to_string(base.getDurability())
                + ((base.getProductionTime()>0)?(", w trakcie produkowania jednostki"):" jednostek niczego nie produkuje");
    };
    auto saveUnitToFile = [](FightingUnit unit, char owner) -> std::string {
        return
                std::string(1, unit.getOwner()) + " " + unit.getName() + " " + to_string(unit.getId()) + " " +
                to_string(unit.getLocalizationY()) + " " + to_string(unit.getLocalizationX()) + " " +
                to_string(unit.getDurability()) + " // "+unit.getUnitType() + ((unit.getOwner()==owner)?" gracza":" przeciwnika")
                + " na pozycji " + to_string(unit.getLocalizationY()) + "," + to_string(unit.getLocalizationX())
                +" wytrzymalosc "+ to_string(unit.getDurability()) + ((unit.getDurability()==1)?" jednostka":" jednostek");

    };

    saveToFile << to_string(player.getGold()) + " //ilosc zlota " << endl;
    saveToFile << saveBaseToFile(playerBase,playerBase.getOwner()) << endl;
    saveToFile << saveBaseToFile(enemyBase,playerBase.getOwner()) << endl;

    for (auto [id, unit]: fightingUnits) {
        saveToFile <<saveUnitToFile(*unit, playerBase.getOwner())<<endl;
    }
    saveToFile.close();

}