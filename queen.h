/***********************************************************************
 * Header File:
 *    QUEEN : Handles a queen on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A queen on the board.
 ************************************************************************/

#include "piece.h"
#pragma once

class Queen : public Piece
{
public:
	Queen(Position pos, bool color, PieceType pt = QUEEN);
	void draw(ogstream& gout);
	RC* getDirections();
};
	