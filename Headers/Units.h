//
// Created by Daniel Kasprow on 28.04.2023.
//

#ifndef UNTITLED_UNITS_H
#define UNTITLED_UNITS_H

#endif //UNTITLED_UNITS_H
#include <iostream>
#include "Unit.cpp"
#include "../Interfaces/UnitsFightingActions.cpp"
#include "../Interfaces/WorkerUnitActions.cpp"

enum UnitType { Knight, Swordsman, Archer, Pikeman, Ram, Catapult };

class Base : public Unit{
    int productionTime = 0;

public:
    Base(int localizationY, int localizationX, char ownerUnit);
    virtual ~Base();

    int getId() override;
    int getDurability() override;
    void setDurability(int durability) override;
    int getSpeed() override;

    int getLocalizationX() override;
    int getLocalizationY() override;

    int getProductionTime();

    void setProductionTime(int productionRemaning);

    char getOwner() override;
};

class Worker : public Unit, UnitsFightingActions, WorkerUnitActions{
public:

    Worker();

    Worker(char ownerUnit);

    virtual ~Worker();

    int getId() override;
    int getDurability() override;
    void setDurability(int durability) override;
    int getSpeed() override;

    int getPrice() override;
    int getRange() override;
    int getBuildTime() override;

    int getLocalizationX() override;
    int getLocalizationY() override;

    void setLocalizationX(int localizationX) override;
    void setLocalizationY(int localizationY) override;

    int getMiningGoldPerRound() override;

    char getOwner() override;

};

class FightingUnit : public Unit, UnitsFightingActions{
public:

    FightingUnit(char ownerUnit, UnitType unitType);

    virtual ~FightingUnit();

    int getId() override;
    int getDurability() override;
    void setDurability(int durability) override;
    int getSpeed() override;

    int getPrice() override;
    int getRange() override;
    int getBuildTime() override;

    int getLocalizationX() override;
    int getLocalizationY() override;

    void setLocalizationX(int localizationX) override;
    void setLocalizationY(int localizationY) override;

    char getOwner() override;

};

