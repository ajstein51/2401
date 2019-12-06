#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"     // Provides definition of game class
#include "colors.h"   // Porivdes definition of color class
#include "move.h"     // Provides definition of the space class
#include "othello.h"
using namespace std;

/************************************************
Notes:
    - White is moving first for some reason, then black is going. Using the black is_legal for white moves, while black is still using black


************************************************/
// displays the board at its current status
void othello::display_status()const{
	char row[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	cout << "    1    2    3    4    5    6    7    8  " << endl;
	for(int i = 0; i < 8; ++i){
		cout << row[i] << " ";
		for(int j = 0; j < 8; ++j){
			board[i][j].color_output();
		}
		cout << "\n";
	}
}

// resets the board
void othello::restart(){
	game::restart();
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			board[i][j].make_empty();
		}
	}
	board[3][3].make_white();
	board[4][4].make_white();
	board[3][4].make_black();
	board[4][3].make_black();
    game::restart();
}

bool othello::is_legal(const string& move)const{ // The spacing on this function is kinda messed up
	int x, y;
	x = (int)(toupper(move[0]) - 'A'); // columns
	y = (int)(move[1] - '1');         // rows
	
	if(x < 8 && x >= 0 && y < 8 && y >= 0){ // checking to see if its on the board
//************************************************
        //if(game::next_mover() == HUMAN){ // changed to pc // changed
        if(move_number % 2 != 0){
            if(board[x-1][y].is_white() == true){
                for(int i = x-1; i >= 0; i--){ 
                    // keeps checking the entire board in that direction until it hits an empty space or black
                    if(board[i][y].is_empty() == true)
                        break;
                    if(board[i][y].is_black() == true)
                        return true;
                }
            }
        
//************************************************
		if(board[x+1][y].is_white() == true){
            for(int i = x + 1; i < 8; i++){
                if(board[i][y].is_empty() == true)
                    break;
            if(board[i][y].is_black() == true)
                return true;
            }
        }
//************************************************
        if(board[x][y-1].is_white() == true){
            for(int i = y -1; i >= 0; i--){
                if(board[x][i].is_empty() == true)
                    break;
            if(board[x][i].is_black() == true)
                return true;
            }
        }
//************************************************
        if(board[x][y+1].is_white() == true){
            for(int i = y + 1; i < 8; i++){
                if(board[x][i].is_empty() == true)
                    return false;
                if(board[x][i].is_black() == true)
                    return true;
            }
        }
//************************************************
        if(board[x-1][y-1].is_white() == true){
            for(int i = x - 1; i >= 0; i--){
                for(int j = y - 1;j >= 0; j--){
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_black() == true)
                        return true;
                }
            }
        }
//************************************************
        if(board[x-1][y+1].is_white() == true){
            for(int i = x - 1; i >= 0; i--){
                for(int j = y + 1;j < 8; j++){
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_black() == true)
                        return true;
                }
            }
        }
//************************************************
        if(board[x+1][y-1].is_white() == true){
            for(int i = x + 1; i < 8; i++){
                for(int j = y - 1;j >= 0; j--){    
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_black() == true)
                        return true;
                }
            }
        }
//************************************************
        if(board[x+1][y+1].is_white() == true){
            for(int i = x + 1; i < 8; i++){
                for(int j = y + 1;j < 8; j++){
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_black() == true)
                        return true;
                }
            }
        }
//************************************************
    
    else
        return false;
    }
//************************************************
    //else if(game::next_mover() == COMPUTER){ // changed to human
    else{
        if(board[x-1][y].is_black() == true){
            for(int i = x - 1; i >= 0; i--){
                if(board[i][y].is_empty() == true)
                    break;
                if(board[i][y].is_white() == true)
                    return true; 
            }
        }
//************************************************
        if(board[x+1][y].is_black() == true){
            for(int i = x +1; i < 8; i++){
                if(board[i][y].is_empty() == true)
                    break;
                if(board[i][y].is_white() == true)
                    return true;
            }
        }
//************************************************
        if(board[y-1][y-1].is_black() == true){
            for(int i = x - 1; i >= 0; i--){
                for(int j = y - 1;j >= 0; j--){
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_white() == true)
                        return true; 
                }
            }
        }
//************************************************
        if(board[x-1][y+1].is_black() == true){
            for(int i = x - 1; i >= 0; i--){
                for(int j = y + 1; j < 8; j++){
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_white() == true)
                        return true;
                }
            }
        }
//************************************************
        if(board[x+1][y-1].is_black() == true){
            for(int i = x + 1; i < 8; i++){
                for(int j = y - 1; j >= 0; j--){
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_white() == true)
                        return true;
                }
            }
        }
//************************************************
        if(board[x+1][y+1].is_black() == true){
            for(int i = x + 1; i < 8; i++){
                for(int j = y+1; j < 8; j++){
                    if(board[i][j].is_empty() == true)
                        break;
                    if(board[i][j].is_white() == true)
                        return true;
                }
            }
        }
//************************************************
        if(board[x][y-1].is_black() == true){
            for(int i = x -1; i >= 0; --i){
                if(board[y][i].is_empty() == true)
                    break;
                if(board[x][i].is_white() == true)
                    return true;
            }
        }
//************************************************
        if(board[x][y+1].is_black() == true){
            for(int i = y + 1; i < 8; ++i){
                if(board[x][i].is_empty() == true)
                    return false;
                if(board[x][i].is_white() == true)
                    return true;
            }
        }
//************************************************        
        else
            return false;
        } // end of else if (next_mover() == COMPUTER)
    } // end of if in board parameters 

    

}


void othello::make_move(const string& move){ 
	int x, y;
    if(is_legal(move)){
        x = (int)(toupper(move[0])-'A');
        y = (int)(move[1]-'1');

        //if(game::next_mover() == HUMAN){
        if(move_number % 2 != 0){
            board[x][y].make_black();
//************************************************
        if(board[x][y].is_black() && board[x][y+1].is_white()){
            for(int i = y+1; board[x][i].is_white(); i++)
                board[x][i].flip();
        }
//************************************************
        else if(board[x][y].is_black() && board[x][y-1].is_white()){
            for(int i=y-1; board[x][i].is_white(); i--)
                board[x][i].flip();
        }
//************************************************
        else if(board[x][y].is_black() && board[x-1][y].is_white()){
            for(int i=x-1; board[i][y].is_white(); i--)
                board[i][y].flip();
        }
//************************************************
        else if(board[x][y].is_black() && board[x+1][y].is_white()){
            for(int i=x+1; board[i][y].is_white(); i++)
                board[i][y].flip();
        }
//************************************************
        else if(board[x][y].is_black() && board[x+1][y+1].is_white()){
            for(int i=x+1; i<8; i++){
                for(int j = y+1; j<8; j++){
                    if(board[i][j].is_white() == true)
                        board[i][j].flip();
                }
            }
        }
//************************************************
        else if(board[x][y].is_black() && board[x+1][y-1].is_white()){
            for(int i = x+1; i<8; i++){
                for(int j = y-1; j >= 0;j--){ 
                    if(board[i][j].is_white() == true)
                        board[i][j].flip();
                }            
            }
        }
//************************************************
       else if(board[x][y].is_black() && board[x-1][y+1].is_white()){
            for(int i = x-1; i >= 0; i--){ 
                for(int j = y+1; j<8;j++){
                    if(board[i][j].is_white() == true)
                        board[i][j].flip();
                }
            }
       }
//************************************************
        else if(board[x][y].is_black() && board[x-1][y-1].is_white()){
            for(int i = x-1; i >= 0; i--){ 
                for(int j = y-1;j >= 0;j--){ 
                    if(board[i][j].is_white() == true)
                        board[i][j].flip();
                }
            }
        }
    }
//************************************************
    //else if(game::next_mover() == COMPUTER){ // pc
    else{
        board[x][y].make_white();
//************************************************
        if(board[x][y].is_white() && board[x][y+1].is_black()){
            for(int i=y+1; board[x][i].is_black(); i++)
                board[x][i].flip();
        }
//************************************************
        else if(board[x][y].is_white() && board[x][y-1].is_black()){
            for(int i=y-1; board[x][i].is_black(); i--)
                board[x][i].flip();
        }
//************************************************
        else if(board[x][y].is_white() && board[x-1][y].is_black()){
            for(int i=x-1; board[i][y].is_black(); i--)
                board[i][y].flip();
        }
//************************************************
        else if(board[x][y].is_white() && board[x+1][y].is_black()){
            for(int i=x+1; board[i][y].is_black(); i++)
                board[i][y].flip();
        }
//************************************************
        else if(board[x][y].is_white() && board[x+1][y+1].is_black()){
            for(int i = x+1; i<8; i++){
                for(int j = y+1; j<8; j++){
                    if(board[i][j].is_black() == true)
                        board[i][j].flip();
                }
            }
        }
//************************************************
        else if(board[x][y].is_white() && board[x+1][y-1].is_black()){
            for(int i = x+1; i<8; i++){
                for(int j = y-1; j >= 0;j--){ 
                    if(board[i][j].is_black() == true)
                        board[i][j].flip();
                }
            }
        }
//************************************************
        else if(board[x][y].is_white() && board[x-1][y+1].is_black()){
            for(int i = x-1; i >= 0; i--){ 
                for(int j = y+1; j<8; j++){
                    if(board[i][j].is_black() == true)
                        board[i][j].flip();
                }
            }
        }
//************************************************
        else if(board[x][y].is_white() && board[x-1][y-1].is_black()){
            for(int i = x-1; i >= 0; i--){ 
                for(int j = y-1; j >= 0; j--){ 
                    if(board[i][j].is_black() == true)
                        board[i][j].flip();
                }
            }
        }
    }
//************************************************
    } // end of the if(is_legal())
    move_number++; // for part
    game::make_move(move);
} // end of function

// counts the pieces of each tile then checks to see which won or if there was a tie
void othello::winning(){ // double for loop to go through board and an incrementer 
    int white_counter = 0, black_counter = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j].is_white())
                white_counter++;
            if(board[i][j].is_black())
                black_counter++;
        }
    }
    if(black_counter > white_counter)
        cout << "\nBlack is the winner!" << endl;
    if(white_counter > black_counter)
        cout << "\nWhite is the winner!" << endl;
    if(black_counter == white_counter)
        cout << "\nIt is a tie, play again!" << endl;
}

// checks to see if the game is over (if it equals 64 then no more space on board)
bool othello::is_game_over()const{ // broke
	if(moves_completed() == 64)
        return true;
    else
        return false;
    
}

// computer moves stuff:
// puts the board into a integer standing for the AI if its doing well or not, the book says not to look into the future or anything just return a number status
int othello::evaluate()const{
	int good = 0, bad = 0, decision = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j].is_white() == true)
                good++;
            if(board[i][j].is_black() == true)
                bad++;
        }
    }
    decision = good - bad;
    return decision;
}

// The  function  examines  the  current  status  of  the  game  and  determines  whatmoves are currently legal. 
// All these legal moves are then placed into the queue.
void othello::compute_moves(std::queue<std::string>& moves)const{
    string tmp;

    for(char x = 'A'; x <= 'H'; x++){
        for(char y = '1'; y <= '8'; y++){
            tmp[0] = x;
            tmp[1] = y;
            if(is_legal(tmp))
                moves.push(tmp);
        }
    }
}

main_savitch_14::game* othello::clone()const{
    return new othello(*this);
}