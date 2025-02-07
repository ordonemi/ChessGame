/***********************************************************************
 * Header File:
 *    TEST MOVE : test the Move class
 * Author:
 *    Br. Helfrich
 ************************************************************************/

#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor
  **************************************/
void MoveTest::constructor_default() const
{  // SETUP
   // EXERCISE
   Move moveTest; // default constructor
   // VERIFY
   assert(Position() == moveTest.source);
   assert(Position() == moveTest.dest);
   assert(SPACE == moveTest.promote);
   assert(SPACE == moveTest.capture);
   assert(!moveTest.enpassant);
   assert(!moveTest.castleK);
   assert(!moveTest.castleQ);
   assert(moveTest.isWhite);
}  // TEARDOWN


 /*************************************
  * ASSIGN string
  **************************************/
void MoveTest::read_simple() const
{  // SETUP
   Move move;
   move.source    = "f8";
   move.dest      = "f8";
   move.promote     = KNIGHT;
   move.capture   = BISHOP;
   move.enpassant = true;
   move.castleK   = true;
   move.castleQ   = true;
   move.isWhite   = false;
   move.error     = "ERROR";
   // EXERCISE
   move.read(string("e5e6"));
   // VERIFY
   assert(Position(4, 4) == move.source);
   assert(Position(5, 4) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(false == move.castleQ);
   assert(true  == move.isWhite);
}  // TEARDOWN

void MoveTest::read_capture() const
{  // SETUP
   Move move;
   move.source    = "f8";
   move.dest      = "f8";
   move.promote     = KNIGHT;
   move.capture   = BISHOP;
   move.enpassant = true;
   move.castleK   = true;
   move.castleQ   = true;
   move.isWhite   = false;
   move.error     = "ERROR";
   // EXERCISE
   move.read(string("e5e6r"));
   // VERIFY
   assert(Position(4, 4) == move.source);
   assert(Position(5, 4) == move.dest);
   assert(SPACE == move.promote);
   assert(ROOK  == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(false == move.castleQ);
   assert(true  == move.isWhite);
}  // TEARDOWN

void MoveTest::read_enpassant() const
{  // SETUP
   Move move;
   move.source    = "f8";
   move.dest      = "f8";
   move.promote     = KNIGHT;
   move.capture   = BISHOP;
   move.enpassant = false;
   move.castleK   = true;
   move.castleQ   = true;
   move.isWhite   = false;
   move.error     = "ERROR";
   // EXERCISE
   move.read(string("e5f6E"));
   // VERIFY
   assert(Position(4, 4) == move.source);
   assert(Position(5, 5) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(true  == move.enpassant);
   assert(false == move.castleK);
   assert(false == move.castleQ);
   assert(true  == move.isWhite);
}  // TEARDOWN

void MoveTest::read_castleKing() const
{  // SETUP
   Move move;
   move.source    = "f8";
   move.dest      = "f8";
   move.promote     = KNIGHT;
   move.capture   = BISHOP;
   move.enpassant = true;
   move.castleK   = true;
   move.castleQ   = true;
   move.isWhite   = false;
   move.error     = "ERROR";
   // EXERCISE
   move.read(string("e1g1c"));
   // VERIFY
   assert(Position(0, 4) == move.source);
   assert(Position(0, 6) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(true  == move.castleK);
   assert(false == move.castleQ);
   assert(true  == move.isWhite);
}  // TEARDOWN

void MoveTest::read_castleQueen() const
{  // SETUP
   Move move;
   move.source    = "f8";
   move.dest      = "f8";
   move.promote     = KNIGHT;
   move.capture   = BISHOP;
   move.enpassant = true;
   move.castleK   = true;
   move.castleQ   = true;
   move.isWhite   = false;
   move.error     = "ERROR";
   // EXERCISE
   move.read(string("e1c1C"));
   // VERIFY
   assert(Position(0, 4) == move.source);
   assert(Position(0, 2) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(true  == move.castleQ);
   assert(true  == move.isWhite);
}  // TEARDOWN

void MoveTest::constructString_simple() const
{  // SETUP
   // EXERCISE
   Move move("e5e6");
   // VERIFY
   assert(Position(4, 4) == move.source);
   assert(Position(5, 4) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(false == move.castleQ);
   assert(true == move.isWhite);
}  // TEARDOWN

void MoveTest::assign_simple() const
{  // SETUP
   Move move;
   move.source = "f8";
   move.dest = "f8";
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // EXERCISE
   move = string("e1c1C");
   // VERIFY
   assert(Position(0, 4) == move.source);
   assert(Position(0, 2) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(true == move.castleQ);
   assert(true == move.isWhite);
}  // TEARDOWN

 /*************************************
  * GET TEXT 
  **************************************/
void MoveTest::getText_simple() const
{  // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(5, 4);
   move.promote = SPACE;
   move.capture = SPACE;
   move.enpassant = false;
   move.castleK = false;
   move.castleQ = false;
   move.isWhite = true;
   move.error = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assert(s == string("e5e6"));
   assert(Position(4, 4) == move.source);
   assert(Position(5, 4) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(false == move.castleQ);
   assert(true == move.isWhite);
}  // TEARDOWN

void MoveTest::getText_capture() const
{  // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(5, 4);
   move.promote = SPACE;
   move.capture = ROOK;
   move.enpassant = false;
   move.castleK = false;
   move.castleQ = false;
   move.isWhite = true;
   move.error = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assert(s == string("e5e6r"));
   assert(Position(4, 4) == move.source);
   assert(Position(5, 4) == move.dest);
   assert(SPACE == move.promote);
   assert(ROOK == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(false == move.castleQ);
   assert(true == move.isWhite);
}  // TEARDOWN

void MoveTest::getText_enpassant() const
{  // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(5, 5);
   move.promote = SPACE;
   move.capture = PAWN;
   move.enpassant = true;
   move.castleK = false;
   move.castleQ = false;
   move.isWhite = true;
   move.error = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assert(s == string("e5f6E"));
   assert(Position(4, 4) == move.source);
   assert(Position(5, 5) == move.dest);
   assert(SPACE == move.promote);
   assert(PAWN == move.capture);
   assert(true == move.enpassant);
   assert(false == move.castleK);
   assert(false == move.castleQ);
   assert(true == move.isWhite);
}  // TEARDOWN

void MoveTest::getText_castleKing() const
{  // SETUP
   Move move;
   move.source = Position(0, 4);
   move.dest = Position(0, 6);
   move.promote = SPACE;
   move.capture = SPACE;
   move.enpassant = false;
   move.castleK = true;
   move.castleQ = false;
   move.isWhite = true;
   move.error = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assert(s == string("e1g1c"));
   assert(Position(0, 4) == move.source);
   assert(Position(0, 6) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(true == move.castleK);
   assert(false == move.castleQ);
   assert(true == move.isWhite);
}  // TEARDOWN

void MoveTest::getText_castleQueen() const
{  // SETUP
   Move move;
   move.source = Position(0, 4);
   move.dest = Position(0, 2);
   move.promote = SPACE;
   move.capture = SPACE;
   move.enpassant = false;
   move.castleK = false;
   move.castleQ = true;
   move.isWhite = true;
   move.error = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assert(s == string("e1c1C"));
   // VERIFY
   assert(Position(0, 4) == move.source);
   assert(Position(0, 2) == move.dest);
   assert(SPACE == move.promote);
   assert(SPACE == move.capture);
   assert(false == move.enpassant);
   assert(false == move.castleK);
   assert(true == move.castleQ);
   assert(true == move.isWhite);
}  // TEARDOWN


/*************************************
 * LETTER FROM PIECE TYPE
 **************************************/
void MoveTest::letterFromPieceType_space() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(SPACE);
   // verify
   assert(letter == ' ');
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::letterFromPieceType_pawn() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(PAWN);
   // verify
   assert(letter == 'p');
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::letterFromPieceType_bishop() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(BISHOP);
   // verify
   assert(letter == 'b');
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::letterFromPieceType_knight() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(KNIGHT);
   // verify
   assert(letter == 'n');
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::letterFromPieceType_rook() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(ROOK);
   // verify
   assert(letter == 'r');
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::letterFromPieceType_queen() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(QUEEN);
   // verify
   assert(letter == 'q');
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::letterFromPieceType_king() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(KING);
   // verify
   assert(letter == 'k');
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

/*************************************
 * PIECE TYPE FROM LETTER
 **************************************/

void MoveTest::pieceTypeFromLetter_pawn() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('p');
   // verify
   assert(pt == PAWN);
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::pieceTypeFromLetter_bishop() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('b');
   // verify
   assert(pt == BISHOP);
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::pieceTypeFromLetter_knight() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('n');
   // verify
   assert(pt == KNIGHT);
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::pieceTypeFromLetter_rook() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('r');
   // verify
   assert(pt == ROOK);
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::pieceTypeFromLetter_queen() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('q');
   // verify
   assert(pt == QUEEN);
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown

void MoveTest::pieceTypeFromLetter_king() const
{  // SETUP
   Move move;
   move.source = Position(7, 7);
   move.dest = Position(7, 7);
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.enpassant = true;
   move.castleK = true;
   move.castleQ = true;
   move.isWhite = false;
   move.error = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('k');
   // verify
   assert(pt == KING);
   assert(Position(7, 7) == move.source);
   assert(Position(7, 7) == move.dest);
   assert(KNIGHT == move.promote);
   assert(BISHOP == move.capture);
   assert(true == move.enpassant);
   assert(true == move.castleK);
   assert(true == move.castleQ);
   assert(false == move.isWhite);
}  // teardown
