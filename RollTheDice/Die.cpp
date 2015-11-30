/* 
 * File:   Die.cpp
 * Author: Teri
 * 
 * Created on November 20, 2015, 11:28 AM
 */

#include "Die.h"
#include <iostream>
Die::Die():possibilites(6){}
Die::Die(int _possibilites, string _identifier):possibilites(_possibilites), identifier(_identifier){}
Die::Die(const Die& orig) {
}


Die::~Die() {
}


