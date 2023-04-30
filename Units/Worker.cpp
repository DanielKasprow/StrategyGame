//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include "../Headers/Units.h"

using namespace std;

Worker::Worker() : Unit("Worker", 20, 2) {
    price = 100;
    range = 1;
    buildTime = 2;
    miningGoldPerRound = 50;
    //delete [] attack;
    //int attack[8] = {35,35,35,35,35,50,35,35};
};

int Worker::getDurability() {
    return durability;
}

void Worker::setDurability(int durability) {
    this->durability = durability;
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


/*

int Worker::getAttack(int unitAttacking) {
    return attack[unitAttacking];
}*/
