/***********************************************************************
 * Header File:
 *    TEST MOVE : test the Piece class
 * Author:
 *    Emilio Ordonez
 ************************************************************************/
#include <iostream>
#pragma once
using namespace std;

class PieceTest
{
public:
	void run() const
	{
		constructorBlack();
		constructorWhite();
		assignPos();
		invalidPos();
		keepTrackofMoves();
		cout << "PieceTest: 5/5 Tests passed.";
	}
private:
	void constructorWhite() const;
	void constructorBlack() const;

	void assignPos() const;
	void invalidPos() const;

	void keepTrackofMoves() const;
};