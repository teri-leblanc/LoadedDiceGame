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
#include <vector>

class Die {
public:
    Die();
    Die(std::string _identifier, int _numberSides);
    Die(const Die& orig);
    int GetNumberSides() const;          // Getter for numberSides - this initial value should never change
    virtual ~Die();
    int Roll() const;
    virtual void CalculateDieProbabilites();
    std::string identifier;              // Name of the die
    std::vector<double> DieSides;                    // Array to hold weight of each side of the die
private:
    int numberSides;
};

#endif	/* DIE_H */

