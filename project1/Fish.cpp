/*
File Title: Fish.cpp
Author: John Zhen
Description: Implementation of the Fish class from the header file Fish.hpp
Date of Creation: 2/6/2020
*/

#include "Fish.hpp"

// Default Constructor initializes class variables to false
Fish::Fish()
{
    venomous_ = false;
}
/*

Constructor for the Fish class, which calls the parent class Mammal's constructor to instantiate 

@param name The string name to be assigned to the Fish
@param domestic The boolean value of whether or not the Fish is a domestic
@param predator The boolean value of whether or not the Fish is a predator

*/
Fish::Fish(std::string name, bool domestic, bool predator):Mammal(name, domestic, predator)
{
    Fish();
}

// @return true if venomous false otherwise
bool Fish::isVenomous() const
{
    return venomous_;
}

// sets the fish's venomous trait to true
void Fish::setVenomous()
{
    venomous_ = true;
}