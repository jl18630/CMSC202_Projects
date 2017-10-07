#include <iostream>
#include <stdlib.h>
#include <string>
#include "Pokemon.h"

using namespace std;

Pokemon::Pokemon(){
  m_Num = 0;
  m_Name = "name";
  m_MinCP = 0;
  m_MaxCP = 0;
  m_Rarity = 0;
}

Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity){
  m_Num = num;
  m_Name = name;
  m_MinCP = cpMin;
  m_MaxCP = cpMax;
  m_Rarity = rarity;
}

int Pokemon::GetCPMin(){
  return m_MinCP;
}

int Pokemon::GetCPMax(){
  return m_MaxCP;
}

/*                                                                              
void Pokemon::SetCP(int newCP){                                                 
  m_CP = newCP;                                                                 
}                                                                               
*/

int Pokemon::GetRarity(){
  return m_Rarity;
}

void Pokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
}

string Pokemon::GetName(){
  return m_Name;
}

void Pokemon::SetName(string newName){
  m_Name = newName;
}

int Pokemon::GetNum(){
  return m_Num;
}

