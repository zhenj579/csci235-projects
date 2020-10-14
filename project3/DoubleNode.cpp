/*
File Title: DoubleNode.cpp
Author: John Zhen
Description: Node implementation for doubly linked list.
Ability to hold information
Date of Creation: 3/21/2020
*/

#include "DoubleNode.hpp"

template <class ItemType>
DoubleNode<ItemType>::DoubleNode() : next(nullptr), prev(nullptr) { } // default constructor

/*

@param item the item of ItemType to insert
@param prev a Double Node pointer of ItemType to set the previous node to
@param next a Double Node pointer of ItemType to set the next node to
*/
template <class ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType item, DoubleNode<ItemType> *prev, DoubleNode<ItemType> *next) : item(item), prev(prev), next(next) { }

//@return ItemType the item in the node
template <class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return this->item;
}

//@param next a double node pointer of ItemType to set the next to
template <class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *next)
{
    this->next = next;
}

//@param prev a double node pointer of ItemType to set the previous to
template <class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode<ItemType> *prev)
{
    this->prev = prev;
}

//@param item item of ItemType to set the node to
template <class ItemType>
void DoubleNode<ItemType>::setItem(ItemType item)
{
    this->item = item;
}

//@return DoubleNode<ItemType> * a pointer to the next node
template <class ItemType>
DoubleNode<ItemType> *DoubleNode<ItemType>::getNext() const
{
    return next;
}

//@return DoubleNode<ItemType> * a pointer to the previous node
template <class ItemType>
DoubleNode<ItemType> *DoubleNode<ItemType>::getPrev() const
{
    return prev; 
}









