// File: Game.cpp                                                             
// Project: CMSC 202 Project 4, Fall 2016                                      
// Author: Kyle Lee                                                            
// Date: 11/14/16                                                              
// Section 4                                                                   
// Email: leek4@umbc.edu                                                       
//This file is the program for running the game. The program allows the user to play as multiple forms of Ben: Ben, Pyronite, and Crystalsapien. The user gets to choose the amount of levels to play, fighting a random monster within each level. If Ben wins the match, the user gets to move up to the next level. If the Ben loses with zero life points, the game ends. When Ben completes all the levels, Ben wins and the game ends.

#include "Game.h"
#include "Ben.h"
#include "Pyronite.h"
#include "Crystalsapien.h"
#include "Monster.h"

using namespace std;

//Game (constructor)
//pre: None
//post: initializes the number of levels, the forms of Ben, and the monsters 
//used for each level
Game::Game(){
  m_level = 1;
  m_levels = NumLevels();
  InitMonsters();
  InitBen();
  Start(100);
}

//Game (Destructor)
//pre: None
//post: deallocates each of the forms of Ben and monster from their arrays
Game::~Game(){
  for(int i = 0; i < m_levels; i++){
    //delete the Ben and monster of the current index
    delete m_mons[i];
  }
  for(int i = 0; i < 3; i++){
    delete m_ben[i];
  }
  //delete the array itself of Ben and Monster
  delete [] m_mons;
  delete [] m_ben;
}

//InitMonsters
//pre: None
//post: creates a monster object for each index of the pointer array
void Game::InitMonsters(){
  //create a pointer array based on the amount of levels provided by the user
  m_mons = new Monster* [m_levels];
 
  for(int i = 0; i < m_levels; i++){
    //creates a monster object of that index 
    m_mons[i] = new Monster(i + 1);
  }
}

//InitBen
//pre: None
//post: creates objects for each form of Ben in the Ben pointer array
void Game::InitBen(){
  m_ben = new Ben* [3];
  m_ben[0] = new Ben("Ben", 100, "hand-to-hand", "kick", 0, 10, 0, 2, 10, 20, 25);
  m_ben[1] = new Pyronite("Pyronite", 120, "fire", "flamer", 0, 15, 0, 1, 15, 20, 30);
  m_ben[2] = new Crystalsapien("Crystalsapien", 120, "energy", "laser", 25, 25, 0, 1, 25, 30, 10);
}

//SetBen
//pre: pass in the life points of the current form of Ben
//post: set the selected form of Ben as the current Ben used at the current 
//level
void Game::SetBen(int startLife){
  int benForm = 0;
  //if the current level is level 1...
  if(m_level == 1){
    //Ben is avaliable
    m_formsBen = 1;
    cout << "Select one from the avaliable forms of Ben at level " << m_level << " are: " << endl;
    cout << "1. " << m_ben[m_formsBen - 1] -> GetName() << endl;
  }
  //if the current level is level 2...
  else if(m_level == 2){
    //Ben and Pyronite are avaliable
    m_formsBen = 2;
    cout << "Select one from the avaliable forms of Ben at level " << m_level << " are: " << endl;
    cout << "1. " << m_ben[m_formsBen - 2] -> GetName() << endl;;
    cout << "2. " << m_ben[m_formsBen - 1] -> GetName() << endl;
  }
  //if the current level is level 3 or above...
  else{
    //Ben, Pyronite, and Crystalsapien are avaliable
    m_formsBen = 3;
    cout << "Select one from the avaliable forms of Ben at level " << m_level << " are: " << endl;
    cout << "1. " << m_ben[m_formsBen - 3] -> GetName() << endl;;
    cout << "2. " << m_ben[m_formsBen - 2] -> GetName() << endl;
    cout << "3. " << m_ben[m_formsBen - 1] -> GetName() << endl;
  }

  //Keep asking the user for a valid input 
  while(benForm <= 0 || benForm > m_formsBen){                                
    cout << "What would you like to do?" << endl;                             
    cout << "Enter 1 to " << m_formsBen << ": ";                              
    cin >> benForm;                                                           
    if(benForm <= 0 || benForm > m_formsBen){                                 
      cout <<"Invalid input. Please re-enter." << endl;                       
    }                                                                         
    cout << "\n";                                                             
  }                                  
  //set the current Ben as the selected form of Ben                            
  m_currBen = m_ben[benForm - 1];                                             
  //Append the current life points from the previous form of Ben to the current Ben
  m_currBen -> SetLife(startLife);   
}

//Start
//pre: passes in the current life points
//post: runs the game until Ben dies or user completes all the levels
void Game::Start(int startLife){
  bool continueGame = true;
  bool levelComplete = true;
 
  //keep running game until Ben dies or user completes all the levels
  while(m_level <= m_levels && continueGame == true){
    //if a new level starts...
    if(levelComplete == true){
      cout << "\tThe game starts... \n\tLEVEL " << m_level << " of " << m_levels << endl;         
      //if the current level is level 1...
      if(m_level == 1)
	//set the life points of the current Ben as 100
	SetBen(startLife);
      //if the current level is after level 1...
      else{
	//set the life points of the current Ben as the life points from the 
	//previous used form of Ben
	SetBen(m_currBen -> GetLife());
      }
      //set the current monster based on the current level
      m_currMons = m_mons[m_level - 1];                                       
                                                                              
      cout << "Ben: " << m_currBen -> GetName() << endl;                       
      cout << "Monster: " << m_currMons -> GetName() << endl;                  
      cout << "The start life of " << m_currBen -> GetName() << " is: " << m_currBen -> GetLife() << endl;                                                 
      cout << "The start life of " << m_currMons -> GetName() << " is: " << m_currMons -> GetLife() << endl;

      levelComplete = false;
    }
    //Show life points
    if(m_currBen -> GetLife() < 0)
      m_currBen -> SetLife(0);
    cout << m_currBen -> GetName() << ": " << m_currBen -> GetLife() << "\t";
    if(m_currMons -> GetLife() < 0)
      m_currMons -> SetLife(0);
    cout << m_currMons -> GetName()  << ": " << m_currMons -> GetLife() << endl;
    //if Ben dies...
    if(m_currBen -> GetLife() <= 0){
      cout << "Game Over! " << m_currMons -> GetName() << " wins." << endl;
      //stop game
      continueGame = false;
    }
    //if Ben beats the monster...
    else if(m_currBen -> GetLife() > 0 && m_currMons -> GetLife() <= 0){
      cout << "Congrats! " << m_currBen -> GetName() << " won that level.\n" << endl;
      //move to the next level
      m_level += 1;
      //start new level
      levelComplete = true;
    }
    //if the level is currently in progress...
    else if(m_currBen -> GetLife() > 0 && m_currMons -> GetLife() > 0){
      //choose an option to attack monster
      continueGame = Input();
      //if monster is alive...
      if(m_currMons -> GetLife() > 0){
	//monster attacks Ben
	m_currMons -> Attack(m_currBen);
      }
    }
    //Win condition
    if(m_level > m_levels){
      cout << "Congrats! You won the game." << endl;
      continueGame = false;
    }
  }
}

//NumLevels
//pre: None
//post: returns the amount of levels the user wishes to play
int Game::NumLevels(){
  int levels;
  cout << "How many levels would you like to try?: ";
  cin >> levels;

  while(levels < 1 || levels > 20){
    cout << "You cannot have more than 20 levels: " << endl;
    cout << "How many levels would you like to try?: ";
    cin >> levels;
  }

  return levels;
}

//Input
//pre: None
//post: returns a boolean value to continue game or not
bool Game::Input(){
  bool continueGame = true;
  int choice = -1;

  //keep printing out menu and ask user for a valid option
    do{                                                    
      cout << "What would you like to do?" << endl;                            
      cout << "1. Normal Attack" << endl;                                      
      cout << "2. Special Attack" << endl;                                     
      cout << "3. Ultimate Attack" << endl;                                    
      cout << "Enter 1 to 3: ";                                                
      cin >> choice;
      if(choice < 1 || choice > 3){
	cout << "Invalid input. Please re-enter." << endl;
      }
      cout << "\n";
    }while(choice < 1 || choice > 3);

    switch(choice){
      case 1:
	//current form of Ben uses a normal attack on monster
	m_currBen -> Attack(m_currMons);
	break;
      case 2:
	//current form of Ben uses a special attack on monster
	m_currBen -> SpecialAttack(m_currMons);
	break;
      case 3:
	//current form of Ben uses an ultimate attack on monster
	m_currBen -> UltimateAttack(m_currMons);
	break;
    }

  return continueGame;
}