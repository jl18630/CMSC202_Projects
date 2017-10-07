#include <iostream>
#include <stdlib.h>
#include <string>
#include "MyPokemon.h"

using namespace std;

MyPokemon::MyPokemon(){
  m_Num = 0;
  m_Name = "name";
  m_CP = 0;
  m_HP = 0;
  m_Rarity = 0;
}

MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity){
  m_Num = num;
  m_Name = name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;
}

int MyPokemon::GetCP(){
  return m_CP;
}

void MyPokemon::SetCP(int newCP){
  m_CP = newCP;
}


int MyPokemon::GetHP(){
  return m_HP;
}

void MyPokemon::SetHP(int newHP){
  m_HP = newHP;
}

int MyPokemon::GetRarity(){
  return m_Rarity;
}

void MyPokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
}

string MyPokemon::GetName(){
  return m_Name;
}

void MyPokemon::SetName(string newName){
  m_Name = newName;
}

int MyPokemon::GetNum(){
  return m_Num;
}

void MyPokemon::Train(){
  m_CP = m_CP + 10;
}
