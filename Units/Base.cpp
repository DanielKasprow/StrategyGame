//
// Created by Daniel Kasprow on 28.04.2023.
//
#include "../Headers/Units.h"

Base::Base(int localizationY, int localizationX, char ownerUnit) : Unit(ownerUnit, localizationY, localizationX) {
    Base::name = "B";
    Base::durability = 200;
    Base::speed = Base::actionPoints = 0;
    Base::productionType = '0';
}

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

int Base::getProductionTime() const {
    return productionTime;
}

void Base::setProductionTime(int productionTime) {
    Base::productionTime = productionTime;
}

char Base::getOwner() {
    return ownerUnit;
}

void Base::setProductionType(char unitType) {
    Base::productionType = unitType;
    switch (unitType) {
        case 'K':
            Base::productionTime = 5;
            break;
        case 'S':
            Base::productionTime = 3;
            break;
        case 'A':
            Base::productionTime = 3;
            break;
        case 'P':
            Base::productionTime = 3;
            break;
        case 'R':
            Base::productionTime = 4;
            break;
        case 'C':
            Base::productionTime = 6;
            break;
        case 'W':
            Base::productionTime = 2;
            break;
    }
}

char Base::getProductionType() const {
    return productionType;
}

int Base::getActionPoints() {
    return actionPoints;
}


void Base::setActionPoints(int actionPoints) {
    Base::actionPoints = actionPoints;
}

void Base::newRound() {

}

string Base::getName() {
    return name;
}


Base::~Base() = default;
