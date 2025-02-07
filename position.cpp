/***********************************************************************
 * Source File:
 *    Position : Location on the chess board
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

/***************************************************
 * POSITION : COPY CONSTRUCTOR
 ***************************************************/
Position::Position(const Position & rhs) : location(0)
{
   location = rhs.location;
}

/***********************************************
 * POSITION : INEQUALITY
 **********************************************/
bool Position::operator != (const Position & rhs) const
{
   if (isInvalid())
      return rhs.isValid();
   else
      return rhs.location != location;
}

/***********************************************
 * POSITION : EQUALITY
 **********************************************/
bool Position::operator == (const Position & rhs) const
{
   // all invalid positions are the same
   if (isInvalid())
      return rhs.isInvalid();
   else
      return rhs.location == location;
}

/**********************************************
 * POSITION : ASSIGNMENT
 **********************************************/
const Position & Position::operator = (const Position & rhs)
{
   location = rhs.location;

   return *this;
}


/**********************************************
 * POSITION : ASSIGNMENT
 **********************************************/
const Position & Position::operator = (const char * rhs)
{
   if (rhs == NULL)
      location = -1;

   else if (rhs[0] < 'a' || rhs[0] > 'h' ||
       rhs[1] < '1' || rhs[1] > '8')
      location = -1;

   else
      set(rhs[1] - '1', rhs[0] - 'a');

   return *this;
}


/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
    if (rhs.isValid())
        out << (char)(rhs.getCol() + 'a')
        << (char)(rhs.getRow() + '1');
    else
        out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
   char text[3] = {};
   in >> text[0] >> text[1];
   if (in.fail())
   {
      in.clear();
      in.ignore();
      throw string("Error reading coordinates");
   }
   else
   {
      rhs = text;
   }

   return in;   
}

