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
LoadedDie::LoadedDie(const int _loadAmount, const int _loadedSide, const string _identifier):loadAmount(_loadAmount),loadedSide(_loadedSide), Die((_loadAmount+5),_identifier) {
    calculateDieProbabilites();
}
LoadedDie::LoadedDie(const LoadedDie& orig) {
}

LoadedDie::~LoadedDie() {

}

void LoadedDie::calculateDieProbabilites(){
    for(int i=0; i<6; i++)  {
        if(loadedSide == (i+1)){
            Die::DieSides[i] = ((double)loadAmount/(double)(Die::possibilites));
        }
        else
            Die::DieSides[i] = ((double)1/(double)(Die::possibilites));
    }
}
