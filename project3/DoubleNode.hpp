/*
File Title: DoubleNode.hpp
Author: John Zhen
Description: Node interface for doubly linked list
-Stores an item and a pointer to the previous and next node.
-Functions to get and set the next and previous nodes as well as the item within the node.
Date of Creation: 3/21/2020
*/

#ifndef DOUBLENODE_HPP
#define DOUBLENODE_HPP

template <class ItemType>
class DoubleNode
{
    private:
    DoubleNode<ItemType> *next;
    DoubleNode<ItemType> *prev;
    ItemType item;
    public:
    DoubleNode();
    /*
    Constructor to instantiate a node with given item.
    If provided with no prev or next pointer, the node's prev and next will default to nullptr
    @param item item of type ItemType to be stored
    @param prev pointer to previous node
    @param next pointer to next node 
    */
    DoubleNode(ItemType item, DoubleNode<ItemType> *prev = nullptr, DoubleNode<ItemType> *next = nullptr);
    ItemType getItem() const;
    void setNext(DoubleNode<ItemType> *next); 
    void setPrev(DoubleNode<ItemType> *prev); 
    void setItem(ItemType item); 
    DoubleNode<ItemType> *getNext() const;
    DoubleNode<ItemType> *getPrev() const;


};



#include "DoubleNode.cpp"

#endif