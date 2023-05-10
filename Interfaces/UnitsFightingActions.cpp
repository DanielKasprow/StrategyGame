//
// Created by Daniel Kasprow on 28.04.2023.
//


enum UnitType { Knight, Swordsman, Archer, Pikeman, Ram, Catapult, Worker };
//Interface for fighting units like Knight
class UnitsFightingActions {
protected:
    int range{};
    bool alreadyAttacking = false;
    int *attack;
    UnitType unitType;
    virtual int getRange() = 0;

    virtual void setLocalization(int localizationY, int localizationX) = 0;

    virtual bool getAlreadyAttacking() = 0;

    virtual void setAlreadyAttacking() = 0;

    virtual int getAttack(char unitAttacking) = 0;

};