/* 
 * File:   DiceGameStatistics.cpp
 * Author: Terianne Bolding
 * 
 * Created on November 30, 2015, 12:57 PM
 */

#include "DiceGameStatistics.h"
#include <random>
#include <iostream>

using namespace std;

DiceGameStatistics::DiceGameStatistics(const Die &_dice): dice(_dice){
    rollPercent.assign(dice.GetNumberSides(),0);
}

DiceGameStatistics::~DiceGameStatistics() {

}

void DiceGameStatistics::AddRoll(int side){
    rollPercent[side-1]++;
    numberRolls++;
}

void DiceGameStatistics::CalculateRollPercent(){
    for(int i=0; i< dice.GetNumberSides(); i++)  {
        rollPercent.push_back(((double)rollPercent[i]/numberRolls)*100);
    }
}

void DiceGameStatistics::PrintRollStatistics(){
    cout<< "\n"<< dice.identifier<<" Statistics for "<<numberRolls<<" rolls: \n";
    for(int i=0; i<dice.GetNumberSides(); i++)  {
        cout<<"Side "<<i+1<<": "<<rollPercent[i]<<"%\n";
        
    }

}