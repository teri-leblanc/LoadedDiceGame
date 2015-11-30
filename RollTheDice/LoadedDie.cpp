/* 
 * File:   LoadedDie.cpp
 * Author: Teri
 * 
 * Created on November 21, 2015, 1:03 PM
 */

#include "LoadedDie.h"
#include <iostream>
#include <stdlib.h>
LoadedDie::LoadedDie() {
}
LoadedDie::LoadedDie(const int _loadAmount, const int _loadedSide, const string _identifier, const int _numberSides):loadAmount(_loadAmount),loadedSide(_loadedSide), Die((_loadAmount+_numberSides),_identifier, _numberSides) {
    calculateDieProbabilites();
}
LoadedDie::LoadedDie(const LoadedDie& orig) {
}

LoadedDie::~LoadedDie() {

}

void LoadedDie::calculateDieProbabilites(){
    for(int i=0; i<6; i++)  {
        if(loadedSide == (i+1)){
            Die::DieSides[i] = ((double)loadAmount/(double)(Die::possibilites)); // Loaded side has a higher probability
        }
        else
            Die::DieSides[i] = ((double)1/(double)(Die::possibilites));          // Non loaded sides have same probability
    }
}
