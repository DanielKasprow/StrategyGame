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

using namespace std;



class Base : public Unit{
public:
    Base();
    virtual ~Base();

    int getId() override;
    int getDurability() override;
    void setDurability(int durability) override;
    int getSpeed() override;

    int getLocalizationX() override;
    int getLocalizationY() override;

};

class Worker : public Unit, UnitsFightingActions, WorkerUnitActions{
public:
    Worker();
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

};

class Knight : public Unit, UnitsFightingActions{
public:
    Knight();
    virtual ~Knight();

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

};

class Swordsman : public Unit, UnitsFightingActions{
public:
    Swordsman();
    virtual ~Swordsman();

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

};

class Archer : public Unit, UnitsFightingActions{
public:
    Archer();
    virtual ~Archer();

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

};

class Pikeman : public Unit, UnitsFightingActions{
public:
    Pikeman();
    virtual ~Pikeman();

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

};

class Ram : public Unit, UnitsFightingActions{
public:
    Ram();
    virtual ~Ram();

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

};

class Catapult : public Unit, UnitsFightingActions{
public:
    Catapult();
    virtual ~Catapult();

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

};

class Team {

};
