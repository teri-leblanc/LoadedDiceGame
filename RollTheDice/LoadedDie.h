/* 
 * File:   LoadedDie.h
 * Author: Terianne Bolding
 *
 * Created on November 21, 2015, 1:03 PM
 * 
 * 
 * This class represents a die with a single loaded side. This die can also have greater or fewer
 */

#ifndef LOADEDDIE_H
#define	LOADEDDIE_H
#include "Die.h"

class LoadedDie: public Die {
    

public:
    LoadedDie();
    LoadedDie(const int _loadAmount, const int _loadedSide, const std::string &_identifier,const int _numberSides);
    LoadedDie(const LoadedDie& orig);
    virtual ~LoadedDie();
protected:
    int loadAmount;
    int loadedSide;
private:
    virtual void CalculateDieProbabilites();
};

#endif	/* LOADEDDIE_H */

