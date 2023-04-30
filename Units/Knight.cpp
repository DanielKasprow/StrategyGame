//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Knight::Knight() : Unit("Knight", 70, 5) {
    price = 400;
    range = 1;
    buildTime = 5;
    //delete [] attack;
    //int attack[8] = {35,35,35,35,35,50,35,35};
};

//long Knight::getId() {
//return id;
//}

int Knight::getDurability() {
    return durability;
}

void Knight::setDurability(int durability) {
    this->durability = durability;
}

int Knight::getSpeed() {
    return speed;
}

int Knight::getPrice() {
    return price;
}

int Knight::getRange() {
    return range;
}

int Knight::getBuildTime() {
    return buildTime;
}

int Knight::getLocalizationX() {
    return localizationX;
}

int Knight::getLocalizationY() {
    return localizationY;
}

void Knight::setLocalizationX(int localizationX) {
    this->localizationX = localizationX;
}

void Knight::setLocalizationY(int localizationY) {
    this->localizationY = localizationY;
}

int Knight::getId() {
    return unitId;
}

Knight::~Knight() {}


/*

int Knight::getAttack(int unitAttacking) {
    return attack[unitAttacking];
}*/
