/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testMove.h"
#include "testPawn.h"
#include "testPiece.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
	MoveTest().run();
	PositionTest().run();
	//PawnTest().run();
	PieceTest().run();
}