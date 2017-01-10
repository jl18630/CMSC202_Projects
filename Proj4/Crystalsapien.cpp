// File: Crystalsapien.cpp                                                    
// Project: CMSC 202 Project 4, Fall 2016                                      
// Author: Kyle Lee                                                            
// Date: 11/14/16                                                              
// Section 4                                                                   
// Email: leek4@umbc.edu                                                       
//This file is the .cpp file for Crystalsapien   

#include "Crystalsapien.h"
#include "Pyronite.h"
#include "Monster.h"
#include "Ben.h"
#include <stdlib.h>
using namespace std;


Crystalsapien::Crystalsapien(string name, int life);

Crystalsapien::Crystalsapien(string name, int life, string nameNormal, string nameSpecial, double defenseBonus, double missPercent, int usedSpecial, int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec);
  
//Attack
//pre: passes in current Monster object by reference
//post: changes the life points of the current monster
void Crystalsapien::Attack(Monster *&target){
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
void Crystalsapien::SpecialAttack(Monster *&target){
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
//post: changes life points of the current monster using Ultimate ability
void Crystalsapien::UltimateAttack(Monster *&target){
  //change the current monster's life points based on ultimate attack damage
  target -> SetLife(target -> GetLife() - (m_damageSpecial * 10));
  cout << GetName() << " attacks using **ULTIMATE** ATTACK!!" << endl; 
}
