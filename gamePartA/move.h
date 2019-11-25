/*
* AJ Stein
* This .h is for making the game board itself which is a two D array with a total of 16 spaces on the board
* The board game is Othello which focuses on a black and white piece for a two player game with a few rules built in
*/
#include <iostream>
#include <string>
using namespace std;

#include "colors.h"

#ifndef MOVE_H
#define MOVE_H

class space{
    public:
        space(){piece = "|   |"; chip = 64;}
        // changes the piece 
        void flip(){
            if(is_white()){
                piece = "| O |";
            }
            else if(is_black()){
                piece = "| X |";
            }
        }

        // getter for the space
        bool is_white()const{return (piece == "| X |");} // white is X
        bool is_black()const{return (piece == "| O |");} // black is O
        bool is_empty()const{return (piece == "|   |");}  // empty is blank

        // setter for the space
        void make_white(){piece = "| X |";}
        void make_black(){piece = "| O |";}
        void make_empty(){piece = "|   |";}
        
    private:
        int chip; // maybe 0 for black and 1 for white?
        string piece;
};
#endif