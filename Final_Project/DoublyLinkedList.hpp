/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-26-2019
** Description:  This is the header for the DoublyLinkedList class. It
                 has functions to add a node to the head, add a node to the
                 tail, delete the first node, delete the last node, display the
                 list in reverse order, print the value of the head, print the
                 value of the tail.  It also has private helper functions to
                 recursively add node to the tail and recursively print the
                 list in reverse.
*******************************************************************************/


#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"
#include "InputValidation2.hpp"

using std::cout;
using std::cin;
using std::endl;


class DoublyLinkedList {

private:

     //Node pointers to store the head and tail
     Node* head, *tail;

     //private functions to add a node to the head of the list
     Node* AddNodeToHead(string value, Node* aList);

     //private functions to recursively add a node to the tail of the list
     Node* AddNodeToTail(string value, Node* aList, Node* prevList);

     //private functions to recursively print the list in reverse
     void ReversePrint(Node* aList);

     //variables for current size and size limit
     int currentSize, sizeLimit;

     //This function removes a node from the head of the list.
     void DeleteFromHead();

     //This function removes a node from the tail of the list.
     void DeleteFromTail();

public:

     //non default Constructor
     DoublyLinkedList(int sizeLimit);

     //This function add a new node with the value to the head of the list
     void AddToHead(string value);

     //This function add a new node with the value to the tail of the list
     void AddToTail(string value);

     //This function removes a specific item from the list.
     bool RemoveSpecific(string item);  

     //This function checks if the list has a specific item
     int CheckExist(string item);

     //This function prints the list values on screen in order.
     void PrintList();

     //This function prints the list in reverse order.
     void PrintListReverse();

     //This function prints the value of the node the head is pointing to
     void PrintHeadValue();

     //This function prints the value of the node the tail is pointing to
     void PrintTailValue();

     //This function prints the current size of the list
     int CurrentSize() { return currentSize; }

     //Destructor
     ~DoublyLinkedList();

};

#endif

