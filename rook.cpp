/***********************************************************************
 * Source File:
 *    ROOK : Handles the rook piece on the board.
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A rook on the chess board.
 ************************************************************************/

#include "rook.h"

 /****************************************************
  * CONSTRUCTOR
  * Create a Rook object
  ***************************************************/
Rook::Rook(Position pos, bool color, PieceType pt)
{
	position = pos;
	fWhite = color;
	type = pt;
	canSlide = true;
	possibleDirections = 4;
}

/****************************************************
 * DRAW
 * Draws the rook on the board
 ***************************************************/
void Rook::draw(ogstream& gout)
{
	gout.drawRook(position.getLocation(), fWhite);
}

/****************************************************
 * GET DIRECTIONS()
 * Get the directions the rook can travel to
 ***************************************************/
RC* Rook::getDirections()
{
	RC* moves = new RC[4]{
	{0, 1},
	{-1, 0},
	{1, 0},
	{0, -1}
	};

	return moves;
}