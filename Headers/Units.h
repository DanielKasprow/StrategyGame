//
// Created by Daniel Kasprow on 28.04.2023.
//

#ifndef UNTITLED_UNITS_H
#define UNTITLED_UNITS_H

#endif //UNTITLED_UNITS_H
#include <iostream>
#include "Unit.cpp"
#include "../Interfaces/UnitsFightingActions.cpp"


enum UnitType { Knight, Swordsman, Archer, Pikeman, Ram, Catapult, Worker };

class Base : public Unit{
    int productionTime = 0;
    char productionType = 0;
public:
    Base(int localizationY, int localizationX, char ownerUnit);
    virtual ~Base();

    int getId() override;
    int getDurability() override;
    void setDurability(int durability) override;
    int getSpeed() override;

    int getLocalizationX() override;
    int getLocalizationY() override;

    void setProductionType(char unitType);
    char getProductionType() const;
    int getProductionTime() const;

    void setProductionTime(int productionRemaning);

    char getOwner() override;

    int getActionPoints() override;
    void setActionPoints(int ActionPoints) override;
    void newRound() override;

    string getName() override;
};

class FightingUnit : public Unit, UnitsFightingActions{
public:

    FightingUnit(int localizationY, int localizationX, char ownerUnit, UnitType unitType);

    virtual ~FightingUnit();

    int getId() override;
    int getDurability() override;
    void setDurability(int durability) override;
    int getSpeed() override;

    int getRange() override;

    int getLocalizationX() override;
    int getLocalizationY() override;

    void setLocalization(int localizationX, int localizationY) override;

    char getOwner() override;

    int getActionPoints() override;
    void setActionPoints(int ActionPoints) override;
    void newRound() override;

    bool getAlreadyAttacking() override;

    void setAlreadyAttacking() override;

    int getAttack(char unitAttacking) override;

    string getName() override;
};

