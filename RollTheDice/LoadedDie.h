/* 
 * File:   LoadedDie.h
 * Author: Teri
 *
 * Created on November 21, 2015, 1:03 PM
 */

#ifndef LOADEDDIE_H
#define	LOADEDDIE_H
#include "Die.h"

class LoadedDie: public Die {
    
protected:
    int loadAmount;
    int loadedSide;
public:
    LoadedDie();
    LoadedDie(const int _loadAmount, const int _loadedSide, const string _identifier);
    LoadedDie(const LoadedDie& orig);
    virtual void calculateDieProbabilites();
    virtual ~LoadedDie();


};

#endif	/* LOADEDDIE_H */

