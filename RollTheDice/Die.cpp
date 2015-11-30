/* 
 * File:   Die.cpp
 * Author: Terianne Bolding
 * 
 * Created on November 20, 2015, 11:28 AM
 */

#include "Die.h"
#include <iostream>
Die::Die():possibilites(6){}
Die::Die(int _possibilites, string _identifier, int _numberSides):possibilites(_possibilites), identifier(_identifier),numberSides(_numberSides){
    DieSides = new double[numberSides];
    if (_numberSides <2) numberSides = 2;           // A Die must have 2 or more sides
    
}
Die::Die(const Die& orig) {
    delete DieSides;
}
Die::~Die() {
}


