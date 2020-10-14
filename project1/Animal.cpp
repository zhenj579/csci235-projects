/*
File Title: Animal.cpp
Author: John Zhen
Description: Implementation of the Animal class from the header file Animal.hpp
Date of Creation: 2/6/2020
*/

#include "Animal.hpp"


/*
Default Constructor for the Animal object

Sets all data members to false
*/
Animal::Animal()
{
    predator_ = false;
    domestic_ = false;
    name_ = "";
}

/*
Constructor for the Animal object

@param name Name of the Animal
@param domestic If the animal is domestic or not
@param predator If the animal is a predator or not
*/

Animal::Animal(std::string name, bool domestic, bool predator)
{
    predator_ = predator;
    domestic_ = domestic;
    name_ = name;
}

// @return name of animal
std::string Animal::getName() const
{
    return name_;
}

// @return whether or not animal is domestic
bool Animal::isDomestic() const
{
    return domestic_;
}

// @return whether or not animal is a predator
bool Animal::isPredator() const
{
    return predator_;
}

/*
Sets the name of the Animal

@param name The name that the Animal should be set to
*/
void Animal::setName(std::string name)
{
    name_ = name;
}

// Sets the animal to be domestic
void Animal::setDomestic()
{
    domestic_ = true;
}

// Sets t he animal to be a predator
void Animal::setPredator()
{
    predator_ = true;
}




