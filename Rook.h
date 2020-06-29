#pragma once
#include "Piece.h"

class Rook : virtual public Piece{

public:

	Rook() {}

	Rook(int index, float x, float y, Shape shape = SQUARE) :Piece(index, x, y, shape, ROOK) {}
	
	int move(unsigned int width, unsigned int height) override;


private:
	const int width = 1, height = 1; 
};