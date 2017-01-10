// File: proj3.cpp                                                             
// Project: CMSC 202 Project 3, Fall 2016                                      
// Author: Kyle Lee                                                            
// Date: 10/23/16                                                               
// Section 4                                                                   
// Email: leek4@umbc.edu                                                       
//This file is the main program for Project 3. The program allows the user to u\
pload a text file containing a list of words and integers attached. The user ca\
n decide to decypher the text file to form a comprehensible sentence by finding\
 the "real" words. The user can also decide to overwrite the file and load a ne\
w text file or to append a file onto the current one. The user can finally exit\
 the program and clear the current data.                                        

#include "LinkedList.h"
#include "proj3.h"

int main () {
  LinkedList list;
  mainMenu(list);
  return 0;
}

//readFile                                                                      
//pre: takes in a linkedlist                                                    
//post: reads in a file from the user                                           
void readFile(LinkedList &list){
  ifstream inputStream;
  string file;
  int newInt;
  string payload;
  int counter = 0;
  bool empty = list.IsEmpty();
  bool cancel = false;
    
 //if list is not empty                                                        
  if(empty == false){
    int option = NULL;
    do{
      cout << "Do you want to: " << endl;
      cout << "1. Overwrite the message" << endl;
      cout << "2. Append the message" << endl;
      cout << "3. Cancel" << endl;
      cout << "Make a choice: ";
      cin >> option;
      cout << "\n";
    } while(option < 1 || option > 3);

    switch(option){
    case 1:
      list.Clear();
      cout << "Previous message cleared" << endl;
      break;
    case 2:
      list.InsertEnd(newInt, payload);
      break;
    case 3:
      cancel = true;
    }
  }

  if(cancel == false){
    cout << "What is the file name?: ";
    cin >> file;
    inputStream.open(file.c_str());

    //reads each line of the text file                                          
    while(inputStream >> newInt >> payload){
      counter =+ 1;
      //appends data to link list                                               
      list.InsertEnd(newInt, payload);
    }

    if(counter == 0){
      cout << "Message load failed" << endl;
    }
    else {
      cout << "New Message Loaded" << endl;
    }
    inputStream.close();
  }
}

void mainMenu(LinkedList &list){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. Load a new encrypted message" << endl;
      cout << "2. Display a raw message" << endl;
      cout << "3. Display an encrypted message" << endl;
      cout << "4. Exit" << endl;
      cout << "Make a choice: ";
      cin >> option;
      cout << "\n";
    } while(option < 1 || option > 4);
    switch(option){
    case 1:
      readFile(list);
      break;
    case 2:
      displayMessage(list);
      break;
    case 3:
      displayEncrypt(list);
      break;
    case 4:
      exitLinked(list);
      isExit = 1;
    }
  } while(isExit == 0);
}

//displayMessage                                                                
//pre: takes in a linked list                                                   
//post: displays raw meesage and sorted raw message                             
void displayMessage(LinkedList &list){
  bool empty = list.IsEmpty();

  //if the list is not empty...                                                 
  if(empty == false){
    list.Display();
    list.Sort();
    list.Display();
  }
  else{
    cout << "You haven't loaded an encrypted message yet." << endl;
  }
}

//exitLinked                                                                    
//pre: takes in a list                                                          
//post: clears linked list and exits program                                    
void exitLinked(LinkedList &list){
  list.Clear();
}

//exitLinked                                                                    
//pre: takes in a list                                                          
//post: clears linked list and exits program                                    
void exitLinked(LinkedList &list){
  list.Clear();
}

//displayEncrypt                                                                
//pre: takes in a linked list                                                   
//post: displays decrypted message                                              
void displayEncrypt(LinkedList &list){
  bool empty = list.IsEmpty();

  if(empty == false){
    LinkedList newList = list.Decrypt();
    newList.Sort();
    newList.Display();
  }
  else{
    cout << "You haven't loaded an encrypted message yet." << endl;
  }
}




