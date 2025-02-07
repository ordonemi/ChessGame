/***********************************************************************
 * Source File:
 *    Piece Test : Unit tests for the Piece class
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    The unit tests for Piece
 ************************************************************************/

#include "testPiece.h"
#include "piece.h"
#include <cassert>

/**************************************
 * Constructor (White)
***************************************/
void PieceTest::constructorWhite() const
{
	// SETUP
	// EXERCISE
	Piece pawn = Piece(Position(2,0),false,PAWN);
	// VERIFY 
	assert(pawn.getPosition().getRow() == 2);
	assert(pawn.getPosition().getCol() == 0);
	assert(pawn.isBlack() == false);
	assert(pawn.hasMoved() == false);
}

/***************************************
 * Constructor (Black)
****************************************/
void PieceTest::constructorBlack() const
{
	// SETUP
	// EXERCISE
	Piece p = Piece(Position(7, 0), true,PAWN);
	// VERIFY 
	assert(p.getPosition().getRow() == 7);
	assert(p.getPosition().getCol() == 0);
	assert(p.isBlack() == true);
	assert(p.hasMoved() == false);
}

/****************************************
 * Move piece
*****************************************/
void PieceTest::assignPos() const
{
	// SETUP
	Piece p = Piece(Position(2, 0), true,PAWN); // white pawn at location 8
	Position pos = Position();
	pos.set(4, 0);
	// EXERCISE
	p.assignPos(pos);
	// VERIFY
	assert(p.getPosition().getRow() == 4);
	assert(p.getPosition().getCol() == 0);
	assert(p.isBlack() == true);
	assert(p.hasMoved() == true);
}

/***************************************
* Move piece to out of bounds position
****************************************/
void PieceTest::invalidPos() const
{
	// SETUP
	Piece p = Piece(Position(2, 1), true,PAWN); //white pawn
	Position pos = Position();
	pos.set(20, 15);
	// EXERCISE
	p.assignPos(pos);
	// VERIFY
	assert(p.getPosition().getRow() == 0);
	assert(p.getPosition().getCol() == 0);
	assert(p.isBlack() == true);
}

/*****************************************
 * Piece is keeping track of moves
******************************************/
void PieceTest::keepTrackofMoves() const
{
	// SETUP
	Piece p = Piece(Position(2, 0), true,PAWN);
	Position pos1;
	Position pos2;
	Position pos3;
	pos1.set(3, 0);
	pos2.set(4, 0);
	pos3.set(5, 0);
	// EXERCISE
	p.assignPos(pos1);
	p.assignPos(pos2);
	p.assignPos(pos3);
	// VERIFY
	assert(p.getNMoves() == 3);
	assert(p.hasMoved() == true);
}
