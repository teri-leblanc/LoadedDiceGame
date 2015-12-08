/* 
 * File:   Die.cpp
 * Author: Terianne Bolding
 * 
 * Created on November 20, 2015, 11:28 AM
 */

#include "Die.h"
#include <iostream>

using namespace std;

Die::Die():possibilites(0),identifier(""),numberSides(0), DieSides(NULL){};//default die will be 6 sided and unloaded
Die::Die(int _possibilites, string _identifier, int _numberSides):possibilites(_possibilites), identifier(_identifier),numberSides(_numberSides){
    if (numberSides < 2){
        DieSides = new double[2];   // A Die must have 2 or more sides
        numberSides = 2;            // Reset number of sides to 2 so that other parts of the system know the size
    }
    else DieSides = new double[numberSides];             
    
}

Die::~Die() {
    delete[] DieSides;
}


