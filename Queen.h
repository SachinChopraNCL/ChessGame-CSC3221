#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen : public Bishop, Rook {
public:	
	Queen(int index, float x, float y, Shape shape = CIRCLE) : Piece(index, x,y,shape,QUEEN) {}
	
	int move(unsigned int width, unsigned int height) override;

};