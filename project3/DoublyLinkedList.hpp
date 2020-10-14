/*
File Title: DoublyLinkedList.hpp
Author: John Zhen
Description: DoublyLinkedList interface 
Keeps track of continuous nodes which store items
Ability to remove, display, interleave, and insert items into the list.
Date of Creation: 3/21/2020
*/
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "DoubleNode.hpp"

template <class ItemType>
class DoublyLinkedList
{
    int size; // the size of the list
    DoubleNode<ItemType> *head;  // pointer to the head of the list
    public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &list); // copy constructor
    ~DoublyLinkedList();
    bool insert(const ItemType &item, const int &position); // insert an element at the position specified
    bool remove(const int& position);
    int getSize() const;
    DoubleNode<ItemType> *getHeadPtr() const;
    DoubleNode<ItemType> *getAtPos(const int &pos) const;
    bool isEmpty() const;
    void clear();
    void display() const;
    void displayBackwards() const;
    DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list);

};


#include "DoublyLinkedList.cpp"

#endif