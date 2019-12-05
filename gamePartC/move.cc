#include "move.h"
#include "colors.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

    // defualt
space::space(){
    piece = '_'; 
    chip = 64;
}

    // changes the piece 
void space::flip(){
    if(piece == 'B')
        piece = 'W';
    else if(piece == 'W')
        piece = 'B';
}

    // getter for the space
bool space::is_white()const{return (piece == 'W');} // white is X
bool space::is_black()const{return (piece == 'B');} // black is O
bool space::is_empty()const{return (piece == '_');}  // empty is blank

    // setter for the space
void space::make_white(){
    piece = 'W';
}
void space::make_black(){
    piece = 'B';
}
void space::make_empty(){
    piece = '_';
}
        
    // Color for the output here:
void space::color_output()const{
    if(piece == '_')
        cout << B_BLACK << BLUE << "| " << piece << " |";
    else if(piece == 'W')
        cout << B_BLACK << MAGENTA << "| " << piece << " |";
    else
        cout << B_BLACK << CYAN << "| " << piece << " |";

    cout << B_BLACK << WHITE;
}

char space::get_color()const{
    return piece;
}