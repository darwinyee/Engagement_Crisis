/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-04-2019
** Description:  This is the function code for the Node class.  It contains two node
                 pointers and an integer variable to store the value in the node.
                 It has a constructor to set up the node.
*******************************************************************************/

#include "Node.hpp"


Node::Node(string val, Node* next, Node* prev) {

     //set up the member variables with the given parameters
     this->val = val;

     this->next = next;

     this->prev = prev;

}