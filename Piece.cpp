#include "Piece.h"
#include <math.h>
/* All types of collision are considered. Checking the piece is not dead and checking the collision between the current piece and all other pieces.*/

int Piece::check_collision(std::vector<Piece*> &pieces) {

	Shape current_shape = this->piece_shape;
	int index = 0;
	for (Piece* piece : pieces) {
		bool captured = false;
		if (piece && piece->index != this->index) {
			Shape new_shape = piece->piece_shape;

			if (current_shape == SQUARE && new_shape == SQUARE) {
				if (this->x <= piece->x + piece->radius * 2  && this->x + this->radius *2 >= piece->x && this->y <= piece->y + piece->radius *2  && this->y + this->radius * 2 >= piece->y) {
					captured = true;
				}
			}
			else if (current_shape == CIRCLE && new_shape == CIRCLE) {
				float x_dif = abs(this->x - piece->x);
				float y_dif = abs(this->y - piece->y);
				float distance = sqrt(x_dif * x_dif + y_dif * y_dif);
				if (distance <= radius * 2) {
					captured = true;
				}
			}
			else if (current_shape == CIRCLE && new_shape == SQUARE) {

				float x_dif = abs(this->x - piece->x);
				float y_dif = abs(this->y - piece->y);

				if ((x_dif >= piece->radius + this->radius || y_dif >= piece->radius + this->radius) == false) {
					if (x_dif <= piece->radius || y_dif <= piece->radius) {
						captured = true;
					}
				}
				float corner_val = sqrt(std::pow(abs(x_dif - piece->radius), 2) + std::pow(abs(y_dif - piece->radius), 2));

				if (corner_val <= this->radius) {
					captured = true;
				}
			}
			else if (current_shape == SQUARE && new_shape == CIRCLE) {
				float x_dif = abs(this->x - piece->x);
				float y_dif = abs(this->y - piece->y);
				
				if ((x_dif >= piece->radius + this->radius || y_dif >= piece->radius + this->radius) == false) {
					if (x_dif <= piece->radius || y_dif <= piece->radius) {
						captured = true;
					}
				}

				float corner_val = sqrt(std::pow(abs(x_dif - this->radius), 2) + std::pow(abs(y_dif - this->radius), 2));

				if (corner_val <= piece->radius) {
					captured = true;
				}

			}
		}
		if (captured == true) {
			std::cout << "--------------------------------------------------------------------------------" << std::endl;

			std::cout << "Collision Occured between Piece index " << this->get_index() << " & " << piece->get_index() << "(" << this->get_x() << "," << this->get_y() << ")"
				"(" << piece->get_x() << "," << piece->get_y() << ")" << std::endl;
			this->x = piece->x; /* Updates piece position to the captured piece */
			this->y = piece->y;
			return index;
		}
		index++;
	}

	return -1;
}



