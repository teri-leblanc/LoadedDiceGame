/* 
 * File:   RollDice.h
 * Author: Teri
 *
 * Created on November 21, 2015, 1:42 PM
 */

#ifndef ROLLDICE_H
#define	ROLLDICE_H
#include "Die.h"
#include "LoadedDie.h"
#include <map>
#include <cstdlib>
#include <string>
using namespace std;

class RollDice {
public:
    RollDice(string _fileName);
    RollDice(const RollDice& orig);
    virtual ~RollDice();
    int MakeRolls();
private:
    map<string,string> gameData;
    int numberRolls;
    int rollPercent[6] = {0,0,0,0,0,0};
    string fileName;
    Die* die1;
    Die* die2;
    void ReadData();
    int Roll(const Die* dice);

    void CreateDice();


};

#endif	/* ROLLDICE_H */

