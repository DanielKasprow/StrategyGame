//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Swordsman::Swordsman() : Unit("Swordsman", 60, 2) {
    price = 250;
    range = 1;
    buildTime = 3;
    //delete [] attack;
    //int attack[8] = {35,35,35,35,35,50,35,35};
};

//long Swordsman::getId() {
//return id;
//}

int Swordsman::getDurability() {
    return durability;
}

void Swordsman::setDurability(int durability) {
    this->durability = durability;
}

int Swordsman::getSpeed() {
    return speed;
}

int Swordsman::getPrice() {
    return price;
}

int Swordsman::getRange() {
    return range;
}

int Swordsman::getBuildTime() {
    return buildTime;
}

int Swordsman::getLocalizationX() {
    return localizationX;
}

int Swordsman::getLocalizationY() {
    return localizationY;
}

void Swordsman::setLocalizationX(int localizationX) {
    this->localizationX = localizationX;
}

void Swordsman::setLocalizationY(int localizationY) {
    this->localizationY = localizationY;
}

int Swordsman::getId() {
    return unitId;
}

Swordsman::~Swordsman() {}


/*

int Swordsman::getAttack(int unitAttacking) {
    return attack[unitAttacking];
}*/
