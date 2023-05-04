//
// Created by Daniel Kasprow on 28.04.2023.
//
#include "../Headers/Units.h"

Base::Base(int localizationX, int localizationY, char ownerUnit) : Unit("B", 200, 0, ownerUnit) {
    Base::localizationX = localizationX;
    Base::localizationY = localizationY;

};

int Base::getDurability() {
    return durability;
}

void Base::setDurability(int durability) {
    Base::durability = durability;
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

int Base::getProductionTime() {
    return productionTime;
}

void Base::setProductionTime(int productionTime) {
    Base::productionTime = productionTime;
}

char Base::getOwner() {
    return ownerUnit;
}


