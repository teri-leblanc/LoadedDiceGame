/* 
 * File:   DiceGameStatistics.cpp
 * Author: Terianne Bolding
 * 
 * Created on November 30, 2015, 12:57 PM
 */

#include "DiceGameStatistics.h"
#include "LoadedDiceGame.h"
#include <math.h>
#include <random>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

DiceGameStatistics::DiceGameStatistics(const Die* _dice, int _numberRolls): dice(_dice), numberRolls(_numberRolls) {
    rollPercent = new int[dice->numberSides];
    for(int i=0; i<dice->numberSides;i++) rollPercent[i] = 0;
}

DiceGameStatistics::~DiceGameStatistics() {
    delete[] rollPercent;
}

void DiceGameStatistics::AddRoll(int side){
    rollPercent[side-1]++;
}

void DiceGameStatistics::CalculateRollPercent(){
    for(int i=0; i< dice->numberSides; i++)  {
        rollPercent[i] = ((double)rollPercent[i]/numberRolls)*100;
    }
}

void DiceGameStatistics::PrintRollStatistics(){
    cout<< "\n"<< dice->identifier<<" Statistics for "<<numberRolls<<" rolls: \n";
    for(int i=0; i<dice->numberSides; i++)  {
        cout<<"Side "<<i+1<<": "<<rollPercent[i]<<"%\n";
        
    }

}