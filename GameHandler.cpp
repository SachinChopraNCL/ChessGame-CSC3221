#include "GameHandler.h"
#define TURNMAX 100
#define SLEEP 500

/* Method starts the game, calls srand to initalise random generation. Keeps gaming for until TURNMAX is met or only one piece is left. */
int GameHandler::run() {
	while (is_playing == true) {
		update();
		Sleep(SLEEP);
		if (turn_count == TURNMAX)
			is_playing = false;
		turn_count++;
	}
	std::cout << "GAME OVER" << std::endl;
	std::cout << "Rook Captures: " << r_count << "\n"<<  "Bishop Captures: " << b_count << "\n" << "Queen Captures: " << q_count;

	return 1;
}

/* Update handles the majority of game logic. Firstly checking if the game is a valid state, then checks collisions, resolving them & keeping a score of all piece types*/
int GameHandler::update() {
	if (is_playing == true) {
		for (Piece* piece : entity_list) {
			int col = -1;
			if (piece) {
				std::cout << "Piece " << piece->get_index() << " Move" << std::endl;
				piece->move(this->width, this->height);
				col = piece->check_collision(entity_list);
			}
			if (col != -1) {
				std::cout << "Piece " << entity_list.at(col)->get_index() << " Has been Removed from the Game" << std::endl;
				switch (piece->get_type()) {
					case(ROOK):r_count++; break;
					case(BISHOP):b_count++; break;
					case(QUEEN):q_count++; break;
				}
				
				
				delete entity_list.at(col); /* As we need to store pointers to pieces, deleting each piece as it is destroyed is needed */
				
			    entity_list.at(col) = nullptr; /* Avoids dangling pointers */
			}
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
		}

		/* Truncates the Vector to remove all dead pieces*/
		for (int i = 0; i < entity_list.size(); i++) {
			if (entity_list.at(i) == nullptr) {
				entity_list.erase(entity_list.begin() + i);
			}
		}
	}
	if (entity_list.size() <= 1) {
		is_playing = false;
	}
	
	return 1;
}

/* Adds a unit at a randomj place on the board */
int GameHandler::add_unit(Type piece) {

	int x = (rand() % (this->width - 1)) + 1;
	int y = (rand() % (this->height - 1)) + 1;


	switch (piece) {
		case ROOK: {entity_list.push_back(new Rook(index, x, y)); std::cout << "ADDED A ROOK WITH ID: " << index << std::endl; }; break;
		case BISHOP: {entity_list.push_back(new Bishop(index, x, y)); std::cout << "ADDED A BISHOP WITH ID: " << index << std::endl; }; break;
		case QUEEN: {entity_list.push_back(new Queen(index, x, y)); std::cout << "ADDED A QUEEN WITH ID: " << index << std::endl; }; break;
	}

	index++;
	return 1;
}


int main() {
	srand(time(NULL));

	GameHandler* game = new GameHandler(10, 10);
	game->add_unit(QUEEN);
	game->add_unit(BISHOP);
	game->add_unit(ROOK);
	game->add_unit(ROOK);
	game->add_unit(BISHOP);
	game->add_unit(QUEEN);
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	//game->run();
	game->unit_testing(); /* Uncomment to run some basic collision testing */
}

int GameHandler::unit_testing() {
	std::cout << "UNIT TESTING " << std::endl;
	std::cout << "TESTING COLLISIONS " << std::endl;
	std::vector<Piece*> test_collision_SQSQ;
	test_collision_SQSQ.push_back(new Rook(0, 5, 5));
	test_collision_SQSQ.push_back(new Rook(1, 5, 5));
	std::cout << "TESTING SQUARE - SQUARE COLLISION (FULL OVERLAP)" << std::endl;
	if (test_collision_SQSQ.at(0)->check_collision(test_collision_SQSQ) != -1)
		std::cout << "COLLISION SUCCESSFUL" << std::endl;
	else
		std::cout << "COLLISION FAILED" << std::endl;
	std::cout << "TESTING SQUARE - SQUARE COLLISION (PARTIAL OVERLAP) " << std::endl;
	test_collision_SQSQ.at(0)->set_x(3.1);
	if (test_collision_SQSQ.at(0)->check_collision(test_collision_SQSQ) != -1)
		std::cout << "COLLISION SUCCESSFUL" << std::endl;
	else
		std::cout << "COLLISION FAILED" << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::vector<Piece*> test_collision_CRCR;
	test_collision_CRCR.push_back(new Bishop(0, 5, 5));
	test_collision_CRCR.push_back(new Queen(1, 5, 5));
	std::cout << "TESTING SQUARE - CIRCLE COLLISION (FULL OVERLAP)" << std::endl;
	if (test_collision_CRCR.at(0)->check_collision(test_collision_CRCR) != -1)
		std::cout << "COLLISION SUCCESSFUL" << std::endl;
	else
		std::cout << "COLLISION FAILED" << std::endl;
	test_collision_CRCR.at(0)->set_x(3.1);
	if (test_collision_CRCR.at(0)->check_collision(test_collision_CRCR) != -1)
		std::cout << "COLLISION SUCCESSFUL" << std::endl;
	else
		std::cout << "COLLISION FAILED" << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::vector<Piece*> test_collision_SQCR;
	test_collision_SQCR.push_back(new Rook(0, 5, 5));
	test_collision_SQCR.push_back(new Queen(1, 5, 5));
	std::cout << "TESTING SQUARE - SQUARE COLLISION (FULL OVERLAP)" << std::endl;
	if (test_collision_SQCR.at(0)->check_collision(test_collision_SQCR) != -1)
		std::cout << "COLLISION SUCCESSFUL" << std::endl;
	else
		std::cout << "COLLISION FAILED" << std::endl;
	test_collision_SQCR.at(0)->set_x(3.1);
	std::cout << "TESTING SQUARE - SQUARE COLLISION (PARTIAL OVERLAP)" << std::endl;
	if (test_collision_SQCR.at(0)->check_collision(test_collision_SQCR) != -1)
		std::cout << "COLLISION SUCCESSFUL" << std::endl;
	else
		std::cout << "COLLISION FAILED" << std::endl;
	test_collision_SQCR.at(0)->set_y(6.4);
	test_collision_SQCR.at(0)->set_x(3.1);
	std::cout << "TESTING SQUARE - SQUARE COLLISION (CORNER OVERLAP)" << std::endl;
	if (test_collision_SQCR.at(0)->check_collision(test_collision_SQCR) != -1)
		std::cout << "COLLISION SUCCESSFUL" << std::endl;
	else
		std::cout << "COLLISION FAILED" << std::endl;

	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	return 1;
}