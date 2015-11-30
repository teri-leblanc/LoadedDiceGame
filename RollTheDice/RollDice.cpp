/* 
 * File:   RollDice.cpp
 * Author: Teri
 * 
 * Created on November 21, 2015, 1:42 PM
 */

#include "RollDice.h"
#include <math.h>
#include <random>
#include <iostream>
#include <fstream>
#include <stdlib.h>
RollDice::RollDice(string _fileName) : fileName(_fileName) {
    ReadData();

}

RollDice::RollDice(const RollDice& orig) {
}

RollDice::~RollDice(){
    delete die1;
    delete die2;
}

int RollDice::MakeRolls(){

         srand (static_cast <unsigned> (time(0)));
    for(int i =0; i < std::stoi(gameData.at("NumRolls")); i++){
        cout<<"Throw "<<i<<": "<<die1->identifier<<" rolled a "<<Roll(die1)<<", "<<die2->identifier<<" rolled a "<<Roll(die2) <<"\n";
    
    }
    for(int i=0; i<6; i++)  {
        cout<< rollPercent[i]<<"\n";
    }
return 0;
}
    
int RollDice::Roll(const Die * dice){

        float val = (rand()%10000)*.0001;

        int side;
    if (val < dice->DieSides[0]) 
        side = 1;
    else if (val < dice->DieSides[0]+dice->DieSides[1])
        side = 2;
    else if (val < dice->DieSides[0]+dice->DieSides[1]+dice->DieSides[2]) 
        side = 3;
    else if (val < dice->DieSides[0]+dice->DieSides[1]+dice->DieSides[2]+dice->DieSides[3]) 
        side = 4;
    else if (val < dice->DieSides[0]+dice->DieSides[1]+dice->DieSides[2]+dice->DieSides[3]+dice->DieSides[4])
        side = 5;
    else 
        side = 6;
    
    rollPercent[side-1]++;
    return side;
    
    

}

void RollDice::ReadData(){
    ifstream diceFile;
    string s  = "something";
    string data[7];
    int numRolls = 0;
    diceFile.open(fileName);
    int count = 0;
     if (diceFile.is_open()) {
        while (count < 8) {
             diceFile >> data[count];
            count++;
        }
    }

    string delimiter = "=";
    for(int i=0; i<4; i++){
        gameData[data[i].substr(0, data[i].find(delimiter))] = data[i].substr(data[i].find(delimiter)+1,data[i].length() );
    }
    die1 = new LoadedDie((std::stoi(gameData.at("LoadAmount"))),std::stoi(gameData.at("LoadedSide")), gameData.at("Die"));
    for(int i=3; i<7; i++){
       gameData[data[i].substr(0, data[i].find(delimiter))] = data[i].substr(data[i].find(delimiter)+1,data[i].length() );
    }
    die2 = new LoadedDie(std::stoi(gameData.at("LoadAmount")),std::stoi(gameData.at("LoadedSide")),gameData.at("Die"));
    diceFile.close();

}