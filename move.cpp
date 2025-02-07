/***********************************************************************
 * Source File:
 *    MOVE : Keep track of a single chess move
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "piece.h"
//#include "board.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move() :
      promote(SPACE),       capture(SPACE),       enpassant(false),
      castleK(false),     castleQ(false),       isWhite(true),
      source(Position()), dest(Position())
{
}

/***********************************************
 * MOVE : COMPLETE
 * We have a move that has nothing but a source
 * and a destination. Figure out what it should be
 **********************************************/
/*void Move::complete(const Board& board)
{
   // set the capture
  // capture = board[dest].getLetter();        // COMMENTED OUT SO TESTS RUN

   // set the color
   //isWhite = board[source].isWhite();

   // handle if this is an en-passant
   //if (capture == SPACE && board[source] == PAWN)
     // enpassant = true;
}*/

/***********************************************
 * MOVE : EQUALITY
 **********************************************/
bool Move::operator == (const Move & rhs) const
{
   if (source    == rhs.getSrc()       &&
       dest      == rhs.getDes()       &&
       castleK   == rhs.getCastleK()   &&
       castleQ   == rhs.getCastleQ()   &&
       enpassant == rhs.getEnPassant() &&
       capture   == rhs.getCapture()   &&
       promote     == rhs.getPromotion())
   {
      assert(enpassant == rhs.getEnPassant());
      assert(castleK   == rhs.getCastleK());
      assert(castleQ   == rhs.getCastleQ());
      assert(promote     == rhs.getPromotion());
      return true;
   }
   else
      return false;
}

/***********************************************
 * MOVE : LETTER FROM PIECE TYPE
 *        Get the Smith notation letter for a piece from
 *        the Piece Type
 *********************************************/
char Move::letterFromPieceType(PieceType pt) const
{
   switch (pt)
   {
      case SPACE:
         return ' ';
      case KING:
         return 'k';
      case QUEEN:
         return 'q';
      case ROOK:
         return 'r';
      case KNIGHT:
         return 'n';
      case BISHOP:
         return 'b';
      case PAWN:
         return 'p';
   }
   assert(false);
   return ' ';
}

/***********************************************
 * MOVE : PIECE TYPE FROM LETTER
 *        Get the Piece Type for a piece from
 *        the Smith notation letter
 *********************************************/
PieceType Move::pieceTypeFromLetter(char letter) const
{
   switch (letter)
   {
      case 'k':
         return KING;
      case 'q':
         return QUEEN;
      case 'r':
         return ROOK;
      case 'b':
         return BISHOP;
      case 'n':
         return KNIGHT;
      case 'p':
         return PAWN;
   }
   assert(false);
   return SPACE;
}


/***********************************************
 * MOVE : GET TEXT
 *        Generate the human-readable text
 *********************************************/
string Move::getText() const
{
   // if there is an error, use it instead
   if (error.length())
      return error;
   
   // use the string stream so we can use the insertion operators of
   // the position class
   std::ostringstream sout;
   sout << source << dest;

   // handle all the special stuff
   if (enpassant)
      sout << "E";
   if (castleK)
      sout << "c";
   if (castleQ)
      sout << "C";
   if (promote != SPACE)
      sout << toupper(letterFromPieceType(promote));
   if (capture != SPACE && !enpassant)
      sout << letterFromPieceType(capture);

   // return the result as a string
   return sout.str();
}

/**********************************************
 * Move : ASSIGNMENT
 **********************************************/
const Move & Move::operator = (const Move & rhs)
{
   source    = rhs.getSrc();
   dest      = rhs.getDes();
   promote     = rhs.getPromotion();
   capture   = rhs.getCapture();
   enpassant = rhs.getEnPassant();
   castleK   = rhs.getCastleK();
   castleQ   = rhs.getCastleQ();
   isWhite   = rhs.getWhiteMove();
   error     = rhs.error;
   return *this;
}


/**********************************************
 * MOVE : READ
 * Parse the input text into its components.
 * We will not validate until later...
 **********************************************/
void Move::read(const string & s)
{
   // clear the move
   *this = Move();

   //
   // from square
   //
   source = s.c_str() + 0;  // start at the start

   //
   // to square
   //
   dest = s.c_str() + 2;   // start two characters in, the destination

   //
   // capture and promotion
   //

   for (int i = 4; i < (int)s.size(); i++)
   {
      switch(s[i])
      {
         case 'p':   // capture a pawn
            capture = PAWN;
            break;
         case 'n':   // capture a knight
            capture = KNIGHT;
            break;
         case 'b':   // capture a bishop
            capture = BISHOP;
            break;
         case 'r':   // capture a rook
            capture = ROOK;
            break;
         case 'q':   // capture a queen
            capture = QUEEN;
            break;
         case 'k':   // !! you can't capture a king you silly!
            capture = KING;
            break;

         case 'c':  // short castling or kings castle
            castleK = true;
            break;
         case 'C':  // long castling or queen castle
            castleQ = true;
            break;
         case 'E':  // En-passant
            enpassant = true;
            break;

         case 'N':  // Promote to knight
            promote = KNIGHT;
            break;
         case 'B':  // Promote to Bishop
            promote = BISHOP;
            break;
         case 'R':  // Promote to Rook
            promote = ROOK;
            break;
         case 'Q':  // Promote to Queen
            promote = QUEEN;
            break;

         default:
            // unknown piece
            error = s;
            throw string("Unknown promotion piece specification");
      }
   }

   // if we made it this far, we are successful
   return;
}


/******************************************
 * MOVE INSERTION OPERATOR
 *       Aint nothing but a glorified getText call...
 ******************************************/
ostream & operator << (ostream & out, Move & rhs)
{
   out << rhs.getText();

   return out;
}

/*************************************
 * MOVE EXTRACTION OPERATOR
 *      Just the assignment operator with a string
 *      on the right-hand-side
 **************************************/
istream & operator >> (istream & in,  Move & rhs)
{   
   string s;
   if (in >> s)
      rhs = s; // assigment operator calling Move::read()

   return in;   
}

