//
// Created by Daniel Kasprow on 28.04.2023.
//
#include <iostream>
#include <string>

using namespace std;

//enum Jednostka { Rycerz, Czolg };
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

    Unit(string name, int durability, int speed) {
        this->name = name;
        this->durability = durability;
        this->speed = speed;
        this->unitId = lastId++;
    }

    virtual int getId() = 0;

    virtual int getDurability() = 0;

    virtual void setDurability(int durability) = 0;

    virtual int getSpeed() = 0;

    virtual int getLocalizationX() = 0;

    virtual int getLocalizationY() = 0;

    //virtual string enumFunction(Jednostka name) = 0;


};