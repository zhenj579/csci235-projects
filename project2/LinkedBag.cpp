//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */
/*
File Title: LinkedBag.cpp
Student: John Zhen
Description: LinkedBag.h implementation
*/
#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>




template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount)
{
   if(entryCount == 0) // if trying to copy an empty array then return an empty list
   {
      return;
   }
   headPtr = new Node<ItemType>(entries[0], nullptr); // set the first element to be the head
   itemCount = 1;
   for(int i = 1; i < entryCount; i++)
   {
      add(entries[i]); // add the rest of the entries from the array
   }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const 
{
   //method to iteratively get size of list
   int size = 0; 
   Node<ItemType> *last = headPtr; // copy of the headPtr, so we can traverse the list without losing elements
   while(last != nullptr) 
   {
      size++; // traverse the list until the last element incrementing size every iteration
      last = last->getNext();
   }
	return size;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(nullptr);  // New node points to nullptr ( end of chain points to nullptr)
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code
   if(headPtr == nullptr) // if bag is empty then set head to the entry
   { 
      headPtr = nextNodePtr;
   }
   else
   {
      Node<ItemType> *last = headPtr; // Node to traverse until the end of the chain
      while(last->getNext() != nullptr)
      {
         last = last->getNext(); // Traverse the chain 
      }
      last->setNext(nextNodePtr); // set the previous last node of the list to point to the entry
   }
   itemCount++; //increment size to keep track
   
   return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

template<class ItemType>
void LinkedBag<ItemType>::deleteSecondNode()
{
   if(headPtr == nullptr || itemCount <= 1) // if there is no second node or list is empty just return
   {
      return;
   }
   else
   {
      delete headPtr->getNext(); // return memory of 2nd node to the system
      headPtr->setNext(headPtr->getNext()->getNext()); // set the headptr to point to the 3rd node
   }
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive()
{
   //method to recursively get the size of list
   LinkedBag<ItemType> copy(*this); // create a copy of the list
   if(copy.isEmpty()) // if empty return 0
   {
      return 0;
   }
   else
   {
      copy.remove(copy.headPtr->getItem()); // remove one element one by one to traverse list
      return 1 + copy.getCurrentSizeRecursive(); //recursively count the number of elements until empty
   }

}

template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom()
{
   //method to remove a random element in the list
   srand(time(NULL)); // set the seed for the random number generator
   ItemType item; // variable to hold item
   Node<ItemType> *last = headPtr; // copy pointer to head to traverse list
   int index = rand() % itemCount; // generate the random number 
   for(int i = 0; i < index; i++)
   {
      last = last->getNext(); // traverse the list until current item
   }
   item = last->getItem(); //get the item
   remove(item); // remove it and return memory to system
   return item;
}
