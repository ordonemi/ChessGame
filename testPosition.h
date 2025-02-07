/***********************************************************************
 * Header File:
 *    Position Test : Unit tests for Position
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The unit tests for Position
 ************************************************************************/

#pragma once


/***************************************************
 * POSITION TEST
 * Test the Position class
 ***************************************************/
class PositionTest
{
public:
   void run()
   {
      // get
      getRow_zero();
      getCol_zero();
      isValid_zero();
      isInvalid_zero();
      getRow_middle();
      getCol_middle();
      isValid_middle();
      isInvalid_middle();
      getRow_end();
      getCol_end();
      isValid_end();
      isInvalid_end();
      getRow_invalid();
      getCol_invalid();
      isValid_invalid();
      isInvalid_invalid();
      getRow_wacky();
      getCol_wacky();
      isValid_wacky();
      isInvalid_wacky();

      // set
      set_col();
      set_row();
      set_both();
      set_text();
      set_string();
      set_copy();
         
      // adjust
      adjust_addColumn();
      adjust_addRow();
      adjust_offRight();
      adjust_offTop();
      adjust_offLeft();
      adjust_offBottom();
      adjust_invalid();
   }
private:
   void getRow_zero();
   void getCol_zero();
   void isValid_zero();
   void isInvalid_zero();
   void getRow_middle();
   void getCol_middle();
   void isValid_middle();
   void isInvalid_middle();
   void getRow_end();
   void getCol_end();
   void isValid_end();
   void isInvalid_end();
   void getRow_invalid();
   void getCol_invalid();
   void isValid_invalid();
   void isInvalid_invalid();
   void getRow_wacky();
   void getCol_wacky();
   void isValid_wacky();
   void isInvalid_wacky();

   void set_col();
   void set_row();
   void set_both();
   void set_text();
   void set_string();
   void set_copy();

   void adjust_addColumn();
   void adjust_addRow();
   void adjust_offRight();
   void adjust_offTop();
   void adjust_offLeft();
   void adjust_offBottom();
   void adjust_invalid();
};
