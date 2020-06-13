/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-26-2019
** Description:  This is the function codes for the Queue class. This is adapted from
                 Lab 7 to act as an inventory container for the character.
*******************************************************************************/

#include "Queue.hpp"

//Constructor
Queue::Queue(int sizeLimit) {

     head = nullptr;
     this->sizeLimit = sizeLimit;
     currentSize = 0;

}



//This function checks if the queue is empty.
bool Queue::isEmpty() {

     if (head == nullptr)
          return true;
     return false;

}



//This function adds a new node to the back of the list 
void Queue::addBack(string val) {

     if (currentSize < sizeLimit) {
          if (isEmpty()) {

               head = new QueueNode(val);
               head->next = head;
               head->prev = head;

          }
          else {

               //new node that points to head's prev and head
               QueueNode* temp = new QueueNode(val, head, head->prev);

               //adjust the head's prev node next pointer
               head->prev->next = temp;

               //adjust the head's prev pointer to point to temp
               head->prev = temp;

          }
     }
     else {



     }

}



//This function returns the value of the node at the front of the queue.
string Queue::getFront() {

     return head->val;

}



//This function removes the front QueueNode of the queue and free the memory.
void Queue::removeFront() {

     if (!isEmpty()) {

          if (head->next == head) {    //if the queue has only one item
               delete head;
               head = nullptr;
          }
          else {
               //The queue has two or more items
               QueueNode* temp = head;        
               head->prev->next = head->next;      //Set the last node next pointer points to the node followed by the first
               head->next->prev = head->prev;      //Set the second node prev pointer points to the last node
               head = head->next;                  //point the head to the second node
               delete temp;                        //delete the original head

          }
     }
     else {

          cout << endl << "The queue is empty!" << endl;

     }

}



//This function removes a specific item from the quene
void Queue::removeSpecific(string item) {

     if (!isEmpty()) {

          if (head->val == item)
               removeFront();
          else {

               QueueNode* temp = head->next;
               while(temp != NULL)

          }

     }

}



//This function prints the values of each QueueNode in the queue, starting from the head
void Queue::printQueue() {

     if (isEmpty()) {
          
          cout << endl << "The queue is empty!" << endl;

     }
     else {
          //Print the message first
          cout << endl << "The queue is: ";

          //go through the list starting from the head
          cout << head->val;

          QueueNode* temp = head->next;
          while (temp != head) {

               cout << ", " << temp->val;
               temp = temp->next;

          }

     }

}

//Destructor
Queue::~Queue() {

     if (!isEmpty()) {

          QueueNode* nextNode = head->next;
          delete head;

          //loop over the list until no next node
          while (nextNode != head) {

               //set the current nextNode to a node named garbage
               QueueNode* garbage = nextNode;

               //set nextNode to the next node nextNode points to
               nextNode = nextNode->next;

               //free the memory pointed to by garbage
               delete garbage;

          }

     }


}