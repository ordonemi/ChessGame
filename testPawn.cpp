///***********************************************************************
// * C++ File:
// *    TEST PAWN : test the Pawn class
// * Author:
// *    Austin Jesperson
// ************************************************************************/
//
//#include "testPawn.h"
//#include "pawn.h"
//#include "board.h"
//#include <cassert>
//
// /*************************************
//  * Constructor
//  **************************************/
//void PawnTest::constructor_default() const
//{  // SETUP 
//		// we need a blank board to start
//   // EXERCISE	
//	Board pawnTest; // default constructor
//
//	// VERIFY
//	assert(pawnTest.blackTurn() == false);
//	pawnTest.clear();
//	for (int i = 0; i < 64; i++)
//	{
//		assert(pawnTest. == Space);
//	}
//
//}  // TEARDOWN
//
//void PawnTest::pawn_blocked() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 3, true));
//	board.assign(Pawn b(b, 4, false));
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_regMove() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 3, true));
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {"b3b4"});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_firstMove() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 2, true));
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {"b2b3", "b2b4"});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_blockedFirstMove() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 2, true));
//	board.assign(Pawn b(b, 3, false));
//
//	a.nMoves = 0;
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_blockedFirstMoveDouble() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 2, true));
//	board.assign(Pawn b(b, 4, false));
//
//	a.nMoves = 0;
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {"b2b3"});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_capture() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 3, true));
//	board.assign(Pawn b(b, 4, false));
//	board.assign(Pawn c(a, 4, false));
//	board.assign(Pawn d(c, 4, false));
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {"b3a4p", "b3c4p"});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_noTeamCapture() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 3, true));
//	board.assign(Pawn b(b, 4, true));
//	board.assign(Pawn c(a, 4, true));
//	board.assign(Pawn d(c, 4, true));
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_enpassant() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 5, true));
//	board.assign(Pawn b(b, 6, false));
//	board.assign(Pawn c(a, 5, false));
//	board.assign(Pawn d(c, 5, false));
//
//	c.nMoves = 1;
//	c.justMoved = true;
//	d.nMoves = 1;
//	d.justMoved = true;
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {"b5a6E", "b5c6E"});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_promote() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 7, true));
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {"b7b8Q"});
//
//}	//TEARDOWN
//
//void PawnTest::pawn_promoteCapture() const
//{   //SETUP
//	Board board;
//
//	board.assign(Pawn a(b, 7, true));
//	board.assign(Pawn b(b, 8, false));
//	board.assign(Pawn c(a, 8, false));
//	board.assign(Pawn d(c, 8, false));
//
//	// EXERCISE
//	moves = a.getMoves();
//
//	// VERIFY
//	assert(moves == {"b7a8pQ", "b7c8pQ"});
//
//}	//TEARDOWN