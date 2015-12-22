/* 
 * File:   Die.cpp
 * Author: Terianne Bolding
 * 
 * Created on November 20, 2015, 11:28 AM
 */

#include "Die.h"

using namespace std;

Die::Die(string _identifier, int _numberSides): identifier(_identifier),numberSides(_numberSides){
    if (numberSides < 2) numberSides = 6;            // Reset number of sides to 6 so that other parts of the system know the size
    CalculateDieProbabilites();
}
Die::Die(): identifier("default"),numberSides(6){

    CalculateDieProbabilites();
}

Die::Die(const Die& orig): identifier(orig.identifier), numberSides(orig.numberSides){

    for(int i = 0; i <DieSides.size(); i++) this->DieSides.push_back(orig.DieSides[i]);
}

Die::~Die() {
}

int Die::Roll() const{
    float val = (rand()%10000)*.0001;
    double comparisonValue = 0.0;
    for(int i=0; i<DieSides.size(); i++){
        comparisonValue += DieSides[i];
        if(val < comparisonValue) return i+1;
    }
    return 0;
}

void Die::CalculateDieProbabilites(){
    for(int i = 0; i<numberSides; i++) DieSides.push_back (1/(double)numberSides);
}

int Die::GetNumberSides() const{return numberSides;}