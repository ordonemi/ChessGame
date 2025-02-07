/***********************************************************************
 * Source File:
 *    QUEEN : Handles a queen on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A queen on the board.
 ************************************************************************/
 #include "queen.h"

/***************************************************
 * CONSTRUCTOR : Initializes a Queen object
 ***************************************************/
Queen::Queen(Position pos, bool color, PieceType pt)
{
	position = pos;
	fWhite = color;
	type = pt;
	canSlide = true;
	possibleDirections = 8;
}

/****************************************************
 * DRAW : Draws the queen on the board
 ***************************************************/
 void Queen::draw(ogstream& gout)
{
	gout.drawQueen(position.getLocation(), fWhite);
}

 /**************************************************
  * GET DIRECTIONS : Gets the directions the Queen
  * can move in
  ***************************************************/
 RC* Queen::getDirections()
 {
	 RC* moves = new RC[8]{
	 {-1,  1},
	 {0,  1},
	 {1,  1},
	 {-1,  0},
	 {1,  0},
	 {-1, -1},
	 {0, -1},
	 {1, -1}
	 };

	 return moves;
 }