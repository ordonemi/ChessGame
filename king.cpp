/***********************************************************************
 * Source File:
 *    KING : Handles a king piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A king on the board.
 ************************************************************************/

#include "king.h"

/*****************************************************
 * Constructor : Initializes a King object
 ****************************************************/
King::King(Position pos, bool color, PieceType pt)
{
	position = pos;
	fWhite = color;
	type = pt;
	possibleDirections = 8;
}

/*****************************************************
 * DRAW : Draw the King on the board
 ****************************************************/
void King::draw(ogstream& gout)
{
	gout.drawKing(position.getLocation(), fWhite);
}

/*****************************************************
 * GET DIRECTIONS : Get the directions the King can 
 * travel in
 ****************************************************/
RC* King::getDirections()
{
	RC* moves = new RC[8]
	{
	   {-1,  1}, {0,  1}, {1,  1},
	   {-1,  0},          {1,  0},
	   {-1, -1}, {0, -1}, {1, -1}
	};

	return moves;
}