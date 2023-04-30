//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Catapult::Catapult() : Unit("Catapult", 50, 2) {
    price = 800;
    range = 7;
    buildTime = 8;
    //delete [] attack;
    //int attack[8] = {35,35,35,35,35,50,35,35};
};

int Catapult::getDurability() {
    return durability;
}

void Catapult::setDurability(int durability) {
    this->durability = durability;
}

int Catapult::getSpeed() {
    return speed;
}

int Catapult::getPrice() {
    return price;
}

int Catapult::getRange() {
    return range;
}

int Catapult::getBuildTime() {
    return buildTime;
}

int Catapult::getLocalizationX() {
    return localizationX;
}

int Catapult::getLocalizationY() {
    return localizationY;
}

void Catapult::setLocalizationX(int localizationX) {
    this->localizationX = localizationX;
}

void Catapult::setLocalizationY(int localizationY) {
    this->localizationY = localizationY;
}

int Catapult::getId() {
    return unitId;
}

Catapult::~Catapult() {}


/*

int Catapult::getAttack(int unitAttacking) {
    return attack[unitAttacking];
}*/
