// File: proj2.cpp                                                              
// Project: CMSC 202 Project 2, Fall 2016                                       
// Author: Kyle Lee                                                             
// Date: 10/9/16                                                                
// Section 4                                                                    
// Email: leek4@umbc.edu                                                        
// This file is the main program for Project2. The program allows the user to p\
lay a simple implementation of Pokemon. In the game the user is able to find an\
d collect Pokemon based on an existing list of Pokemon. Once the user catches s\
ome Pokemon, the user can either train owned Pokemon or battle other Pokemon ra\
ndomly spawned. Once finished, the user can exit and save the Pokemon owned.    

#include "proj2.h"

int main () {
  srand(time(NULL));
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu (pokeDex, myCollection);
  return 0;
}

//getPokeDex                                                                    
//pokeDex list uploaded from "pokeDex.txt"                                      
//pushes data from text file into Pokemon vector                                
void getPokeDex(vector<Pokemon> & pokeDex){
  int num, cpMin, cpMax, rarity;
  string name;
  ifstream inputStream;

  inputStream.open(POKEDEX);

  //while each line is read until the last line...                              
  while(inputStream >> num >> name >> cpMin >> cpMax >> rarity){
    //create class Pokemon object with data from .txt file                      
    Pokemon inputPokemon(num, name, cpMin, cpMax, rarity);
    //push object into pokeDex vector                                           
    pokeDex.push_back(inputPokemon);
  }

  inputStream.close();
}


//getMyCollection                                                               
//list of owned Pokemon uploaded from "myCollection.txt"                        
//pushes data from text file into MyPokemon vector                              
void getMyCollection(vector<MyPokemon> & myCollection){
  int num, cp, hp, rarity;
  string name;
  ifstream inputStream;

  inputStream.open(MYCOLLECTION);

  //while each line is read until the last line...                              
  while(inputStream >> num >> name >> cp >> hp >> rarity){
    //create class MyPokemon object with data from .txt file                    
    MyPokemon inputMyPokemon(num, name, cp, hp, rarity);
    //push object into myCollection vector                                      
    myCollection.push_back(inputMyPokemon);
  }

  inputStream.close();
}


//printPokeDex                                                                  
//passes in pokeDex vector                                                      
//prints out list of total Pokemon existing                                     
void printPokeDex(vector <Pokemon> & pokeDex){
  //from the first to last element...                                           
  for(int i = 0; i < POKECOUNT; i++){
    //print out the Pokemon's number and name                                   
    cout << pokeDex.at(i).GetNum() <<  ".    " << pokeDex.at(i).GetName() << en\
dl;
  }
  cout << "\n";
}

//printMyCollection                                                             
//passes in myCollection vector                                                 
//prints out list of Pokemon owned by user                                      
void printMyCollection(vector <MyPokemon> & myCollection){
  //from the first to last element of the list of owned Pokemon...              
  for(unsigned int i = 0; i < myCollection.size(); i++){
    //print out the Pokemon's number, name, CP, HP, and rarity                  
    cout << myCollection.at(i).GetNum() << ".    " << myCollection.at(i).GetNam\
e() << "   " << myCollection.at(i).GetCP() << "   " << myCollection.at(i).GetHP\
() << "   " << myCollection.at(i).GetRarity() << endl;
  }
  cout << "\n";
}


//catchPokemon                                                                  
//passes in pokeDex and myCollection vector                                     
//calls function for found Pokemon or tells user that no Pokemon were found     
void catchPokemon(vector <Pokemon> & pokeDex, vector <MyPokemon> & myCollection\
){
  bool validation = false;
  int catchOption;
  int catchChance = rand() % 100 + 1;  //random number generator from 1 - 100%  
  srand(time(NULL));

  //keep asking user to choose an option until a valid option is chosen         
  while(validation == false){
    cout << "What type of Pokemon would you like to try and catch?: " << endl;
    cout << "1. Very Common (Very High Probability)" << endl;
    cout << "2. Common (High Probability)" << endl;
    cout << "3. Uncommon (Normal Probability)" << endl;
    cout << "4. Rare (Low Probability)" << endl;
    cout << "5. Ultra Rare (Extremely Low Probability)" << endl;
    cout << "\nChoose an option: ";
    cin >> catchOption;
    cout << "\n";

    if(catchOption >= 1 && catchOption <= 5)
      cout << "You start to search." << endl;
      validation = true;
  }
  
 //call found function based on if the found percentage is met or not          
  switch(catchOption){
  case 1:
    if(catchChance <= 65){
      foundPokemon(catchOption, pokeDex, myCollection);
    }
    else {
      cout << "You did not catch any Pokemon" << endl;
    }
    break;
  case 2:
    if(catchChance <= 45){
      foundPokemon(catchOption, pokeDex, myCollection);
    }
    else {
      cout << "You did not catch any Pokemon" << endl;
    }
    break;
  case 3:
    if(catchChance <= 25){
      foundPokemon(catchOption, pokeDex, myCollection);
    }
    else {
      cout << "You did not catch any Pokemon" << endl;
    }
    break;
  case 4:
    if(catchChance <= 10){
      foundPokemon(catchOption, pokeDex, myCollection);
    }
    else {
      cout << "You did not catch any Pokemon" << endl;
    }
    break;
  case 5:
    if(catchChance <= 1){
      foundPokemon(catchOption, pokeDex, myCollection);
    }
    else {
      cout << "You did not catch any Pokemon" << endl;
    }
    break;
    }
}


//foundPokemon                                                                  
//passes in option for rarity type from catchPokemon and pokeDex and myCollecti\
on vector                                                                       
//prints found Pokemon and pushes found Pokemon into myCollection vector        
void foundPokemon(int rarity, vector <Pokemon> & pokeDex, vector<MyPokemon> & m\
yCollection){
  bool validation = false;

  //keep generating a random Pokemon until the rarity matches                   
  while(validation == false){
    int randomPokemon = rand() % POKECOUNT + 0;
    if(pokeDex.at(randomPokemon).GetRarity() == rarity){
      cout << "Congrats! You found a " << pokeDex.at(randomPokemon).GetName() <\
< endl;

      //randomly generate CP for found Pokemon                                  
      int randomCP = rand() % pokeDex.at(randomPokemon).GetCPMax() + pokeDex.at\
(randomPokemon).GetCPMin();
      //found Pokemon's HP                                                      
      int randomHP = randomCP / 10;
      cout << "\n";

      //create class MyPokemon object for found Pokemon                         
      MyPokemon found(pokeDex.at(randomPokemon).GetNum(), pokeDex.at(randomPoke\
mon).GetName(), randomCP, randomHP, pokeDex.at(randomPokemon).GetRarity());
      //push object into myCollection vector                                    
      myCollection.push_back(found);

      validation = true;
    }
  }
}


//mainMenu                                                                      
//passes in pokeDex and myCollection vector                                     
//calls appropriate function based on user input                                
void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cout << "\nChoose an option: ";
      cin >> option;
      cout << "\n";
    }while(option < 1 || option > 6);
    
    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}


//battlePokemon                                                                 
//passes in pokeDex and myCollection vector                                     
//tells user has won the battle or not                                          
 void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollectio\
n){
   bool validation = false;
   unsigned int MyPokemonPosition;  //list number for owned Pokemon             
   unsigned int pokeDexPokemonPosition = rand() % POKECOUNT + 0;  //list number\
 of Pokemon in pokeDex                                                          
   unsigned int pokeDexPokemonCP = rand() % (pokeDex.at(pokeDexPokemonPosition)\
.GetCPMax() - pokeDex.at(pokeDexPokemonPosition).GetCPMin()) + pokeDex.at(pokeD\
exPokemonPosition).GetCPMin();  //CP of Pokemon in pokeDex                      
   int totalPokemon = 0;  //total number of owned Pokemon                       

   //print out list of owned Pokemon                                            
   while(validation == false){
     cout << "Which of the Pokemon would you like to use?: " << endl;
     for(unsigned int i = 0; i < myCollection.size(); i++){
       totalPokemon += 1;
       cout << i << ".    " << myCollection.at(i).GetNum() << "   " << myCollec\
tion.at(i).GetName() << "   " << myCollection.at(i).GetCP() << "   " << myColle\
ction.at(i).GetHP() << "   " << myCollection.at(i).GetRarity() << endl;
     }

     //if there is at least one Pokemon in the list, enter what Pokemon to use  
     if(totalPokemon > 0){
       cout << "\nYou are going to fight a " << pokeDex.at(pokeDexPokemonPositi\
on).GetName() << endl;
       cout << "The enemy has a CP of " << pokeDexPokemonCP << endl;
       cout << "Which of your Pokemon would you like to use?: ";
       cin >> MyPokemonPosition;

       //if user chooses a valid Pokemon...                                     
       if(MyPokemonPosition >= 0 && MyPokemonPosition < myCollection.size()){
         //if owned Pokemon's CP is higher than the Pokemon being fought, user  
         //wins                                                                 
         if((unsigned int)myCollection.at(MyPokemonPosition).GetCP() >= (unsign\
ed int)pokeDexPokemonCP){
           cout << "\nYou won!" << endl;
           validation = true;
         }
//if owned Pokemon's CP is lower than the Pokemon being fought, user loses                                           

         else {
           cout << "\nYou lost!" << endl;
           validation = true;
         }
       }
     }
     //if there are no Pokemon in user's list...                                
     else {
       cout << "You have no Pokemon to use for battle\n" << endl;
       validation = true;
     }
   }
}


//trainPokemon                                                                  
//passes in pokeDex and myCollection vector                                     
//call train function for selected Pokemon                                      
 void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection\
){
   bool validation = false;
   unsigned int trainPokemonPosition; //list number for owned Pokemon           
   int totalMyPokemon = 0;  //total Pokemon in user's list                      

   //keep running program until valid Pokemon is choosen                        
   while(validation == false){
     cout << "Which of your Pokemon would you like to use?: " << endl;
     //print out owned Pokemon's number, name, CP, HP, and rarity               
     for(unsigned int i = 0; i < myCollection.size(); i++){
       totalMyPokemon += 1;
       cout << i << ".    " << myCollection.at(i).GetNum() << "   " << myCollec\
tion.at(i).GetName() << "   " << myCollection.at(i).GetCP() << "   " << myColle\
ction.at(i).GetHP() << "   " << myCollection.at(i).GetRarity() << endl;
     }

//if there is at least one owned Pokemon...                                
     if(totalMyPokemon > 0){
       cout << "Choose a Pokemon: ";
       cin >> trainPokemonPosition;
       cout << "\n";
       //if user chooses a valid Pokemon...                                     
       if(trainPokemonPosition >= 0 && trainPokemonPosition < myCollection.size\
()){
         //call train function for selected Pokemon                             
         myCollection.at(trainPokemonPosition).Train();
         cout << "\nYour " << myCollection.at(trainPokemonPosition).GetName() <\
< " trained." << endl;
         cout << "Your CP is now " << myCollection.at(trainPokemonPosition).Get\
CP() << endl;
         cout << "\n";
         validation = true;
       }
     }
     //if there are no owned Pokemon in the list...                             
     else {
       cout << "You have no Pokemon to train\n" << endl;
       validation = true;
     }
   }
}


//exitPokemon                                                                   
//passes in myCollection vector                                                 
//calls save function                                                           
 void exitPokemon(vector<MyPokemon> & myCollection){
   saveMyCollection(myCollection);
 }
 

//saveMyCollection                                                              
//passes in myCollection vector                                                 
//saves owned Pokemon list into text file "myCollections.txt"                   
void saveMyCollection(vector<MyPokemon> & myCollection){
  ofstream outputStream;

  outputStream.open(MYCOLLECTION);

  //for each owned Pokemon in the list...                                       
  for(unsigned int i = 0; i < myCollection.size(); i++){
    //output content into .txt file                                             
    outputStream << myCollection.at(i).GetNum() << "   " << myCollection.at(i).\
GetName() << "   " << myCollection.at(i).GetCP() << "   " << myCollection.at(i)\
.GetHP() << "   " << myCollection.at(i).GetRarity() << endl;
    }

  cout << "File Saved" << endl;
  cout << "Thank you for playing Pokemon UMBC" << endl;
  outputStream.close();
}



