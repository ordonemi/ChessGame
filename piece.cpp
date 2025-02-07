/***********************************************************************
 * Source File:
 *    PIECE : Keep track of each piece on the board
 * Author:
 *    Emilio Ordonez 
 * Summary:
 *    All the pieces on the board. 
 ************************************************************************/

#include "piece.h"

/**************************************
* PIECE : ASSIGN POS
***************************************/
void Piece::assignPos(Position pos)
{
	if (pos.getRow() > 7 || pos.getRow() < 0)
	{
		return;
	}
	else if (pos.getCol() > 7 || pos.getCol() < 0)
	{
		return;
	}
	position = pos;
	nMoves++;
}

/**************************************
* PIECE : CONSTRUCTOR
***************************************/
Piece::Piece(Position p, bool color, PieceType pt)
{
	position = p;
	fWhite = color;
	type = pt;
	canSlide = false;
}

/*************************************************
* HAS MOVED() : DETERMINE IF THE PIECE HAS MOVED
***************************************************/
bool Piece::hasMoved()
{
	if (nMoves > 0)
	{
		return true;
	}
	return false;
}

/******************************************************
* IS VALID() : DETERMINE IF THE PIECE IS NOT A SPACE
*******************************************************/
bool Piece::isValid()
{
	if (type == SPACE)
	{
		return false;
	}
	return true;
}

/******************************************************
* GET DIRECTIONS() : DETERMINE THE DIRECTIONS EACH PIECE
* CAN GO
*******************************************************/
RC* Piece::getDirections()
{
	RC* moves = new RC[4]{
	{0, 1},
	{-1, 0},
	{1, 0},
	{0, -1}
	};

	return moves;
}

//const Piece& Piece::operator= (const Piece& rhs)
//{
//	Position position = rhs.position;
//	bool fWhite = rhs.fWhite;
//	int nMoves = rhs.nMoves;
//	PieceType type = rhs.type;
//	bool canSlide = rhs.canSlide;
//	int possibleDirections = rhs.possibleDirections;
//}