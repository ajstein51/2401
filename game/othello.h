/*
*
*
*/
#include <iostream>
#include <string>
using namespace std;

#ifndef OTHELLO_H
#define OTHELLO_H

class space{
    public:
        space(){piece = 0;}
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
        int piece;
};
#endif