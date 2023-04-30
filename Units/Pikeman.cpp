//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Pikeman::Pikeman() : Unit("Pikeman", 50, 2) {
    price = 200;
    range = 2;
    buildTime = 3;
    //delete [] attack;
    //int attack[8] = {35,35,35,35,35,50,35,35};
};

int Pikeman::getDurability() {
    return durability;
}

void Pikeman::setDurability(int durability) {
    this->durability = durability;
}

int Pikeman::getSpeed() {
    return speed;
}

int Pikeman::getPrice() {
    return price;
}

int Pikeman::getRange() {
    return range;
}

int Pikeman::getBuildTime() {
    return buildTime;
}

int Pikeman::getLocalizationX() {
    return localizationX;
}

int Pikeman::getLocalizationY() {
    return localizationY;
}

void Pikeman::setLocalizationX(int localizationX) {
    this->localizationX = localizationX;
}

void Pikeman::setLocalizationY(int localizationY) {
    this->localizationY = localizationY;
}

int Pikeman::getId() {
    return unitId;
}

Pikeman::~Pikeman() {}


/*

int Pikeman::getAttack(int unitAttacking) {
    return attack[unitAttacking];
}*/
