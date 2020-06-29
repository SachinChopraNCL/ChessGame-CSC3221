#include "Bishop.h"
/* Solves Linear movement checking it the move is legal and re-rolling moves until a valid one is found */

int Bishop::move(unsigned int game_width, unsigned int game_height) {
	
	std::cout << "Old Position X: " << get_x() << " Y: " << get_y() << std::endl;


	bool shift_allowed = false;
	while (shift_allowed == false) {
		int x_y_shift = (rand() % 4) + 1;
		float shift_val = (float)((rand() % 5) + 1) / 10 ;
		std::cout << "x_y_shift: " << x_y_shift << " shift_val: " << shift_val << std::endl;

		switch (x_y_shift) {
		case(1): {
			shift_allowed = (get_x() - this->radius - shift_val < 0) || (get_y() + this->radius + shift_val > game_height) ? false : true;
			if (shift_allowed) {
				set_x(get_x() - shift_val);
				set_y(get_y() + shift_val);
			}}; break;
		case(2): {
			shift_allowed = (get_x() + this->radius + shift_val > game_width) || (get_y() + this->radius + shift_val > game_height) ? false : true;
			if (shift_allowed) {
				set_x(get_x() + shift_val);
				set_y(get_y() + shift_val);
			}}; break;
		case(3): {
			shift_allowed = (get_x() - this->radius - shift_val < 0) || (get_y() - this->radius - shift_val < 0) ? false : true;
			if (shift_allowed) {
				set_x(get_x() - shift_val);
				set_y(get_y() - shift_val);
			}}; break;
		case(4): {
			shift_allowed = (get_x() + this->radius + shift_val > game_width) || (get_y() - this->radius - shift_val < 0) ? false : true;
			if (shift_allowed) {
				set_x(get_x() + shift_val);
				set_y(get_y() - shift_val);
			}}; break;
		}
	}
	std::cout << " New Position X: " << get_x() << " Y: " << get_y() << std::endl;

	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	return 1;
}