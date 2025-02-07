/***********************************************************************
 * Source File:
 *    Position Test : Unit tests for Position
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The unit tests for Position
 ************************************************************************/


#include "testPosition.h" // for POSITION_TEST
#include "position.h"     // for POSITION
#include <cassert>        // for ASSERT


/*************************************
 * GET  Zero
 * Default position: slot zero at a1
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1  (0) 1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::getRow_zero()
{
   // SETUP
   Position pos;
   pos.location = 0;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assert(row == 0);
   assert(pos.location == 0);

}  // TEARDOWN
void PositionTest::getCol_zero()
{
   // SETUP
   Position pos;
   pos.location = 0;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assert(col == 0);
   assert(pos.location == 0);

}  // TEARDOWN
void PositionTest::isValid_zero()
{
   // SETUP
   Position pos;
   pos.location = 0;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assert(f == true);
   assert(pos.location == 0);

}  // TEARDOWN
void PositionTest::isInvalid_zero()
{
   // SETUP
   Position pos;
   pos.location = 0;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assert(f == false);
   assert(pos.location == 0);

}  // TEARDOWN


/*************************************
 * GET  Middle
 * Default position: slot in the middle at b5
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32(33)34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::getRow_middle()
{
   // SETUP
   Position pos;
   pos.location = 33;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assert(row == 4);
   assert(pos.location == 33);

}  // TEARDOWN
void PositionTest::getCol_middle()
{
   // SETUP
   Position pos;
   pos.location = 33;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assert(col == 1);
   assert(pos.location == 33);

}  // TEARDOWN
void PositionTest::isValid_middle()
{
   // SETUP
   Position pos;
   pos.location = 33;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assert(f == true);
   assert(pos.location == 33);

}  // TEARDOWN
void PositionTest::isInvalid_middle()
{
   // SETUP
   Position pos;
   pos.location = 33;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assert(f == false);
   assert(pos.location == 33);

}  // TEARDOWN
/*************************************
 * GET TEST End
 * End position: slot in the end at h8
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62(63)  8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::getRow_end()
{
   // SETUP
   Position pos;
   pos.location = 63;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assert(row == 7);
   assert(pos.location == 63);

}  // TEARDOWN
void PositionTest::getCol_end()
{
   // SETUP
   Position pos;
   pos.location = 63;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assert(col == 7);
   assert(pos.location == 63);

}  // TEARDOWN
void PositionTest::isValid_end()
{
   // SETUP
   Position pos;
   pos.location = 63;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assert(f == true);
   assert(pos.location == 63);

}  // TEARDOWN
void PositionTest::isInvalid_end()
{
   // SETUP
   Position pos;
   pos.location = 63;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assert(f == false);
   assert(pos.location == 63);

}  // TEARDOWN

/*************************************
 * GET TEST Invalid
 * Default invalid position: -1
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                        ()  |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::getRow_invalid()
{
   // SETUP
   Position pos;
   pos.location = -1;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assert(row == 0);
   assert(pos.location == -1);

}  // TEARDOWN
void PositionTest::getCol_invalid()
{
   // SETUP
   Position pos;
   pos.location = -1;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assert(col == 0);
   assert(pos.location == -1);

}  // TEARDOWN
void PositionTest::isValid_invalid()
{
   // SETUP
   Position pos;
   pos.location = -1;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assert(f == false);
   assert(pos.location == -1);

}  // TEARDOWN
void PositionTest::isInvalid_invalid()
{
   // SETUP
   Position pos;
   pos.location = -1;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assert(f == true);
   assert(pos.location == -1);

}  // TEARDOWN

/*************************************
 * GET TEST Wacky
 * An invalid position that is not what was expected: -50
 **************************************/
void PositionTest::getRow_wacky()
{
   // SETUP
   Position pos;
   pos.location = -50;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assert(row == 0);
   assert(pos.location == -50);

}  // TEARDOWN
void PositionTest::getCol_wacky()
{
   // SETUP
   Position pos;
   pos.location = -50;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assert(col == 0);
   assert(pos.location == -50);

}  // TEARDOWN
void PositionTest::isValid_wacky()
{
   // SETUP
   Position pos;
   pos.location = -50;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assert(f == false);
   assert(pos.location == -50);

}  // TEARDOWN
void PositionTest::isInvalid_wacky()
{
   // SETUP
   Position pos;
   pos.location = -50;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assert(f == true);
   assert(pos.location == -50);

}  // TEARDOWN

/*************************************
 * SET TEST Col
 * Set to f1 using setCol
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4 (5) 6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::set_col()
{
   // SETUP
   Position pos;
   pos.location = 0;

   // EXERCISE
   pos.setCol(5);

   // VERIFY
   assert(pos.location == 5);

   // TEARDOWN
}

/*************************************
 * SET TEST Row
 * Set to a6 user setRow
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6 (40)41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::set_row()
{
   // SETUP
   Position pos;
   pos.location = 0;

   // EXERCISE
   pos.setRow(5);

   // VERIFY
   assert(pos.location == 40);

   // TEARDOWN
}

/*************************************
 * SET TEST Both
 * Set to h5
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38(39)  5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::set_both()
{
   // SETUP
   Position pos;

   // EXERCISE
   pos.set(4 /*row*/, 7 /*col*/);

   // VERIFY
   assert(pos.location == 39);

   // TEARDOWN
}


/*************************************
 * SET TEST Text
 * Set to "c6" 
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41(42)43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::set_text()
{
   // SETUP
   Position pos;

   // EXERCISE
   pos = "c6";

   // VERIFY
   assert(pos.location == 42);

   // TEARDOWN
}

/*************************************
 * SET TEST String
 * Set to string("c6")
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41(42)43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::set_string()
{
   // SETUP
   Position pos;

   // EXERCISE
   pos = string("c6");

   // VERIFY
   assert(pos.location == 42);

   // TEARDOWN
}

/*************************************
 * SET TEST Copy
 * Set to Position("c6")
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41(42)43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::set_copy()
{
   // SETUP
   Position pos;
   Position posRHS;
   posRHS.location = 42;

   // EXERCISE
   pos = posRHS;

   // VERIFY
   assert(pos.location == 42);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST AddColumn
 * add one column to the middle
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21(22)23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::adjust_addColumn()
{
   // SETUP
   Position pos;
   pos.location = 22;

   // EXERCISE
   pos += ADD_C;

   // VERIFY
   assert(pos.location == 23);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST AddRow
 * add one row to the middle
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21(22)23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::adjust_addRow()
{
   // SETUP
   Position pos;
   pos.location = 22;

   // EXERCISE
   pos += ADD_R;

   // VERIFY
   assert(pos.location == 30);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffRight
 * go of the end to the right
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30(31)  4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::adjust_offRight()
{
   // SETUP
   Position pos;
   pos.location = 31;

   // EXERCISE
   pos += ADD_C;

   // VERIFY
   assert(pos.location == -1);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffTop
 * go of the end to the top
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58(59)60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21(22)23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::adjust_offTop()
{
   // SETUP
   Position pos;
   pos.location = 59;

   // EXERCISE
   pos += ADD_R;

   // VERIFY
   assert(pos.location == -1);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffLeft
 * go off the end to the right
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5 (32)33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::adjust_offLeft()
{
   // SETUP
   Position pos;
   pos.location = 32;

   // EXERCISE
   pos += SUB_C;

   // VERIFY
   assert(pos.location == -1);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffBottom
 * go off the end to the bottom
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3 (4) 5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::adjust_offBottom()
{
   // SETUP
   Position pos;
   pos.location = 4;

   // EXERCISE
   pos += SUB_R;

   // VERIFY
   assert(pos.location == -1);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST Invalid
 * Start off invalid
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                       ( )  |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void PositionTest::adjust_invalid()
{
   // SETUP
   Position pos;
   pos.location = -1;

   // EXERCISE
   pos += ADD_R;

   // VERIFY
   assert(pos.location == -1);

   // TEARDOWN
}

