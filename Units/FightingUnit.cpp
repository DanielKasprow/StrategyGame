//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;


FightingUnit::FightingUnit(char ownerUnit, UnitType unitType) : Unit("name", 7, 1, ownerUnit) {
    switch (unitType) {
        case Knight:
            name = "K";
            durability = 70;
            speed = 5;
            price = 400;
            range = 1;
            buildTime = 5;
            break;
        case Swordsman:
            name = "S";
            durability = 60;
            speed = 2;
            price = 250;
            range = 1;
            buildTime = 3;
            break;
        case Archer:
            name = "A";
            durability = 40;
            speed = 2;
            price = 250;
            range = 5;
            buildTime = 3;
            break;
        case Pikeman:
            name = "P";
            durability = 50;
            speed = 2;
            price = 200;
            range = 2;
            buildTime = 3;
            break;
        case Ram:
            name = "R";
            durability = 90;
            speed = 2;
            price = 500;
            range = 1;
            buildTime = 4;
            break;
        case Catapult:
            name = "C";
            durability = 50;
            speed = 2;
            price = 800;
            range = 7;
            buildTime = 6;
            break;
    }

};

int FightingUnit::getDurability() {
    return durability;
}

void FightingUnit::setDurability(int durability) {
    FightingUnit::durability = durability;
}

int FightingUnit::getSpeed() {
    return speed;
}

int FightingUnit::getPrice() {
    return price;
}

int FightingUnit::getRange() {
    return range;
}

int FightingUnit::getBuildTime() {
    return buildTime;
}

int FightingUnit::getLocalizationX() {
    return localizationX;
}

int FightingUnit::getLocalizationY() {
    return localizationY;
}

void FightingUnit::setLocalizationX(int localizationX) {
    FightingUnit::localizationX = localizationX;
}

void FightingUnit::setLocalizationY(int localizationY) {
    FightingUnit::localizationY = localizationY;
}

int FightingUnit::getId() {
    return unitId;
}

char FightingUnit::getOwner() {
    return ownerUnit;
}

FightingUnit::~FightingUnit() {}






