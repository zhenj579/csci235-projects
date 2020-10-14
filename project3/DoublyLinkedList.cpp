/*
File Title: DoublyLinkedList.cpp
Author: John Zhen
Description: DoublyLinkedList implementation
Keeps track of continuous nodes which store items
Ability to remove, display, interleave, and insert items into the list.
Date of Creation: 3/21/2020
*/

#include "DoublyLinkedList.hpp"

/*
default constructor, sets member variables to nullptr if its type is a pointer and size to 0
*/
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : head(nullptr), size(0) { }

/*
copy constructor, takes in a list reference and copies every item in the list.

@param list a doubly linked list reference to copy from.
*/
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &list) : head(nullptr), size(0)
{
    DoubleNode<ItemType> *tail = list.getAtPos(1); //get the pointer to the first element of the list
    for(int i = 1; i <= list.getSize(); i++, tail = tail->getPrev())
    {
        insert(tail->getItem(), i); // iterate through the list and insert each node into the list
    }
}

/*
inserts an item into the list at the position specified

@param item an item of ItemType const reference to insert into the list
@param position an integer within the range of 1 <= position <= size + 1
@return bool a boolean of whether or not the item was successfully inserted
*/
template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
    bool ableToInsert = (position >= 1) && (position <= size + 1);
    if(ableToInsert)
    {
        DoubleNode<ItemType> *entry = new DoubleNode<ItemType>(item);
        DoubleNode<ItemType> *nodeAtPos = getAtPos(position); // get the node at the position
        if(head == nullptr) // if list is empty create a node to insert the item into
        {
            head = new DoubleNode<ItemType>(item, nullptr, nullptr);
        }
        else if(position == size + 1) // if position is one past the head create a new node and set it as the new head
        { 
            entry->setNext(head); // push the head forward one position
            head->setPrev(entry); // set the head's previous to the new entry
            head = entry; // set the new head to the entry
        }
        else if(position == 1) // if position is at the first element, create a new node and push the first element forward
        {
            entry->setPrev(nodeAtPos); // set the entry's previous to the previous first element
            nodeAtPos->setNext(entry); // set the previous first element to point the to the entry
        }
        else // otherwise insert the node and fix the connection of the nodes
        {
            nodeAtPos = getAtPos(position - 1); // get the node in front of the position to insert
            nodeAtPos->getPrev()->setNext(entry); // fix the prevs and next
            entry->setPrev(nodeAtPos->getPrev());
            nodeAtPos->setPrev(entry); // insert the node
            entry->setNext(nodeAtPos); 
        }
        size++; 
    }
    return ableToInsert; 
}
/*
returns the node at the specified position, where 1 <= pos <= size

@param pos the integer position to retrieve the node from
@return DoubleNode<ItemType> * a pointer to the node at the specified pos
*/
template <class ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
    if(pos > size) // if the position is invalid return
    {
        return nullptr;
    }
    DoubleNode<ItemType> *node = head;
    while(node->getNext() != nullptr)
    {
        node = node->getNext(); // iterate to the beginning of the list
    }
    for(int i = 1; i < pos; i++)
    {
        node = node->getPrev(); // iterate forward until the specified pos
    }
    return node;

}
/*
displays the current state of the list in the order of the elements inserts
from first node inserted -> last node inserted
*/
template <class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType> *copy = head;
    while(copy->getNext() != nullptr)
    { 
        copy = copy->getNext(); // iterate to the first element of the list
    }
    while(copy->getPrev() != nullptr)
    {
        std::cout<<copy->getItem()<<" "; // iterate back while printing the value of the elements
        copy = copy->getPrev();
    }
    std::cout<<copy->getItem()<<std::endl;
}

//@return int returns the size of the list
template <class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    return size;
}

//@return DoubleNode<ItemType> * returns a pointer to the head of the list
template <class ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getHeadPtr() const
{
    return head;
}

/*
displays the current state of the list backwards
last node inserted -> first node inserted
*/
template <class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    DoubleNode<ItemType> *copy = head;
    while(copy->getNext() != nullptr) // iterate forward while displaying the items
    {
        std::cout<<copy->getItem()<<" ";
        copy = copy->getNext();
    }
    std::cout<<copy->getItem()<<std::endl;
}

//@return bool true if the list size is 0 or false otherwise
template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return size == 0;
}

/*
removes the node at the specific position

@param pos an integer position to remove the node at
@return bool whether or not the node was successfully removed
*/
template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &pos)
{
    bool ableToRemove = (pos >= 0) && (pos <= size) && (!isEmpty());
    if(ableToRemove)
    {
        if(size == 1) // if the list has only one element remove it
        {
            delete head;
            head = nullptr;
        }
        else if(pos == size) // if the position is the head of the list
        {
            DoubleNode<ItemType> *copyOfHeadNext = head->getNext();
            delete head; //move the head up and then delete the previous head
            head = copyOfHeadNext;
            head->setPrev(nullptr);
        }
        else if(pos == 1) // if the position is the end of the list
        {
            DoubleNode<ItemType> *firstNodePrev = getAtPos(pos+1); // get the node before the first
            delete firstNodePrev->getNext(); // delete the first element
            firstNodePrev->setNext(nullptr); // set the node before the first element to point to nullptr
        }
        else
        {
            DoubleNode<ItemType> *nodeAtPos = getAtPos(pos); //get the node at the position
            nodeAtPos->getNext()->setPrev(nodeAtPos->getPrev()); // fix the prevs and nexts to fill the empty gap
            nodeAtPos->getPrev()->setNext(nodeAtPos->getNext());
            delete nodeAtPos; // delete the node at the position
        }
        size--;
    }
    return ableToRemove;
}

/*
clear the list
*/
template <class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    while(!isEmpty()) // while the list is not empty delete the first element until it is empty
    {
        remove(1);
    }
}

/*
edit and interleave the current list with the list specified
for exmaple: let l1 = {1,2,3} and l2 = {4,5,6}
then the interleaved list will be {1,4,2,5,3,6}

@param a_list the list to interleave with
@return DoublyLinkedList<ItemType> the current list interleaved
*/

template <class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list)
{
    int insertionIndex = 2; // the position to insert the node from the other list
    int count = 1; // the index for keeping track of traversing the second list
    for(insertionIndex, count; count <= a_list.size; count++, insertionIndex+=2) // iterate through the second list 
    {
        if(insertionIndex > size + 1)
        {
            insertionIndex--; // if there are no more elements to interleave then just insert at the end of the current list.
        }
        insert(a_list.getAtPos(count)->getItem(), insertionIndex); // insert the item every other index
    }
    return *this;
}

template <class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear(); //destructor, clear the list when list is destroyed.
}