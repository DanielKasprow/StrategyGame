//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include <string>

using namespace std;


static int lastId = 1;
//Abstraction class for units
class Unit {
protected:

    int unitId;
    string name;
    int durability;
    int speed;
    int localizationX;
    int localizationY;
    char ownerUnit;

    Unit(string name, int durability, int speed, int ownerUnit) {
        Unit::name = name;
        Unit::durability = durability;
        Unit::speed = speed;
        Unit::unitId = lastId++;
        Unit::ownerUnit = ownerUnit;
    }
public:

    virtual int getId() = 0;

    virtual char getOwner() = 0;

    virtual int getDurability() = 0;

    virtual void setDurability(int durability) = 0;

    virtual int getSpeed() = 0;

    virtual int getLocalizationX() = 0;

    virtual int getLocalizationY() = 0;

};