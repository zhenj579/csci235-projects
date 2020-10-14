/*
File Title: Fish.hpp
Author: John Zhen
Description: Interface of the Fish class
Date of Creation: 2/6/2020
*/

#ifndef FISH_HPP
#define FISH_HPP

#include "Mammal.hpp"

class Fish: public Mammal
{
    private:
    bool venomous_; // determines if the fish is venomous or not
    public:
    Fish(); // default constructor, which sets data members to false 
    /*
    Constructor
    
    @param name The string name to be assigned to the Fish
    @param domestic Whether or not the animal is domestic or not, set to false by default
    @param predator Whether or not the animal is a predator or not, set to false by default
    */
    Fish(std::string name, bool domestic = false, bool predator = false);
    bool isVenomous() const; //@returns if the fish is venomous or not
    void setVenomous(); // Sets the fish's venomous trait to true

};


#endif