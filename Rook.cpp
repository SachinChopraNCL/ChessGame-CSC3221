#include "Rook.h"
#include <time.h>
#include <stdlib.h>


/* Solves diagonal movement checking it the move is legal and re-rolling moves until a valid one is found */
int Rook::move (unsigned int game_width, unsigned int game_height) {
	bool shift_allowed = false;
	std::cout << "Old Position X: " << get_x() << " Y: " << get_y() << std::endl;
	while (shift_allowed == false) {
		int x_y_shift = (rand() % 2) + 1;
		int dir = (rand() % 2) + 1;
		float  shift_val = (float)((rand() % 5) + 1) / 10;
	std::cout << "x_y_shift: " << x_y_shift << " dir: " << dir << " shift_val: " << shift_val << std::endl;

		if (x_y_shift == 1) {
			if (dir == 1) {
				shift_allowed = shift_val + get_x() + this->width > game_width ? false : true;
			}
			else {
				shift_allowed = get_x() - this->width - shift_val < 0 ? false : true;
			}

			if (shift_allowed)
				dir == 1 ? set_x(get_x() + shift_val) : set_x(get_x() - shift_val);
		}
		else {
			if (dir == 1) {
				shift_allowed = shift_val + get_y() + this->height > game_height ? false : true;
			}
			else {
				shift_allowed = get_y() - this->height - shift_val < 0 ? false : true;
			}

			if (shift_allowed)
				dir == 1 ? set_y(get_y() + shift_val) : set_y(get_y() - shift_val);
		}
	}
	std::cout << "New Position X: " << get_x() << " Y: " << get_y() << std::endl;
	
	return 1;
}