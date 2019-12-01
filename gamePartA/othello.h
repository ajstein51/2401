#include <string>
#include "move.h"
#include "game.h"
#include "colors.h"
using namespace std;

class othello:public main_savitch_14::game{
	public:
		othello(){f_move = 1;}
		
		// displays the board~~
		void display_status()const;

		// this restarts the entire game, starting from the beginning
		void restart();

		// gives a true or false (1 or 0) if the move is legal to do, should be called every move?
		bool is_legal(const string& move);
/*
		// These functions server is legal:
		bool look_up(const string& move);
		bool look_down(const string& move);
		bool look_left(const string& move);
		bool look_right(const string& move);
		bool top_left(const string& move);
		bool top_right(const string& move);
		bool bottom_left(const string& move);
		bool bottom_right(const string& move);
*/
		
		// makes a move and checks to see if its legal using the is_legal function written above
		void make_move(const string& move);
	
	// to avoid errors
		bool is_game_over()const;
		void victory();
		void compute_moves(std::queue<std::string>& moves)const;
		
    	int evaluate()const;

	private:
		space board[8][8];
		int f_move;
		string move;
};
