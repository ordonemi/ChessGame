/***********************************************************************
 * Source File:
 *    BISHOP : Handles the bishop piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A bishop on the board. 
 ************************************************************************/
#include "bishop.h"

/*************************************************
 * CONSTRUCTOR : Initializes a Bishop object
 *************************************************/
Bishop::Bishop(Position pos, bool color, PieceType pt)
{
	position = pos;
	fWhite = color;
	type = pt;
	possibleDirections = 4;
	canSlide = true;
}

/*************************************************
 * DRAW : Draws the bishop on the board
 *************************************************/
void Bishop::draw(ogstream& gout)
{
	gout.drawBishop(position.getLocation(), fWhite);
}

/**************************************************
 * GET DIRECTIONS : Get the directions the Bishop 
 * can move in
 **************************************************/
RC* Bishop::getDirections()
{
	RC* moves = new RC[4]{
   {-1,  1}, {1,  1},
   {-1, -1}, {1, -1}
	};

	return moves;
}