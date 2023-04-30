//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>


//Interface for fighting units like Knight
class UnitsFightingActions {
protected:
    int price;
    int range;
    int buildTime;
    //int *attack;


    virtual int getPrice() = 0;

    virtual int getRange() = 0;

    virtual int getBuildTime() = 0;

    virtual void setLocalizationX(int localizationX) = 0;

    virtual void setLocalizationY(int localizationY) = 0;

    //virtual int getAttack(int unitAttacking);

};