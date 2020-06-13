/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-04-2019
** Description:  This is the header for the Node class.  It contains two node
                 pointers and an integer variable to store the value in the node.
                 It has a constructor to set up the node.
*******************************************************************************/


#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>

using std::string;

class Node {

private:
     Node* next, *prev;
     string val;

public:

     //constructor
     Node(string val, Node* next = nullptr, Node* prev = nullptr);

     /*Getter/setter functions*/

     //This function gets the integer value in the node.
     string GetValue() { return val; }
     //This function sets the integer value in the node.
     void SetValue(string val) { this->val = val; }

     //This function returns the next node pointer
     Node* NextNode() { return next; }
     //This function sets the next node pointer
     void SetNextNode(Node* next) { this->next = next; }

     //This function returns the previous node pointer
     Node* PrevNode() { return prev; }
     //This function sets the prev node pointer
     void SetPrevNode(Node* prev) { this->prev = prev; }

};
#endif
