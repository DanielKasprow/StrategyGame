//
// Created by Daniel Kasprow on 28.04.2023.
//
#include "../Headers/Units.h"

using namespace std;


FightingUnit::FightingUnit(int localizationY, int localizationX, char ownerUnit, UnitType unitType) : Unit( ownerUnit, localizationY, localizationX) {
    switch (unitType) {
        case Knight:
            name = "K";
            durability = 70;
            speed = actionPoints = 200;
            range = 1;
            attack = new int[8];
            attack[0]=attack[1]=attack[2]=attack[3]=attack[4]=attack[6]=attack[7]= 35;
            attack[5]=50;
            break;
        case Swordsman:
            name = "S";
            durability = 60;
            speed = actionPoints = 2;
            range = 1;
            attack = new int[8];
            attack[0]=attack[1]=attack[2]=attack[5]=attack[6]=attack[7]= 30;
            attack[3]=attack[4]=20;
            break;
        case Archer:
            name = "A";
            durability = 40;
            speed = actionPoints = 2;
            range = 5;
            attack = new int[8];
            attack[0]=attack[1]=attack[2]=attack[3]=attack[6]=attack[7]= 15;
            attack[4]=attack[5]=10;
            break;
        case Pikeman:
            name = "P";
            durability = 50;
            speed = actionPoints = 2;
            range = 2;
            attack = new int[8];
            attack[0]=35;
            attack[1]=attack[2]=attack[3]=attack[4]=attack[6]= 15;
            attack[5]=attack[7]=10;
            break;
        case Catapult:
            name = "C";
            durability = 50;
            speed = actionPoints = 2;
            range = 7;
            attack = new int[8];
            attack[0]=attack[1]=attack[2]=attack[3]=attack[4]=attack[5]=attack[6]= 40;
            attack[7]=50;
            break;
        case Ram:
            name = "R";
            durability = 90;
            speed = actionPoints = 2;
            range = 1;
            attack = new int[8];
            attack[0]=attack[1]=attack[2]=attack[3]=attack[4]=attack[5]=attack[6]= 10;
            attack[7]=50;
            break;

        case Worker:
            name = "W";
            durability = 20;
            speed = actionPoints = 2;
            range = 1;
            attack = new int[8];
            attack[0]=attack[1]=attack[2]=attack[3]=attack[4]=attack[5]=attack[6]= 5;
            attack[7]=1;
            break;
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
            break;
        case 'S':
            return attack[1];
            break;
        case 'A':
            return attack[2];
            break;
        case 'P':
            return attack[3];
            break;
        case 'R':
            return attack[4];
            break;
        case 'C':
            return attack[5];
            break;
        case 'W':
            return attack[6];
            break;
        case 'B':
            return attack[7];
            break;
    }
}








