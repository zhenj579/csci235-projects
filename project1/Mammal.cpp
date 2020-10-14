/*
File Title: Mammal.cpp
Author: John Zhen
Description: Implementation of the Mammal class from the header Mammal.hpp
Date of Creation: 2/6/2020
*/
#include "Mammal.hpp"

// Default Constructor, which initializes all the member variable to false
Mammal::Mammal()
{
    hair_ = false;
    airborne_ = false;
    aquatic_ = false;
    toothed_ = false;
    fins_ = false;
    tail_ = false;
    legs_ = 0;
}

/*
Constructor for the Mammal class, which calls the parent class Animal's constructor to instantiate
Initializes member variables to false

@param name The string name to be assigned to the mammal
@param domestic The boolean value of whether or not the Mammal is domestic
@param predator The boolean value of whether or not the Mammal is predator
*/
Mammal::Mammal(std::string name, bool domestic, bool predator) : Animal(name,domestic,predator)
{
    hair_ = false;
    airborne_ = false;
    aquatic_ = false;
    toothed_ = false;
    fins_ = false;
    tail_ = false;
    legs_ = 0;
}

//@return true if the mammal has hair or false otherwise
bool Mammal::hasHair() const
{
    return hair_;
}

//@return true if the mammal is airborne or false otherwise
bool Mammal::isAirborne() const
{
    return airborne_;
}

//@return true if the mammal is aquatic or false otherwise
bool Mammal::isAquatic() const
{
    return aquatic_;
}

//@return true if the mammal is toothed or false otherwise
bool Mammal::isToothed() const
{
    return toothed_;
}

//@return true if the mammal has fins or false otherwise
bool Mammal::hasFins() const
{
    return fins_;
}

//@return true if the mammal has a tail or false otherwise
bool Mammal::hasTail() const
{
    return tail_;
}

//@return the integer number of legs the mammal has 
int Mammal::legs() const
{
    return legs_;
} 

//Sets the mammal's trait of having hair to true
void Mammal::setHair()
{
    hair_ = true;
}

//Sets the mammal's trait of being airborne to true
void Mammal::setAirborne()
{
    airborne_ = true;
}

//Sets the mammal's trait of being aquatic to true
void Mammal::setAquatic()
{
    aquatic_ = true;
}

//Sets the mammal's trait of having teeth to true
void Mammal::setToothed()
{
    toothed_ = true;
}

//Sets the mammal's trait of having fins to true
void Mammal::setFins()
{
    fins_ = true;
}

//Sets the mammal's trait of having a tail to true
void Mammal::setTail()
{
    tail_ = true;
}

/*
Sets the number of legs the mammal has

@param legs The integer number of legs the mammal has
*/
void Mammal::setLegs(int legs)
{
    legs_ = legs;
}