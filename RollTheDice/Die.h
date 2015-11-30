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
    friend class RollDice;
protected:
    string identifier;
    virtual void calculateDieProbabilites() = 0;
public:
    int possibilites;
    double DieSides[6];
    Die();
    Die(const Die& orig);
    Die(int _possibilites, string _identifier);
    virtual ~Die();
    


};

#endif	/* DIE_H */

