/* 
 * File:   DiceGameStatistics.h
 * Author: Terianne Bolding
 *
 * Created on November 30, 2015, 12:57 PM
 * 
 * 
 * 
 * This class is meant to hold and calculate statistical roll data from any dice game.
 */

#ifndef DICEGAMESTATISTICS_H
#define	DICEGAMESTATISTICS_H
#include "Die.h"
#include "LoadedDie.h"
#include <cstdlib>

class DiceGameStatistics {
public:
    DiceGameStatistics(const Die* _dice, int _numberRolls);
    DiceGameStatistics(const DiceGameStatistics& orig);
    virtual ~DiceGameStatistics();
    void AddRoll(int side);
    void CalculateRollPercent();
    void PrintRollStatistics();
private:
    const Die* dice;                                    // Die calculating data for
    int* rollPercent;                                   // Array to hold the amount of times a side has been rolled
    int numberRolls;                                    // Number of rolls in the game

};

#endif	/* DICEGAMESTATISTICS_H */

