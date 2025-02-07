/***********************************************************************
 * Header File:
 *    Position : Location on the chess board
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
using std::string;
using std::ostream;
using std::istream;

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};

// const int PIXELS_PER_SQUARE = 32;

class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
public:

   // Constructors
   Position(const Position & rhs);
   Position() :               location(-1)  {               }
   Position(int loc) :        location(loc) {               }
   Position(const char * s) : location(0)   { *this = s;    }
   Position(int r, int c) :   location(0)   { set(r, c);    }
   Position(const Position & rhs, const Delta & delta) : location(-1)
   {
      set(rhs.getRow() + delta.dRow, rhs.getCol() + delta.dCol);
   }

   // Accessors
   int getLocation() const { return location; }
   int getRow() const { return (isInvalid() ? 0 : (int)(location / 8));}
   int getCol() const { return (isInvalid() ? 0 : (int)(location % 8));}
   int getX()   const { return (int)((double)getCol() * getSquareWidth());  }
   int getY()   const { return (int)((double)getRow() * getSquareHeight()); }
   double getSquareWidth()  const { return squareWidth;  }
   double getSquareHeight() const { return squareHeight;  }
   bool isInvalid() const { return location < 0 || location >= 64; }
   bool isValid()   const { return !isInvalid();                   }

   // Mutators
   void setRow(int r)
   {
      if (r >= 0 && r < 8 && isValid())
      {
         char c = getCol();
         location = (char)r * 8 + c;
      }
      else
         location = -1;
   }
   void setCol(int c)
   {
      if (c >= 0 && c < 8 && isValid())
      {
         char r = getRow();
         location = r * 8 + (char)c;
      }
      else
         location = -1;
   }
   void set(int r, int c)    { location = 0; setRow(r); setCol(c);                   }
   void setXY(double x, double y) { set(7 - (int)(y / getSquareHeight()),
                                        (int)(x / getSquareWidth ()));               }
   void adjustRow(int dRow)  { if (isValid()) setRow(getRow() + (char)dRow);         }
   void adjustCol(int dCol)  { if (isValid()) setCol(getCol() + (char)dCol);         }
   void setValid()           { if (isInvalid()) location = 0;         }
   void setInvalid()         { location = -1;                         }
   void setSquareWidth (double width ) { if (width  > 0.0) squareWidth  = width;  }
   void setSquareHeight(double height) { if (height > 0.0) squareHeight = height; }

   // Operators
   bool operator <  (const Position & rhs) const { return location < rhs.location;}
   bool operator == (const Position & rhs) const;
   bool operator != (const Position & rhs) const;
   const Position & operator =  (const Position & rhs);
   const Position & operator =  (const char     * rhs);
   const Position & operator =  (const string   & rhs)
   {
      *this = rhs.c_str();
      return *this;
   };
   const Position & operator += (const Delta & rhs)
   {
      adjustRow(rhs.dRow);
      adjustCol(rhs.dCol);

      return *this;
   }
   Position operator + (const Delta & rhs) const
   {
      Position pos(*this);
      pos.adjustRow(rhs.dRow);
      pos.adjustCol(rhs.dCol);

      return pos;
   }

private:
   char location;
   static double squareWidth;
   static double squareHeight;
};


ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in,  Position & pos);
      
