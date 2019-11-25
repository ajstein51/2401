#include "move.h"
#include "colors.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

    // defualt
space::space(){
    piece = "|   |"; 
    chip = 64;
}

    // changes the piece 
void space::flip(){
    if(is_white()){
        piece = "| O |";
    }
    else if(is_black()){
        piece = "| X |";
    }
}

    // getter for the space
bool space::is_white()const{return (piece == "| X |");} // white is X
bool space::is_black()const{return (piece == "| O |");} // black is O
bool space::is_empty()const{return (piece == "|   |");}  // empty is blank

    // setter for the space
void space::make_white(){
    piece = "| X |";
}
void space::make_black(){
    piece = "| O |";
}
void space::make_empty(){
    piece = "|   |";
}
        
    // Color for the output here:
void space::color_output()const{
    if(piece == "|   |")
        cout << B_BLACK << BLUE << piece;
    else if(piece == "| X |")
        cout << B_BLACK << MAGENTA << piece;
    else
        cout << B_BLACK << CYAN << piece;

    cout << B_BLACK << WHITE;
}

string space::get_color()const{
    return piece;
}