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

class Die {
public:
    std::string identifier;              // Name of the die
    int numberSides;                     // Number of sides the die has, certain die can contain greater then 6 sides
    double* DieSides;                    // Array to hold weight of each side of the die
    Die();
    Die(int _possibilites, std::string _identifier, int _numberSides);
    Die(const Die& orig);
    virtual ~Die();
    virtual int Roll() const;
protected:
    int possibilites;                   // Number of statistical possibilities for the dies sides
    virtual void CalculateDieProbabilites() = 0;

};

#endif	/* DIE_H */

