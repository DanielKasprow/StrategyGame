//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Ram::Ram() : Unit("Ram", 90, 2) {
    price = 500;
    range = 1;
    buildTime = 4;
    //delete [] attack;
    //int attack[8] = {35,35,35,35,35,50,35,35};
};

int Ram::getDurability() {
    return durability;
}

void Ram::setDurability(int durability) {
    this->durability = durability;
}

int Ram::getSpeed() {
    return speed;
}

int Ram::getPrice() {
    return price;
}

int Ram::getRange() {
    return range;
}

int Ram::getBuildTime() {
    return buildTime;
}

int Ram::getLocalizationX() {
    return localizationX;
}

int Ram::getLocalizationY() {
    return localizationY;
}

void Ram::setLocalizationX(int localizationX) {
    this->localizationX = localizationX;
}

void Ram::setLocalizationY(int localizationY) {
    this->localizationY = localizationY;
}

int Ram::getId() {
    return unitId;
}

Ram::~Ram() {}


/*

int Ram::getAttack(int unitAttacking) {
    return attack[unitAttacking];
}*/
