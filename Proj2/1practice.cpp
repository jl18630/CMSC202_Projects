#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void printPokemon(int num, string name, int cpMin, int cpMax, int rarity);

int main(){
  int num;
  string name;
  int cpMin;
  int cpMax;
  int rarity;

  ifstream inputStream;
  inputStream.open("pokeDex.txt");

  while(!inputStream.eof()){
    inputStream >> num >> name;
  }

  printPokemon(num, name, cpMin, cpMax, rarity);

  inputStream.close();
  return 0;
}

void printPokemon(int num, string name, int cpMin, int cpMax, int rarity){
  cout << num << " " << " " << name;
}

