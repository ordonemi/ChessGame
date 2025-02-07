/***********************************************************************
 * Header File:
 *    BOARD : Handles the board.
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    A chess board.
 ************************************************************************/
#pragma once
#include "uiDraw.h"
#include "uiInteract.h"
#include "move.h"
#include "piece.h"
#include "space.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"

using namespace std;

class Board
{
public:
	Board();
	bool blackTurn();
	void reset();
	void clear();
	bool move(int positionFrom, int positionTo);
	void assign(Position pos, Piece* p);
	void draw(const Interface& ui);
	void clearMoves() { moves.clear(); }
private:
	Piece* board[64];
	int currentMove = 1; 
	ogstream gout;
	Move last;
	set <Move> moves;
	void convertDirectionToMove(RC* movesArrayP, int length, Piece* currPiece);
};
