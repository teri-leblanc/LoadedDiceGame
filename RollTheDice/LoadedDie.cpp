/* 
 * File:   LoadedDie.cpp
 * Author: Terianne Boldin
 * 
 * Created on November 21, 2015, 1:03 PM
 */

#include "LoadedDie.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

LoadedDie::LoadedDie():loadAmount(1),loadedSide(1),Die(){};
LoadedDie::LoadedDie(const int _loadAmount, const int _loadedSide, const string &_identifier, const int _numberSides):loadAmount(_loadAmount),loadedSide(_loadedSide), Die((_loadAmount+(_numberSides-1)),_identifier, _numberSides) {
    CalculateDieProbabilites();
}

LoadedDie::~LoadedDie() {
}
void LoadedDie::CalculateDieProbabilites(){
    for(int i=0; i<numberSides; i++)  {
        if(loadedSide == (i+1)){
            Die::DieSides[i] = ((double)loadAmount/(double)(Die::possibilites)); // Loaded side has a higher probability
        }
        else
            Die::DieSides[i] = ((double)1/(double)(Die::possibilites));          // Non loaded sides have same probability
    }
}
