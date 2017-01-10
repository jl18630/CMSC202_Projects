// File: Ben.cpp                                                             
// Project: CMSC 202 Project 4, Fall 2016                                      
// Author: Kyle Lee                                                            
// Date: 11/14/16                                                              
// Section 4                                                                   
// Email: leek4@umbc.edu                                                       
//This file is the .cpp file for Ben 

#include "Ben.h"
#include "Monster.h"
#include "Pyronite.h"
#include "Crystalsapien.h"
#include <stdlib.h> 

using namespace std;

//Ben (default constructor)
//pre: None
//post: assigns m_name and m_life
Ben::Ben(string name, int life){
  m_name = name;
  m_life = life;
}

//Ben (constructor)
//pre: None
//post: assigns mutator variables when creating a new Ben object
Ben::Ben(string name, int life, string nameNorm, string nameSpecial, double defenseBonus, double missPercent, int usedSpecial, int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec){
  m_name = name;
  m_life = life;
  m_nameNormal = nameNorm;
  m_nameSpecial = nameSpecial;
  m_defenseBonus = defenseBonus;
  m_missPercent = missPercent;
  m_usedSpecial = usedSpecial;
  m_maxSpecial = maxSpecial;
  m_minDamageNormal = minDamNorm;
  m_maxDamageNormal = maxDamNorm;
  m_damageSpecial = damSpec;
}

//NOTE: BEN DESTRUCTOR IS NOT NEEDED STATED BY TA
Ben::~Ben(){}

//Attack
//pre: passes in current Monster object by reference
//post: changes the life points of the current monster 
void Ben::Attack(Monster *&target){
  //randomly generate the normal attack damage based on given range
  int randNormalAttack = rand() % ((m_maxDamageNormal - m_minDamageNormal) + 1) + m_minDamageNormal;
  //randomly generate the miss percentage of the current Ben form
  int randMissPercentage = rand() % ((100 - 1) + 1) + 1;

  if(randMissPercentage <= m_missPercent)
    cout << "You missed!" << endl;
  else{
    //change the current monster's life points based on normal attack damage
    target -> SetLife(target -> GetLife() - randNormalAttack);
    cout << GetName() << " attacks using his " << m_nameNormal << " attack." << endl;
    cout << GetName() << " did " << randNormalAttack << " to " << target -> GetName() << "." << endl;
  }
}

//SpecialAttack
//pre: passes in current Monster object by reference
//post: changes the life points of the current monster
void Ben::SpecialAttack(Monster *&target){
  //if the user has not used up the amount of specials...
  if(m_usedSpecial < m_maxSpecial){
    //change the current monster's life points based on special attack damage
    target -> SetLife(target -> GetLife() - m_damageSpecial);
    cout << GetName() << " attacks using his " << m_nameSpecial << " attack." << endl;
    cout << GetName() << " did " << m_damageSpecial <<" to " << target -> GetName() << "." << endl;
    //add one to the number of times special is used
    m_usedSpecial += 1;
  }
  else{
    cout << "You have used up his special" << endl;
  }
}

//UltimateAttack
//pre: passes in current Monster object by reference
//post: prints out that Ben has no ultimate attack
void Ben::UltimateAttack(Monster *&target){
  cout << m_name << " has no ultimate attack! ";
  cout << target -> GetName() << " retaliates!" << endl;
}

//SetLife
//pre: passes in lifepoints
//post: assigns m_life as life points of Ben
void Ben::SetLife(int life){
  m_life = life;
}

//GetName
//pre: None
//post: returns name of Ben form
string Ben::GetName(){
  return m_name;
}

//GetLife
//pre: None
//post: returns the lifepoints of Ben form
int Ben::GetLife(){
  return m_life;
}

//GetDefenseBonus
//pre: None
//post: returns defense bonus of Ben form
double Ben::GetDefenseBonus(){
  return m_defenseBonus;
}