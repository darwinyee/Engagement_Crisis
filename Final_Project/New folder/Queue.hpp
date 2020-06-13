/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-26-2019
** Description:  This is a header file for the Queue class. This is adapted from
                 Lab 7 to act as an inventory container for the character.
*******************************************************************************/


#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct QueueNode {

     QueueNode* next;
     QueueNode* prev;
     string val;

     QueueNode(string inval, QueueNode* inNext = nullptr, QueueNode* inPrev = nullptr) {
          val = inval;
          next = inNext;
          prev = inPrev;
     }

};

class Queue {

private:
     QueueNode* head;
     int sizeLimit;     //this is the limit of the inventory size.
     int currentSize;

public:

     //Constructor
     Queue(int sizeLimit);

     //This function checks if the queue is empty.
     bool isEmpty();

     //This function adds a new node to the back of the list 
     void addBack(string val);

     //This function returns the value of the node at the front of the queue.
     string getFront();

     //This function removes the front QueueNode of the queue and free the memory.
     void removeFront();

     //This function removes a specific item from the quene
     void removeSpecific(string item);

     //This function prints the values of each QueueNode in the queue, starting from the head
     void printQueue();

     //Destructor
     ~Queue();

};


#endif // !QUEUE_HPP
