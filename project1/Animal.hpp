/*
File Title: Animal.hpp
Author: John Zhen
Description: Interface of the Animal class
Date of Creation: 2/6/2020
*/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
    private:
    //data members
    std::string name_; // name of animal
    bool domestic_; // whether or not animal is domestic
    bool predator_; // whether or not animal is a predator
    public:
    Animal(); // default constrcutor (sets data members to false)
    /*

    @param name name of the animal
    @param domestic = false, domestic trait of the animal automatically set to false
    @param predator = false, predator trait of the animal automatically set to false
    */
    Animal(std::string name, bool domestic = false, bool predator = false);
    std::string getName() const; // returns the respective data member 
    bool isDomestic() const;
    bool isPredator() const;
    void setName(std::string name); // sets the respective data member
    void setDomestic();
    void setPredator();
};



#endif