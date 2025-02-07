/***********************************************************************
 * Header File:
 *    MOVE : Keep track of a single chess move
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type
//#include "board.h"



class MoveTest;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
  public:
      friend MoveTest;

      // constructor
      Move(); 
      Move(const Move & rhs)           { *this = rhs;      }
      Move(const char * s)             { *this = s;        }

      // getters
      string getText()           const;
      const Position & getDes()  const { return dest;      }
      const Position & getSrc()  const { return source;    }
      PieceType getPromotion()   const { return promote;   }
      PieceType getCapture()     const { return capture;   }
      bool getEnPassant()        const { return enpassant; }
      bool getCastleK()          const { return castleK;   }
      bool getCastleQ()          const { return castleQ;   }
      bool getWhiteMove()        const { return isWhite;   }
      bool operator == (const Move & rhs)   const;
      bool operator == (const string & rhs) const { return getText() == rhs; }
      bool operator != (const string & rhs) const { return getText() != rhs; }
      bool operator != (const Move & rhs)   const { return !(*this == rhs); }
      bool operator <  (const Move & rhs)   const { return dest.getLocation() < rhs.dest.getLocation(); }
	  bool operator >  (const Move& rhs)   const { return dest.getLocation() > rhs.dest.getLocation(); }

      // setters
      void setCapture(PieceType pt)     { capture    = pt;  }
      void setWhiteMove(bool f)         { isWhite    = f;   }
      void setSrc(const Position & src) { source     = src; }
      void setDes(const Position & des) { dest       = des; }
      void setEnPassant()               { enpassant  = true;}
      void setPromote(PieceType pt)     { promote      = pt;  }
      //void complete(const Board & board);
      void setCastle(bool isKing)
      {
         if (isKing)
            castleK = true;
         else
            castleQ = true;
      };

      // for file I/O though only file input is currently implemented
      friend ostream & operator << (ostream & out, Move & rhs);
      friend istream & operator >> (istream & in,  Move & rhs);
      
      const Move & operator = (const Move & rhs);
      const Move & operator = (const string & s)
      {
         read(s);
         return *this;
      }
      const Move & operator = (const char *s)
      {
         const string str(s);
         read(str);
         return *this;
      }
      

private:
      void read(const std::string & s);
      char letterFromPieceType(PieceType pt) const;
      PieceType pieceTypeFromLetter(char letter) const;

      Position  source;    // where the move originated from
      Position  dest;      // where the move finished
      PieceType promote;   // piece to be promoted to
      PieceType capture;   // did a capture happen this move?
      bool      enpassant; // Enpassant pawn capture
      bool      castleK;   // kingside castle
      bool      castleQ;   // queenside castle
      bool      isWhite;   // white's move?
      string    error;     // if in error state, what was the bug?  
};

