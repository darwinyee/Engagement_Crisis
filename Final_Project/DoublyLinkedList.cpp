/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-26-2019
** Description:  This is the function codes for the DoublyLinkedList class. It 
                 has functions to add a node to the head, add a node to the 
                 tail, delete the first node, delete the last node, display the
                 list in reverse order, print the value of the head, print the 
                 value of the tail.  It also has private helper functions to
                 recursively add node to the tail and recursively print the 
                 list in reverse.
*******************************************************************************/

#include "DoublyLinkedList.hpp"



//private functions to add a node to the head of the list
Node* DoublyLinkedList::AddNodeToHead(string value, Node* aList) {

     Node* temp;

     if (aList == nullptr) {
          temp = new Node(value);
          tail = temp;
     }
     else {
          temp = new Node(value, aList);
          aList->SetPrevNode(temp);
     }

     //add one to the current size
     currentSize++;

     return temp;

}



//private functions to recursively add a node to the tail of the list
Node* DoublyLinkedList::AddNodeToTail(string value, Node* aList, Node* prevList) {

     if (aList == nullptr) {
          Node* temp = new Node(value,nullptr,prevList);
          tail = temp;

          //add one to the current size
          currentSize++;

          return temp;
     }
     else {

          //recursively calling AddNodeToTail
          aList->SetNextNode(AddNodeToTail(value, aList->NextNode(), aList));
          return aList;

     }

}



//This function removes a node from the head of the list.
void DoublyLinkedList::DeleteFromHead() {

     //Warn the user if the list is empty
     if (head == nullptr)
          cout << "The list contains no elements!";
     else {

          //store the value of the first node
          string firstNodeVal = head->GetValue();

          //create a temporary pointer and point to the next node
          Node* temp = head->NextNode();

          //Delete the head
          delete head;

          //set the head to the temporary pointer
          head = temp;

          //set the first node previous pointer to nullptr if head is not null
          if(head)
               head->SetPrevNode(nullptr);

          //set tail to null if head is null
          if (head == nullptr)
               tail = nullptr;

          cout << firstNodeVal << " has been removed successfully!" << endl;

     }

}



//This function removes a node from the tail of the list.
void DoublyLinkedList::DeleteFromTail() {

     //Warn the user if the list is empty
     if (head == nullptr)
          cout << "The list contains no elements!";
     else {

          //if head == tail, this means this is the last element and head should set to null
          if (head == tail)
               head = nullptr;

          //store the value of the first node
          string lastNodeVal = tail->GetValue();

          //Create a temporary pointer and point to the node before the tail node
          Node* temp = tail->PrevNode();

          //delete the tail
          delete tail;

          //set the tail to the temporary pointer
          tail = temp;

          //set the next pointer on the new tail to nullptr
          if(tail)
               tail->SetNextNode(nullptr);

          cout << lastNodeVal << " has been removed successfully!" << endl;

     }

}



//This function removes a specific item from the list.
bool DoublyLinkedList::RemoveSpecific(string item) {

     bool removeSuccess = false;
     
     if (head != nullptr) {

          //Check the first node
          if (head->GetValue() == item) {
               DeleteFromHead();
               removeSuccess = true;
          }
          else {
               Node* nextNode = head->NextNode();
               while (nextNode && !removeSuccess) {

                    if (nextNode->GetValue() == item) {
                         //if it is the last node, call DeleteFromTail
                         if (nextNode->NextNode() == nullptr) {
                              DeleteFromTail();
                              removeSuccess = true;
                         }
                         else {

                              Node* temp = nextNode;
                              nextNode->PrevNode()->SetNextNode(nextNode->NextNode());
                              nextNode->NextNode()->SetPrevNode(nextNode->PrevNode());
                              delete temp;
                              removeSuccess = true;
                         }
                    }
                    else {
                         nextNode = nextNode->NextNode();
                    }
               }

          }

          if (!removeSuccess) {
               if (item != "none")
                    cout << "The item " + item + " was not found in the list! " << endl;
          }
          else {
               currentSize--;
          }
     }
     else
          cout << "The list has no item!" << endl;

     return removeSuccess;
}



//This function returns the number of times a specific item has been found.
int DoublyLinkedList::CheckExist(string item) {

     int foundCt = 0;

     Node* nextNode = head;
     while (nextNode) {

          if (nextNode->GetValue() == item)
               foundCt++;
          
          nextNode = nextNode->NextNode();

     }

     return foundCt;
}



//private functions to recursively print the list in reverse
void DoublyLinkedList::ReversePrint(Node* aList) {

     //if there is a node followed, call the ReversePrint on the next node
     if (aList->NextNode() != nullptr) {
          ReversePrint(aList->NextNode());        
     }

     //if there is no next node, print the value of this node.
     cout << aList->GetValue();
     if (aList->PrevNode() != nullptr)
          cout << ", ";

}



//Constructor
DoublyLinkedList::DoublyLinkedList(int sizeLimit) {

     head = nullptr;
     tail = nullptr;
     this->sizeLimit = sizeLimit;
     currentSize = 0;

}



//This function add a new node with the value to the head of the list
void DoublyLinkedList::AddToHead(string value) {

     if(currentSize < sizeLimit)
          head = AddNodeToHead(value, head);
     else {
          //print the items on screen
          PrintList();

          //ask user for items to remove
          cout << "Which item do you want to remove from the list? ";
          string removeThis = getValidInputString();

          //remove the item
          if (RemoveSpecific(removeThis)) 
               cout << removeThis + " removed successfully!!" << endl;
          else
               cout << value + " cannot be added!!" << endl;

     }

}



//This function add a new node with the value to the tail of the list
void DoublyLinkedList::AddToTail(string value) {
     
     if (currentSize < sizeLimit) {
          head = AddNodeToTail(value, head, nullptr);
          cout << value + " added successfully!!" << endl;
     }
     else {
          //print the items on screen
          PrintList();

          //ask user for items to remove
          cout << endl << "Your inventory is full. Which item do you want to remove from the list? ";
          string removeThis = getValidInputString();

          //remove the item
          if (RemoveSpecific(removeThis)) {
               cout << removeThis + " removed successfully!!" << endl;
               head = AddNodeToTail(value, head, nullptr);
               cout << value + " added successfully!!" << endl;
          }
          else
               cout << value + " will be discarded!!" << endl;

     }
}



//This function prints the list values on screen in order.
void DoublyLinkedList::PrintList() {

     cout << "Inventory: \n";

     //if the list has nothing return nothing
     if (head == nullptr) {
          cout << "Empty" << endl;
          return;
     }

     //Print the first node value
     cout << head->GetValue();

     //Goes to the next node
     Node* nextNode = head->NextNode();

     //print a comma if there is a next node
     if (nextNode)
          cout << ", ";

     while (nextNode) {    //if there is a node following

          //Print the value for this node
          cout << nextNode->GetValue();

          //Goes to the next node
          nextNode = nextNode->NextNode();

          //print a comma if there is a next node
          if (nextNode)
               cout << ", ";

     }
     cout << endl;

}



//This function prints the list in reverse order.
void DoublyLinkedList::PrintListReverse() {

     //Warn the user if the list is empty
     if (head == nullptr)
          cout << "The list contains no elements!" ;
     else {

          //print the original order
          PrintList();

          //Recursively print the value in reverse order
          cout << endl << "The reverse order of the list is: ";
          ReversePrint(head);
     }

}



//This function prints the value of the node the head is pointing to
void DoublyLinkedList::PrintHeadValue() {

     if (head)
          cout << endl << "The value of the Head node is " << head->GetValue() << ".";
     else
          cout << endl << "The Head is empty!";

}



//This function prints the value of the node the tail is pointing to
void DoublyLinkedList::PrintTailValue() {

     if (tail)
          cout << endl << "The value of the Tail node is " << tail->GetValue() << ".";
     else
          cout << endl << "The Tail is empty!";

}



//This is the destructor to dynamically allocated nodes properly
DoublyLinkedList::~DoublyLinkedList() {

     Node* nextNode = head;

     //loop over the list until no next node
     while(nextNode){

          //set the current nextNode to a node named garbage
          Node* garbage = nextNode;

          //set nextNode to the next node nextNode points to
          nextNode = nextNode->NextNode();

          //free the memory pointed to by garbage
          delete garbage;

     }

}
