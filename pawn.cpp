/***********************************************************************
 * Source File:
 *    PAWN : Handles a pawn on the board
 * Author:
 *    Austin Jesperson
 * Summary:
 *    A pawn on the chess board.
 ************************************************************************/

#include "pawn.h"

/************************************************
 * CONSTRUCTOR : Initializes a Pawn object
 ************************************************/
Pawn::Pawn(Position pos, bool color, PieceType pt)
{
    position = pos;
    fWhite = color;
    type = pt;
    canSlide = false;
}

/*************************************************
 * DRAW : Draws the Pawn on the board
 ************************************************/
void Pawn::draw(ogstream& gout)
{
	gout.drawPawn(position.getLocation(), fWhite);
}