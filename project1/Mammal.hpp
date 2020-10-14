/*
File Title: Mammal.hpp
Author: John Zhen
Description: Interface of the Mammal class 
Date of Creation: 2/6/2020
*/

#ifndef MAMMAL_HPP
#define MAMMAL_HPP

#include "Animal.hpp" 
#include <string>

class Mammal : public Animal
{
    private:
    //data members, which determines if a specific trait of the animal exists(true) or not(false).
    bool hair_; 
    bool airborne_; 
    bool aquatic_; 
    bool toothed_;
    bool fins_;
    bool tail_;
    int legs_;
    public:
    Mammal(); // default empty constructor
    Mammal(std::string name, bool domestic = false, bool predator = false); // constructor, which calls the parent class Animal's constructor to instantiate
    bool hasHair() const;
    bool isAirborne() const; //@return true if the trait exists or false otherwise
    bool isAquatic() const;
    bool isToothed() const;
    bool hasFins() const;
    bool hasTail() const;
    int legs() const; //@return the integer number of legs the mammal has
    void setHair();
    void setAirborne(); //sets the respective member trait to true 
    void setAquatic();
    void setToothed();
    void setFins();
    void setTail();
    /*
    Sets the integer number of legs to the mammal

    @param legs integer number of legs
    */
    void setLegs(int legs); 

};

#endif
