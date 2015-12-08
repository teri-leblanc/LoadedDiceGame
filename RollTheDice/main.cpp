/* 
 * File:   main.cpp
 * Author: Terianne LeBlanc Bolding
 *
 * Created on November 20, 2015, 11:23 AM
 * 
 * Write a program using C++ to do the following:
Simulate the rolling of two 6-sided dice. Each die will be loaded so that one side comes up more frequently than the others.
The program will need to:
1. Open a file and read key, values pairs (i.e. key=value)
The keys will be, number of rolls to execute, the die identifier, which side of the dice is loaded and by how much
that side is loaded.
2. Execute each throw of the dice and print out each die's result.
3. Summarize the results of each dice and the percentages that each side came up.
So as an example the parameter file might look like this:
     NumRolls=100
     Die=Die1
     LoadedSide=3
     LoadAmount=2
     Die=Die2
     LoadedSide=6
     LoadAmount=10
The LoadAmount would be the factor that that side is likely to occur so Die1, Side 3
would be twice as likely as the other sides to appear and Die2, Side 6 would be 10 times as likely.
And the results would show each throw:
     Throw 1: Die1 rolled a 3, Die2 rolled a 6
     Throw 2: Die1 rolled a 2, Die2 rolled a 2
     Throw 3: Die1 rolled a 3, Die2 rolled a 6
     Throw 4: Die1 rolled a 1, Die2 rolled a 6
     Throw 5: Die1 rolled a 6, Die2 rolled a 6
     .
. .
And then at the end a summary:
     Die1 Statistics for 100 rolls:
     Side 1: 13%
     Side 2: 15%
     Side 3: 30%
     Side 4: 14%
     Side 5: 16%
     Side 6: 12%
     Die2 Statistics for 100 rolls:
     Side 1: 8%
     Side 2: 6%
     Side 3: 6%
     Side 4: 7%
     Side 5: 9%
     Side 6: 64%
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * NOTES:: 
 * 
 * -----Die
 * I created this project with the idea of creating a dice game. The Die abstraction could be used to implement any
 * form of dice. 
 * Not limited to 6 sides
 * 
 * -----LoadedDice
 * Inherits Die and adds fields to keep track of the loaded side of the die. It also calculates the weight of each side
 * Not limited to 6 sides
 * 
 * -----DiceGameStatistics
 * Keeps track of the number of times each side of a specific side lands up and calculates the percentages based on a number of rolls
 * Not limited to 6 sides
 * 
 * -----LoadedDiceGame
 * This game is limited to 2, 6 sided dice. This class takes a filename and reads data from that file. It then rolls the two dice
 * a given number of times and prints out each throw. It then prints out the statistical data about the overall rolls.
 * 
 */

#include <cstdlib>
#include "Die.h"
#include "LoadedDie.h"
#include "LoadedDiceGame.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    LoadedDiceGame dice = LoadedDiceGame("diceData.txt");
    dice.MakeRolls();

    return 0;
}

