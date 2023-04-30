//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Archer::Archer() : Unit("Archer", 40, 2) {
    price = 240;
    range = 5;
    buildTime = 3;
    //delete [] attack;
    //int attack[8] = {35,35,35,35,35,50,35,35};
};

//long Archer::getId() {
//return id;
//}


int Archer::getDurability() {
    return durability;
}

void Archer::setDurability(int durability) {
    this->durability = durability;
}

int Archer::getSpeed() {
    return speed;
}

int Archer::getPrice() {
    return price;
}

int Archer::getRange() {
    return range;
}

int Archer::getBuildTime() {
    return buildTime;
}

int Archer::getLocalizationX() {
    return localizationX;
}

int Archer::getLocalizationY() {
    return localizationY;
}

void Archer::setLocalizationX(int localizationX) {
    this->localizationX = localizationX;
}

void Archer::setLocalizationY(int localizationY) {
    this->localizationY = localizationY;
}

int Archer::getId() {
    return unitId;
}

Archer::~Archer() {}


/*

int Archer::getAttack(int unitAttacking) {
    return attack[unitAttacking];
}*/
