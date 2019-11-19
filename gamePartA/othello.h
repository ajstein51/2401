/*
* AJ Stein
* This .h is for making the game board itself which is a two D array with a total of 16 spaces on the board
* The board game is Othello which focuses on a black and white piece for a two player game with a few rules built in
*/
#include <iostream>
#include <string>
using namespace std;

#include "colors.h"

#ifndef OTHELLO_H
#define OTHELLO_H

class space{
    public:
        space(){chip = 64;}
        // changes the piece 
        void flip();

        // getter for the space
        bool is_white()const;
        bool is_black()const;
        bool is_empty()const;

        // setter for the space
        void make_white();
        void make_black();
        void make_empty();
        
    private:
        int chip; // maybe 0 for black and 1 for white?
};
#endif