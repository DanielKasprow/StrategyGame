//
// Created by Daniel Kasprow on 28.04.2023.
//
#include "../Headers/Units.h"

FightingUnit::FightingUnit(int localizationY, int localizationX, char ownerUnit, UnitType unitType) : Unit( ownerUnit, localizationY, localizationX) {
    FightingUnit::unitType = unitType;
    switch (unitType) {

        case Knight:
            name = "K";
            durability = 70;
            speed = actionPoints = 200;
            range = 1;
            attack = new int[8]{35,35,35,35,35,35,35,50};
            break;
        case Swordsman:
            name = "S";
            durability = 60;
            speed = actionPoints = 2;
            range = 1;
            attack = new int[8]{30,30,30,20,20,30,30,30};
            break;
        case Archer:
            name = "A";
            durability = 40;
            speed = actionPoints = 2;
            range = 5;
            attack = new int[8]{15,15,15,15,10,10,15,15};
            break;
        case Pikeman:
            name = "P";
            durability = 50;
            speed = actionPoints = 2;
            range = 2;
            attack = new int[8]{35,15,15,15,15,10,15,10};
            break;
        case Catapult:
            name = "C";
            durability = 50;
            speed = actionPoints = 2;
            range = 7;
            attack = new int[8]{40,40,40,40,40,40,40,50};
            break;
        case Ram:
            name = "R";
            durability = 90;
            speed = actionPoints = 2;
            range = 1;
            attack = new int[8]{10,10,10,10,10,10,10,50};
            break;

        case Worker:
            name = "W";
            durability = 20;
            speed = actionPoints = 2;
            range = 1;
            attack = new int[8]{5,5,5,5,5,5,5,1};
            break;
    }

}
string FightingUnit::getUnitType(){
    switch(unitType){
        case Knight: return "Knight";
        case Swordsman:return "Swordsman";
        case Archer:return "Archer";
        case Pikeman:return "Pikeman";
        case Catapult:return "Catapult";
        case Ram:return "Ram";
        case Worker:return "Worker";
    }

}

string FightingUnit::getName(){
    return name;
}

int FightingUnit::getDurability() {
    return durability;
}

void FightingUnit::setDurability(int durability) {
    FightingUnit::durability = durability;
}

int FightingUnit::getSpeed() {
    return speed;
}

int FightingUnit::getRange() {
    return range;
}

int FightingUnit::getLocalizationX() {
    return localizationX;
}

int FightingUnit::getLocalizationY() {
    return localizationY;
}

void FightingUnit::setLocalization(int localizationY, int localizationX) {
    FightingUnit::localizationX = localizationX;
    FightingUnit::localizationY = localizationY;

}

int FightingUnit::getId() {
    return unitId;
}

char FightingUnit::getOwner() {
    return ownerUnit;
}

FightingUnit::~FightingUnit() = default;

int FightingUnit::getActionPoints() {
    return actionPoints;
}

void FightingUnit::setActionPoints(int actionPoints) {
    FightingUnit::actionPoints = actionPoints;
}

void FightingUnit::newRound() {
    FightingUnit::actionPoints = speed;
    FightingUnit::alreadyAttacking = false;
}

bool FightingUnit::getAlreadyAttacking() {
    return alreadyAttacking;
}

void FightingUnit::setAlreadyAttacking() {
    FightingUnit::alreadyAttacking = true;
}

int FightingUnit::getAttack(char unitAttacking) {
    switch (unitAttacking) {
        case 'K':
            return attack[0];
        case 'S':
            return attack[1];
        case 'A':
            return attack[2];
        case 'P':
            return attack[3];
        case 'R':
            return attack[4];
        case 'C':
            return attack[5];
        case 'W':
            return attack[6];
        case 'B':
            return attack[7];
    }
    return 0;
}








