#pragma once
#include <vector>
#include "Piece.h"
#include "Type.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include <Windows.h>
#include <time.h>

/* GameHandler - Responsible for tracing the game and keep track of the state of the game. Some Correctness testing is available for collision detection (uncomment the code in the .cpp file)
   the handler also handles the entity_list with contains all pieces of the board.
*/
class GameHandler {
	public:	
	GameHandler() {
		this->width = 100;
		this->height = 100;
	}
	
	GameHandler(unsigned int width, unsigned int height) {
		this->width = width;
		this->height = height; 
	}

	void set_is_playing(bool is_playing) {
		this->is_playing = is_playing;
	}

	int run();
	int update();
	int unit_testing();
	int add_unit(Type piece); 

private:
	unsigned int width, height; 
	std::vector<Piece*> entity_list;
	bool is_playing = true; 
	int index = 0;
	int q_count = 0, b_count = 0, r_count = 0; 
	int turn_count = 0;

};