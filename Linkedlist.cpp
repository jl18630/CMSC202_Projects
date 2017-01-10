// File: LinkedList.cpp                                                        
// Project: CMSC 202 Project 3, Fall 2016                                      
// Author: Kyle Lee                                                            
// Date: 10/23/16                                                              
// Section 4                                                                   
// Email: leek4@umbc.edu                                                       
// This file contains the code for the LinkedList class functions               

#include "LinkedList.h"

using namespace std;


//LinkedList (constructor)                                                      
//pre: none                                                                     
//post: m_head and m_tail are pointing to null                                  
LinkedList::LinkedList(){
  m_head = NULL;
  m_tail = NULL;
}

//LinkedList (destructor)                                                       
//pre: none                                                                     
//post: deallocates linked list from memory                                     
LinkedList::~LinkedList(){
  Clear();
}

//CreateNode                                                                    
//pre: takes in integer and string                                              
//post: creates a new node and returns the node                                 
Node* LinkedList::CreateNode(int newInt, string newPayload){
  //cout << "create" << endl;                                                   
  Node *tempNode = new Node;
  tempNode -> m_int = newInt;
  tempNode -> m_payload = newPayload;
  tempNode -> m_next = NULL;
  return tempNode;
}

//InsertEnd                                                                     
//pre: takes in integer and string                                              
//post: appends a new node onto the linked list                                 
void LinkedList::InsertEnd(int newInt, string newPayLoad){
  //Create a new node          
  Node *newNode = CreateNode(newInt, newPayLoad);
  Node *currentNode;
  bool empty = IsEmpty();

  //if list is empty...                                                         
  if(empty == true){
    //append a new node as the first node                                       
    m_head = newNode;
    currentNode = newNode;
    empty = false;
  }
  //if list is not empty...                                                     
  else {
    currentNode = m_head;
    //while the current node is not the last node in the list...                
    while(currentNode -> m_next != NULL){
      //go to the next node                                                     
      currentNode = currentNode -> m_next;
    }
    //append new node when reaching the last node                               
    currentNode -> m_next = newNode;
  }
}

//Display                                                                       
//pre: none                                                                     
//post: display raw contents                                                    
void LinkedList::Display(){
  Node *currentNode = m_head;

  cout << "Payload of list are: " << endl;
  while(currentNode != NULL){
      cout << currentNode -> m_payload << "->";
      currentNode = currentNode -> m_next;
  }
  cout << "END";
  cout << "\n" << endl;
}

//Sort                                                                          
//pre: none                                                                     
//post: sorts the linked list based on raw integers                             
void LinkedList::Sort(){
  bool isSorted = false;

  //while the linked list is not sorted...                                      
  while(isSorted == false){
    //assume list is sorted                                                     
    isSorted = true;
    Node *currentNode = m_head;

    //traverse the linked list                                                  
    while(currentNode -> m_next != NULL){
      Node *nextNode = currentNode -> m_next;
      int currentInt = currentNode -> m_int;
      int nextInt = nextNode -> m_int;
      string currentString = currentNode -> m_payload;
      string nextString = nextNode -> m_payload;

      //if the integer of current node is greater than the next integer         
      if(currentInt > nextInt){
        int tempCurrentInt = currentInt;
        string tempCurrentString = currentString;

       isSorted = false;
        //swap integers between the current and next node                       
        currentNode -> m_int = nextInt;
        nextNode -> m_int = tempCurrentInt;
        currentNode -> m_payload = nextString;
        nextNode -> m_payload = tempCurrentString;

      }
      //move to the next node                                                   
      currentNode = currentNode -> m_next;
    }
  }
}

//IsEmpty                                                                       
//pre: none                                                                     
//post: returns true or false                                                   
bool LinkedList::IsEmpty(){
  bool isEmpty = false;

  //if the list is empty...                                                     
  if(m_head == NULL){
    //list is empty                                                             
    isEmpty = true;
  }
  return isEmpty;
}

//Decrypt                                                                       
//pre: none                                                                     
//post: returns a linked list containing the "real" integers                    
LinkedList LinkedList::Decrypt(){
  LinkedList decrypted;
  Node *currentNode = m_head;
  int sRoot = 0;   //square root                                                
  int cRoot = 0;   //cube root                                                  
  bool squareRoot = false;
  bool cubeRoot = false;

 //traverse through the linked list                                            
  while(currentNode != NULL){
    //find if the square of the current integer is perfect                      
    squareRoot = IsPerfectSquare(currentNode -> m_int);
    //find if the cube of the current integer is perfect                        
    cubeRoot = IsPerfectCube(currentNode -> m_int);
    //    cout << currentNode -> m_int << endl;                                 

    //if the integer is a perfect square...                                     
    if(squareRoot == true){
      sRoot = sqrt(currentNode -> m_int);
      //append a new node to the new linked list                                
      decrypted.InsertEnd(sRoot, currentNode -> m_payload);
    }
    //if the integer is a perfect cube...                                       
    else if(cubeRoot == true){
      cRoot = cbrt(currentNode -> m_int);
      decrypted.InsertEnd(cRoot, currentNode -> m_payload);
    }

    currentNode = currentNode -> m_next;
  }

  return decrypted;
}

//IsPerfectSquare                                                               
//pre: takes in an integer                                                      
//post: returns true or false                                                   
bool LinkedList::IsPerfectSquare(int n){
  bool isPerfectSquare = false;
  int num = round(sqrt((int)n));
  int square = pow(num, 2);

  //checks to see if the number is a perfect square                             
  if(n == square){
    isPerfectSquare = true;
  }

  return isPerfectSquare;
}

//IsPerfectCube                                                                 
//pre: takes in an integer                                                      
//post: returns true or false                                                   
bool LinkedList::IsPerfectCube(int n){
  bool isPerfectCube = false;
  int num = round(cbrt((int)n));
  int cube = pow(num, 3);

  //checks to see if the number is a perfect cube                               
  if(n == cube){
    isPerfectCube = true;
  }

  return isPerfectCube;
}

//Clear                                                                         
//pre: none                                                                     
//post: clear the linked list                                                   
void LinkedList::Clear(){
  Node *currentNode = m_head;
  Node *previousNode;

  while(currentNode != NULL){
    previousNode = currentNode;
    currentNode = currentNode -> m_next;
    delete previousNode;
  }

  m_head = NULL;
}