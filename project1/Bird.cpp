/*
File Title: Bird.cpp
Author: John Zhen
Description: Implementation of the Bird class from the header file Bird.hpp
Date of Creation: 2/6/2020
*/

#include "Bird.hpp"

//Default Constructor, initializes class variables to false
Bird::Bird()
{
    airborne_ = false;
    aquatic_ = false;
}

/*
Constructor for the Bird class, which calls the parent class constructor to instantiate
and initializes class variables to false

@param name Name to be assigned to the Bird
@param domestic If the Bird is domestic or not
@param predator If the Bird is a predator or not
*/
Bird::Bird(std::string name, bool domestic, bool predator):Mammal(name,domestic,predator)
{
    Bird();
}   

// @return true if the Bird is airborne or false if the Bird is not airborne
bool Bird::isAirborne() const
{
    return airborne_;
}

// @return true if the Bird is aquatic or false if the Bird is not aquatic
bool Bird::isAquatic() const
{
    return aquatic_;
}

// sets the Bird's airborne trait to true
void Bird::setAirborne()
{
    airborne_ = true;
}

// sets the Bird's aquatic trait to true
void Bird::setAquatic()
{
    aquatic_ = true;
}


