/***********************************************************************
 * Header File:
 *    SPACE : Handles a space on the board.
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A space on the chess board.
 ************************************************************************/
#include "piece.h"
#pragma once

class Space : public Piece
{
public:
	Space(Position pos, bool color = NULL, PieceType pt = SPACE)
	{
		position = pos;
		fWhite = color;
		type = pt;
		possibleDirections = 0;
	}
	void draw(ogstream& gout) { return; }
};
