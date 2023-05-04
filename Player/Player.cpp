//
// Created by trane on 30.04.2023.
//

#include "../Headers/Player.h"

Player::Player() {
    this-> gold = 2000;
}

Player::~Player() {}

int Player::getGold() {
    return gold;
}

void Player::setGold(int gold) {
    this->gold = gold;

}


