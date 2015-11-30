/* 
 * File:   RollDice.cpp
 * Author: Terianne Bolding
 * 
 * Created on November 21, 2015, 1:42 PM
 */

#include "LoadedDiceGame.h"
#include <math.h>
#include <random>
#include <iostream>
#include <fstream>
#include <stdlib.h>
LoadedDiceGame::LoadedDiceGame(string _fileName) : fileName(_fileName) {
    ReadData();
    statsDie1 = new DiceGameStatistics(die1,numberRolls);   // Create statistical tracking object for die1
    statsDie2 = new DiceGameStatistics(die2,numberRolls);   // Create statistical tracking object for die2
    
}

LoadedDiceGame::LoadedDiceGame(const LoadedDiceGame& orig) {
}

LoadedDiceGame::~LoadedDiceGame(){
    delete die1;
    delete die2;
    delete statsDie1;
    delete statsDie2;
}

void LoadedDiceGame::MakeRolls(){
    srand (static_cast <unsigned> (time(0)));
    int side1;
    int side2;
    for(int i =0; i < numberRolls; i++){
        side1 = Roll(die1);
        statsDie1->AddRoll(side1);                      // Add roll result to statistics object for die1
        side2 = Roll(die2);
        statsDie2->AddRoll(side2);                      // Add roll result to statistics object for die2
        cout<<"Throw "<<i+1<<": "<<die1->identifier<<" rolled a "<<side1<<", "<<die2->identifier<<" rolled a "<<side2 <<"\n";
    }

    statsDie1->CalculateRollPercent();                  // Calculate Statistical Percentages of all rolls for die1
    statsDie2->CalculateRollPercent();                  // Calculate Statistical Percentages of all rolls for die2
    statsDie1->PrintRollStatistics();                   // Print Statistical Percentages of all rolls for die1
    statsDie2->PrintRollStatistics();                   // Print Statistical Percentages of all rolls for die2
}
    
int LoadedDiceGame::Roll(const Die * dice){

    float val = (rand()%10000)*.0001;
    int side;
    if (val < dice->DieSides[0]) side = 1;
    else if (val < dice->DieSides[0]+dice->DieSides[1]) side = 2;
    else if (val < dice->DieSides[0]+dice->DieSides[1]+dice->DieSides[2]) side = 3;
    else if (val < dice->DieSides[0]+dice->DieSides[1]+dice->DieSides[2]+dice->DieSides[3]) side = 4;
    else if (val < dice->DieSides[0]+dice->DieSides[1]+dice->DieSides[2]+dice->DieSides[3]+dice->DieSides[4]) side = 5;
    else side = 6;
    return side;
}

void LoadedDiceGame::ReadData(){
    ifstream diceFile;                                  // file input stream
    string data[7];                                     // Array to capture data from file                 
    diceFile.open(fileName);                            // Open file input stream
    int count = 0;
    if (diceFile.is_open()) {
        while (count < 8) {
            diceFile >> data[count++];
        }
    }
    else{
        cout<<"Error: Filename does not exist, Game Over"; // Quit if file does not exist
        exit(1);
    }
    string delimiter = "=";
    for(int i=0; i<4; i++) gameData[data[i].substr(0, data[i].find(delimiter))] = data[i].substr(data[i].find(delimiter)+1,data[i].length() ); // Split string at =
    numberRolls = std::stoi(gameData.at("NumRolls"));       // set number of rolls (done for readability)
    die1 = new LoadedDie((std::stoi(gameData.at("LoadAmount"))),std::stoi(gameData.at("LoadedSide")), gameData.at("Die"),6);  // Create first die
    for(int i=3; i<7; i++) gameData[data[i].substr(0, data[i].find(delimiter))] = data[i].substr(data[i].find(delimiter)+1,data[i].length() );  // Split string at =
    die2 = new LoadedDie(std::stoi(gameData.at("LoadAmount")),std::stoi(gameData.at("LoadedSide")),gameData.at("Die"),6);     // Create second die
    diceFile.close();

}



