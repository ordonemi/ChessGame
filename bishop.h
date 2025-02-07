/***********************************************************************
 * Header File:
 *    BISHOP : Handles the bishop piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A bishop on the board. 
 ************************************************************************/
#include "piece.h"
#pragma once

class Bishop : public Piece
{
public:
	Bishop(Position pos, bool color, PieceType pt = BISHOP);
	RC* getDirections();
	void draw(ogstream& gout);
};
