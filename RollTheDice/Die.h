/* 
 * File:   Die.h
 * Author: Terianne Bolding
 *
 * Created on November 20, 2015, 11:28 AM
 */

#ifndef DIE_H
#define	DIE_H
#include <cstdlib>
#include <string>
using namespace std;

class Die {
protected:
    int possibilites;               // Number of statistical possibilities for the dies sides
    
    virtual void calculateDieProbabilites() = 0;
public:
    string identifier;              // Name of the die
    int numberSides;                // Number of sides the die has, certain die can contain greater then 6 sides
    double* DieSides;               // Array to hold weight of each side of the die
    Die();
    Die(const Die& orig);
    Die(int _possibilites, string _identifier, int _numberSides);
    virtual ~Die();
};

#endif	/* DIE_H */

