/***********************************************************************
 * Header File:
 *    KING : Handles a king piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A king on the chess board.
 ************************************************************************/
#include "piece.h"
#pragma once

class King : public Piece
{
public:
	King(Position pos, bool color, PieceType pt = KING);
	RC* getDirections();
	void draw(ogstream& gout);
};
