/***********************************************************************
 * Header File:
 *    PIECE : Handles each piece on the board.
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    A piece on the chess board.
 ************************************************************************/
#pragma once
#include "position.h"
#include "uiDraw.h"
#include "pieceType.h"
#include "rc.h"
#include <set> // for STD::SET

using namespace std;

class Piece
{
public:
	// Constructors
	Piece(Position p, bool color, PieceType pt);
	Piece() {};

	bool isBlack() { return fWhite; }
	void assignPos(Position os);
	int getNMoves() { return nMoves; }
	Position getPosition() { return position; }
	bool hasMoved();
	bool isValid();
	virtual RC* getDirections();
	bool ifSlide() { return canSlide; };
	virtual void draw(ogstream& gout) {};
	int getLengthOfDirections() { return possibleDirections; }
	PieceType getType() { return type; }
	const Piece& operator = (const Piece& rhs);
protected:
	Position position;
	bool fWhite = false; // false is equal to white, true is equal to black
	int nMoves = 0;
	PieceType type = SPACE;
	bool canSlide = false;
	int possibleDirections = 4;
};
