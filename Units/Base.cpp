//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Base::Base() : Unit("Base", 200, 0) {

};

int Base::getDurability() {
    return durability;
}

void Base::setDurability(int durability) {
    this->durability = durability;
}

int Base::getSpeed() {
    return speed;
}

int Base::getLocalizationX() {
    return localizationX;
}

int Base::getLocalizationY() {
    return localizationY;
}

int Base::getId() {
    return unitId;
}

Base::~Base() {}
