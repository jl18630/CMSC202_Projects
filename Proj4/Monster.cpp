// File: Monster.cpp                                                          
// Project: CMSC 202 Project 4, Fall 2016                                      
// Author: Kyle Lee                                                            
// Date: 11/14/16                                                              
// Section 4                                                                   
// Email: leek4@umbc.edu                                                       
//This file is the .cpp file for Monster                                     

#include "Monster.h"
#include "Ben.h"
#include "Pyronite.h"
#include "Crystalsapien.h"

using namespace std;

//Monster (constructor)
//pre: passes in current level
//post: creates Monster object and randomly generates life points and attack damage based on level
Monster::Monster(int level){
  //reads in monster name into vector from text file
  LoadMonster();
  //randomly choose a monster from the monster vector
  m_name = SummonMonster();

  //randomly generate monster's life points and attack damage based on level
  if(level == 1){
    m_life = rand() % ((50 - 20) + 1) + 20;
    m_attack = rand() % ((5 - 1) + 1) + 1;
  }
  else if(level == 2){
    m_life = rand() % ((60 - 30) + 1) + 30;
    m_attack = rand() % ((10 - 3) + 1) + 3;
  }
  else{
    m_life = rand() % ((70 - 40) + 1) + 40;
    m_attack = rand() % ((15 - 5) + 1) + 5;
  }
}

//NOTE: MONSTER DESTRUCTOR IS NOT NEEDED STATED BY TA
Monster::~Monster(){
}

//SummonMonster
//pre: None
//post: returns a randomly choosen monster from the monster vector
string Monster::SummonMonster(){
  int randSummonPosition = rand() % static_cast<int>(m_monster.size()) + 1;
  return m_monster.at(randSummonPosition - 1);
}

//LoadMonster
//pre: None
//post: reads in each monster's name into a vector from a text file
void Monster::LoadMonster(){
  string FILE = "monster.txt";
  ifstream inputStream;
  string name;
  inputStream.open(FILE.c_str());

  //reads in each line of the text file until reaching the last string
  while(getline(inputStream, name)){
    //pushes the monster's name into the m_monster vector
    m_monster.push_back(name);
  }
  inputStream.close();
}

//Attack
//pre: passes in current Ben object by reference
//post: changes the life points of the current Ben form
void Monster::Attack(Ben *&target){
  cout << GetName() << " attacks " << target -> GetName() << " using a normal attack." << endl; 
  //if the current Ben form is 'Crystalsapien'...
  if(target -> GetName() == "Crystalsapien"){
    //change the life points of the current Ben form based on reduced normal 
    //attack damage
    int reductedAttack = m_attack - ((target -> GetDefenseBonus() / 100) * m_attack);
    target -> SetLife(target -> GetLife() - reductedAttack);
  }
  else{
    target -> SetLife(target -> GetLife() - m_attack);
  }
  cout << GetName() << " did " << m_attack << " to " << target -> GetName() << endl;
}

//SetLife
//pre: passes in current life points of the current monster
//post: assigns m_life with life points
void Monster::SetLife(int life){
  m_life = life;
}

//GetLife
//pre: None
//post: returns life points of current Monster
int Monster::GetLife(){
  return m_life;
}

//GetName
//pre: Noen
//post: returns name of currentMonster
string Monster::GetName(){
  return m_name;
}