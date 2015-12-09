/* 
 * File:   Die.cpp
 * Author: Terianne Bolding
 * 
 * Created on November 20, 2015, 11:28 AM
 */

#include "Die.h"
#include <iostream>

using namespace std;

Die::Die(string _identifier, int _numberSides): identifier(_identifier),numberSides(_numberSides){
    if (numberSides < 2){
        DieSides = new double[2];   // A Die must have 2 or more sides
        numberSides = 2;            // Reset number of sides to 2 so that other parts of the system know the size
    }
    else DieSides = new double[numberSides]();             
}
Die::Die(const Die& orig){
    this->identifier = orig.identifier;
    this->numberSides = orig.numberSides;
    this->DieSides = new double[this->numberSides];
    for(int i = 0; i <numberSides; i++) this->DieSides[i] = orig.DieSides[i];
}

Die::~Die() {
    if (DieSides != NULL) delete[] DieSides;    // Check if array has been initialized before trying to delete it
}

int Die::Roll() const{
    if (DieSides == NULL) return 0;
    float val = (rand()%10000)*.0001;
    double comparisonValue = 0.0;
    for(int i=0; i<numberSides; i++){
        comparisonValue += DieSides[i];
        if(val < comparisonValue) return i+1;
    }
    return 0;
}

void Die::CalculateDieProbabilites(){
    for(int i = 0; i<numberSides; i++) DieSides[i] = (1/(double)numberSides);
}

int Die::GetNumberSides() const{return numberSides;}