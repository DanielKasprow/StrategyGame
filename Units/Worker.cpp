//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Worker::Worker(char ownerUnit) : Unit("W", 20, 2, ownerUnit) {
    price = price;
    range = range;
    buildTime = buildTime;
    miningGoldPerRound = miningGoldPerRound;
};

int Worker::getDurability() {
    return durability;
}

void Worker::setDurability(int durability) {
    Worker::durability = durability;
}

int Worker::getSpeed() {
    return speed;
}

int Worker::getPrice() {
    return price;
}

int Worker::getRange() {
    return range;
}

int Worker::getBuildTime() {
    return buildTime;
}

int Worker::getLocalizationX() {
    return localizationX;
}

int Worker::getLocalizationY() {
    return localizationY;
}

void Worker::setLocalizationX(int localizationX) {
    this->localizationX = localizationX;
}

void Worker::setLocalizationY(int localizationY) {
    this->localizationY = localizationY;
}

int Worker::getId() {
    return unitId;
}

Worker::~Worker() {}

int Worker::getMiningGoldPerRound() {
    return miningGoldPerRound;
}

char Worker::getOwner() {
    return ownerUnit;
}



