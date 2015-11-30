/* 
 * File:   RollDice.h
 * Author: Teri
 *
 * Created on November 21, 2015, 1:42 PM
 * 
 * 
 * This class is a loaded dice game meant to roll two, 6 sided dies a given number of times depending upon 
 * data read from a file.
 */




#ifndef ROLLDICE_H
#define	ROLLDICE_H
#include "Die.h"
#include "LoadedDie.h"
#include "DiceGameStatistics.h"
#include <map>
#include <cstdlib>
#include <string>
using namespace std;

class LoadedDiceGame {
public:
    LoadedDiceGame(string _fileName);
    LoadedDiceGame(const LoadedDiceGame& orig);
    virtual ~LoadedDiceGame();
    void MakeRolls();                           // Player calls this to play the game. Makes all rolls and prints out statistical data
private:
    map<string,string> gameData;                // Data structure to hold data from file
    int numberRolls;                            // Number of times to roll dice
    DiceGameStatistics* statsDie1;              // Statistical object for die1
    DiceGameStatistics* statsDie2;              // Statistical object for die2
    string fileName;                            // file to open and read data from
    Die* die1;                                  // Physical representation of die1
    Die* die2;                                  // Physical representation of die2
    void ReadData();                            // Reads data from fileName and puts it in gameData map
    int Roll(const Die* dice);                  // Rolls an individual die once
};

#endif	/* ROLLDICE_H */

