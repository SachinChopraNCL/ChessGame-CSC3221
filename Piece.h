#pragma once
#include <vector>
#include <iostream>
#include "Type.h"
enum Shape {
	CIRCLE,
	SQUARE
};

/* Piece outlines the basic functionality of every piece. We also introduce an ENUM to dicate the type of shape*/

class Piece {

public:
	Piece(){}
	Piece(int index, float x, float y, Shape piece_shape, Type type) {
		this->index = index;
		this->x = x;
		this->y = y;
		this->piece_shape = piece_shape;
		this->type = type;
	}
	virtual ~Piece() {}

	float get_x() { return x; }
	void  set_x(float x) { this->x = x; }
	float get_y() { return y; }
	void  set_y(float y) { this->y = y; }
	int   get_index() { return index; }
	Shape get_shape(){ return piece_shape; }
	Type  get_type() { return type; }
	virtual int move(unsigned int width, unsigned int height) { std::cout << "ERROR - FUNCTION SHOULD NOT BE CALLED" << std::endl; return -1; }
	int check_collision(std::vector<Piece*> &pieces);

private:
	float x, y; 
	int index;
	const int radius = 1;
	Shape piece_shape; 
	Type type;
};