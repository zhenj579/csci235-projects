/*
File Title: Bird.cpp
Author: John Zhen
Description: Interface of the Bird class, which is a subclass of the Mammal class
Date of Creation: 2/6/2020
*/
#ifndef BIRD_HPP
#define BIRD_HPP

#include "Mammal.hpp"

class Bird : public Mammal
{
    private:
    bool airborne_; // holds true or false whether or not the Bird is airborne or not
    bool aquatic_; // holds true or false whether or not the Bird is aquatic or not
    public:
    Bird(); // default constructor, which sets data members to false

    /*
    Constructor for Bird, which calls on the parent class to instantiate

    @param name The name to be assigned to the Bird
    @param domestic Whether or not the Bird is domestic
    @param predator Whether or not the Bird is a predator

    By default the domestic and predator trait are set to false.
    */
    Bird(std::string name, bool domestic = false, bool predator = false);

    // @return true if Bird is airborne or false if otherwise
    bool isAirborne() const;

    // @return true if Bird is aquatic or false if otherwise
    bool isAquatic() const;

    // set the airborne trait of the Bird to true
    void setAirborne();

    // set the aquatic trait of the Bird to true 
    void setAquatic();

};



#endif