/***********************************************************************
 * Source File:
 *    KNIGHT : Handles the knight piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jespeson
 * Summary:
 *    A knight on the board. 
 ************************************************************************/

 #include "knight.h"

/****************************************************
 * CONSTRUCTOR : Initializes a Knight object
 ***************************************************/
Knight::Knight(Position pos, bool color, PieceType pt)
{
	position = pos;
	fWhite = color;
	type = pt;
	possibleDirections = 8;
}

/****************************************************
 * DRAW : Draws the Knight on the board
 ***************************************************/
 void Knight::draw(ogstream& gout)
{
	gout.drawKnight(position.getLocation(), fWhite);
}

/******************************************************
 * GET DIRECTIONS : Gets the directions the Knight can
 * move in
 *****************************************************/
 RC* Knight::getDirections()
 {
	 RC* moves = new RC[8]
	 {
			  {-1,  2}, { 1,  2},
	 {-2,  1},                    { 2,  1},
	 {-2, -1},                    { 2, -1},
			  {-1, -2}, { 1, -2}
	 };

	 return moves;
 }