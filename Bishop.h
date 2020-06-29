#pragma once
#include "Piece.h"

class Bishop : virtual public Piece {
public:
	Bishop() {}
	
	Bishop(int index, float x, float y, Shape shape = CIRCLE):Piece(index,x,y,shape,BISHOP){}
	
	int move(unsigned int width, unsigned int height) override;

private:

	const int radius = 1; 

};