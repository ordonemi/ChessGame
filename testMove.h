/***********************************************************************
 * Header File:
 *    TEST MOVE : test the Move class
 * Author:
 *    Br. Helfrich
 ************************************************************************/


#pragma once

 /***************************************************
  * MOVE TEST
  * Test the Position class
  ***************************************************/
class MoveTest
{
public:
   void run() const
   {
      // Constructor
      constructor_default();

      // Assign
      read_simple();
      read_capture();
      read_enpassant();
      read_castleKing();
      read_castleQueen();
      constructString_simple();
      assign_simple();

      // Get Text
      getText_simple();
      getText_capture();
      getText_enpassant();
      getText_castleKing();
      getText_castleQueen();

      // Letter from Piece Type
      letterFromPieceType_space();
      letterFromPieceType_pawn();
      letterFromPieceType_bishop();
      letterFromPieceType_knight();
      letterFromPieceType_rook();
      letterFromPieceType_queen();
      letterFromPieceType_king();

      // Piece Type from Letter
      pieceTypeFromLetter_pawn();
      pieceTypeFromLetter_knight();
      pieceTypeFromLetter_bishop();
      pieceTypeFromLetter_rook();
      pieceTypeFromLetter_king();
      pieceTypeFromLetter_queen();

   }
private:

   void constructor_default() const;

   void read_simple() const;
   void read_capture() const;
   void read_enpassant() const;
   void read_castleKing() const;
   void read_castleQueen() const;

   void constructString_simple() const;
   void assign_simple() const;

   void getText_simple() const;
   void getText_capture() const;
   void getText_enpassant() const;
   void getText_castleKing() const;
   void getText_castleQueen() const;


   void letterFromPieceType_space() const;
   void letterFromPieceType_pawn() const;
   void letterFromPieceType_bishop() const;
   void letterFromPieceType_knight() const;
   void letterFromPieceType_rook() const;
   void letterFromPieceType_queen() const;
   void letterFromPieceType_king() const;

   void pieceTypeFromLetter_pawn() const;
   void pieceTypeFromLetter_knight() const;
   void pieceTypeFromLetter_bishop() const;
   void pieceTypeFromLetter_rook() const;
   void pieceTypeFromLetter_king() const;
   void pieceTypeFromLetter_queen() const;

};