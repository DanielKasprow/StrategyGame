//
// Created by Daniel Kasprow on 28.04.2023.
//
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
    int actionPoints;
    int localizationX;
    int localizationY;
    char ownerUnit;

    Unit(char ownerUnit, int localizationX, int localizationY) {
        Unit::unitId = lastId++;
        Unit::ownerUnit = ownerUnit;
        Unit::localizationX = localizationX;
        Unit::localizationY = localizationY;
    }
public:

    virtual int getId() = 0;

    virtual string getName() = 0;

    virtual char getOwner() = 0;

    virtual int getDurability() = 0;

    virtual void setDurability(int durability) = 0;

    virtual int getSpeed() = 0;

    virtual int getActionPoints() = 0;
    virtual void setActionPoints(int actionPoints) = 0;
    virtual void newRound() = 0;

    virtual int getLocalizationX() = 0;

    virtual int getLocalizationY() = 0;

};