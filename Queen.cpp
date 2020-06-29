#include "Queen.h"

/*Randomises to decided which move method to use*/

int Queen::move(unsigned int width, unsigned int height) {
	int x_y_shift = (rand() % 2) + 1;
	if (x_y_shift == 1) {
		Rook::move( width, height);
	} 
	else {
		Bishop::move(width, height);
	}

	return 1;
}