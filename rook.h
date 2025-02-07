/***********************************************************************
 * Header File:
 *    ROOK : Handles the rook piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A rook on the chess board.
 ************************************************************************/

#include "piece.h"
#pragma once

using namespace std;

class Rook : public Piece
{
public:
	Rook(Position pos, bool color, PieceType pt = ROOK);
	void draw(ogstream& gout);
	RC* getDirections();
};
